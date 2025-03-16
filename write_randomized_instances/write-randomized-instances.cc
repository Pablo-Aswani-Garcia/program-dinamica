#include "write-randomized-instances.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

void WriteRandomInstances::generarInstancias(const std::string& archivoBase, int numCiudades, int numInstancias) {
    for (int k = 0; k < numInstancias; k++) {
        std::string archivo = archivoBase + "_" + std::to_string(k + 1) + ".txt";
        std::ofstream file(archivo);
        if (!file) {
            std::cerr << "Error al crear el archivo: " << archivo << "\n";
            continue;
        }

        file << numCiudades << "\n";
        std::vector<std::string> nombresCiudades;
        for (int i = 0; i < numCiudades; i++) {
            nombresCiudades.push_back("C" + std::to_string(i + 1));
        }

        srand(time(0) + k); // Ensure different seed for each instance
        for (int i = 0; i < numCiudades; i++) {
            for (int j = i + 1; j < numCiudades; j++) {
                int distancia = rand() % 100 + 1;
                file << nombresCiudades[i] << " " << nombresCiudades[j] << " " << distancia << "\n";
            }
        }
        file.close();
        std::cout << "Instancia generada: " << archivo << "\n";
    }
}