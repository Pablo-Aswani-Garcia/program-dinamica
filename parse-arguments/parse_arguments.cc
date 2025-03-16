#include "parse_arguments.h"
#include <iostream>

std::string ParseArguments::parse(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Uso: ./tsp_solver <ruta_carpeta_instancias>\n";
        exit(1);
    }
    return argv[1];
}