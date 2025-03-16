#include "experimento-tsp.h"
#include <iostream>
#include <chrono>
#include <vector>

/* 
 * Ejecuta los algoritmos para resolver el problema del TSP.
 * @param ruta Ruta del archivo con la instancia del problema.
 */
void ExperimentoTSP::Ejecutar(const std::string& ruta) {
    std::vector<std::string> ciudades;
    std::vector<std::vector<int>> distancias;

    if (!InstanciaTSP::LeerInstancia(ruta, ciudades, distancias)) {
        std::cerr << "Error al leer instancia.\n";
        return;
    }
    
    Voraz voraz;
    Algoritmo* algoritmo = new FuerzaBruta();
    auto start = std::chrono::high_resolution_clock::now();
    auto resultado = algoritmo->resolver(distancias, ciudades);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Fuerza Bruta: " << resultado.second << " en " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "us\n";
    delete algoritmo;

    algoritmo = new Voraz();
    start = std::chrono::high_resolution_clock::now();
    resultado = algoritmo->resolver(distancias, ciudades);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Voraz: " << resultado.second << " en " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "us\n";
    delete algoritmo;

    algoritmo = new ProgramacionDinamica();
    start = std::chrono::high_resolution_clock::now();
    resultado = algoritmo->resolver(distancias, ciudades);
    end = std::chrono::high_resolution_clock::now();
    delete algoritmo;
    std::cout << "Programación Dinámica: " << resultado.second << " en " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "us\n";
}
