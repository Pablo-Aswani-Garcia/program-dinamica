#include "parse-arguments/parse_arguments.h"
#include "experimento_tsp/experimento-tsp.h" 
#include "write_randomized_instances/write-randomized-instances.h" 
#include <iostream>
#include <filesystem>

int main(int argc, char* argv[]) {
    std::string directorio = ParseArguments::parse(argc, argv);
    std::string instancia_test = "../tmp/instancia";
    WriteRandomInstances::GenerarInstancias(instancia_test, 10, 20);

    for (const auto& fichero : std::filesystem::directory_iterator(directorio)) {
        std::cout << "Ejecutando instancia: " << fichero.path().string() << "\n";
        ExperimentoTSP::Ejecutar(fichero.path().string());
    }
    return 0;
}