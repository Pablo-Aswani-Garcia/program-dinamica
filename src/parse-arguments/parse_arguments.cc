/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 * Práctica 4 Experimentación con Programación Dinámica
 *
 * @author Pablo Aswani García
 * @since Fri 14 Mar 2025
 * @brief Declaración de la clase ParseArguments
 * @see
 */
#include "parse_arguments.h"
#include <iostream>

/**
 * Analiza los argumentos del programa.
 * @param argc Número de argumentos.
 * @param argv Argumentos del programa.
 * @return std::string Ruta de la carpeta con las instancias.
 */
std::string ParseArguments::parse(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Uso: ./tsp_solver <ruta_carpeta_instancias>\n";
        exit(1);
    }
    return argv[1];
}