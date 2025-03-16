#include "experimento-tsp.h"
#include <iostream>
#include <chrono>
#include <vector>


void ExperimentoTSP::ejecutar(const std::string& ruta) {
    std::vector<std::string> ciudades;
    std::vector<std::vector<int>> matriz;

    if (!InstanciaTSP::leerInstancia(ruta, ciudades, matriz)) {
        std::cerr << "Error al leer instancia.\n";
        return;
    }

    FuerzaBruta fb;
    Voraz voraz;
    ProgramacionDinamica pd;

    auto start = std::chrono::high_resolution_clock::now();
    auto resultado = fb.resolver(matriz, ciudades);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Fuerza Bruta: " << resultado.second << " en " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "us\n";

    start = std::chrono::high_resolution_clock::now();
    resultado = voraz.resolver(matriz, ciudades);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Voraz: " << resultado.second << " en " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "us\n";

    start = std::chrono::high_resolution_clock::now();
    resultado = pd.resolver(matriz, ciudades);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Programación Dinámica: " << resultado.second << " en " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "us\n";
}
