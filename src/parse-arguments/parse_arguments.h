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

#ifndef PARSE_ARGUMENTS_H_
#define PARSE_ARGUMENTS_H_

#include <string>

/**
 * @brief Analiza los argumentos del programa.
 */
class ParseArguments {
public:
  static std::string parse(int argc, char* argv[]);
};

#endif  // PARSE_ARGUMENTS_H_
