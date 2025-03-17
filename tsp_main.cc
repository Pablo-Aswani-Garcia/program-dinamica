#include "parse-arguments/parse_arguments.h"
#include "experimento_tsp/experimento-tsp.h" 
#include "escribir-instancias-aleatorias/escribir_instancias_aleatorias.h"
#include <iostream>
#include <filesystem>

int main(int argc, char* argv[]) {
    std::string directorio = ParseArguments::parse(argc, argv);
    std::string instancia_test = "../tmp/instancia";
    const long TIEMPO_SEGUNDOS = 1;
    // a partir de 23 ciudades el tiempo de ejecución es muy alto
    const int NUM_CIUDADES = 12;
    EscribirInstanciasAleatorias::GenerarInstancias(instancia_test, NUM_CIUDADES, 20);

    for (const auto& fichero : std::filesystem::directory_iterator(directorio)) {
        std::cout << "Ejecutando instancia: " << fichero.path().string() << "\n";
        ExperimentoTSP::Ejecutar(fichero.path().string(), TIEMPO_SEGUNDOS);
    }
    return 0;
}