/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 * Práctica 4 Experimentación con Programación Dinámica
 *
 * @author Pablo Aswani García
 * @since Fri 14 Mar 2025
 * @brief Programa principal para ejecutar el experimento del TSP
 * @see
 */

#include <filesystem>
#include <iostream>

#include "escribir-instancias-aleatorias/escribir_instancias_aleatorias.h"
#include "experimento_tsp/experimento-tsp.h"
#include "parse-arguments/parse_arguments.h"

int main(int argc, char* argv[]) {
  std::string directorio = ParseArguments::parse(argc, argv);
  directorio = "./" + directorio;
  
  const long TIEMPO_SEGUNDOS = 1;
  // a partir de 23 ciudades el tiempo de ejecución es muy alto
  const int NUM_CIUDADES = 12;
  EscribirInstanciasAleatorias::GenerarInstancias(directorio, NUM_CIUDADES, 20);

  for (const auto& fichero : std::filesystem::directory_iterator(directorio)) {
    std::cout << "Ejecutando instancia: " << fichero.path().string() << "\n";
    ExperimentoTSP::Ejecutar(fichero.path().string(), TIEMPO_SEGUNDOS);
  }
  return 0;
}