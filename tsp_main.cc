#include "parse-arguments/parse_arguments.h"
#include "experimento_tsp/experimento-tsp.h" 
#include "write_randomized_instances/write-randomized-instances.h" 
#include <iostream>
#include <filesystem>

int main(int argc, char* argv[]) {
    std::string directorio = ParseArguments::parse(argc, argv);
    // Generar instancia aleatoria de prueba
    std::string instanciaTest = "../tmp/instancia";
    WriteRandomInstances::generarInstancias(instanciaTest, 10, 20);

    for (const auto& entry : std::filesystem::directory_iterator(directorio)) {
        std::cout << "Ejecutando instancia: " << entry.path().string() << "\n";
        ExperimentoTSP::ejecutar(entry.path().string());
    }
    return 0;
}