#include "escribir_instancias_aleatorias.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

/*
 * Genera instancias aleatorias del problema del TSP.
 * @param archivo_entrada Nombre base del archivo de salida.
 * @param num_ciudades Número de ciudades de la instancia.
 * @param num_instancias Número de instancias a generar.
 **/
void EscribirInstanciasAleatorias::GenerarInstancias(const std::string& archivo_entrada, int num_ciudades, int num_instancias) {
    for (int i = 0; i < num_instancias; i++) {
        std::string archivo = archivo_entrada + "_" + std::to_string(i + 1) + ".txt";
        std::ofstream file(archivo);
        if (!file) {
            std::cerr << "Error al crear el archivo: " << archivo << "\n";
            continue;
        }

        file << num_ciudades << "\n";
        std::vector<std::string> nombresCiudades;
        for (int i = 0; i < num_ciudades; i++) {
            nombresCiudades.push_back("C" + std::to_string(i + 1));
        }

        srand(time(0) + i); // Ensure different seed for each instance
        for (int j = 0; j < num_ciudades; j++) {
            for (int k = j + 1; k < num_ciudades; k++) {
                int distancia = rand() % 100 + 1;
                file << nombresCiudades[j] << " " << nombresCiudades[k] << " " << distancia << "\n";
            }
        }
        file.close();
        std::cout << "Instancia generada: " << archivo << "\n";
    }
}