/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 * Práctica 4 Experimentación con Programación Dinámica
 *
 * @author Pablo Aswani García
 * @since Fri 14 Mar 2025
 * @brief Definición de la clase ExperimentoTsp
 * @see
 */

#include "experimento-tsp.h"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

/**
 * Ejecuta los algoritmos para resolver el problema del TSP.
 * @param ruta Ruta del archivo con la instancia del problema.
 */
void ExperimentoTSP::Ejecutar(const std::string& ruta,
                              const long& tiempo_segundos) {
  const long SEGUNDOS_A_NANOSEGUNDOS = 1000000;
  const long tiempo_limite =
      tiempo_segundos * SEGUNDOS_A_NANOSEGUNDOS;  // 1 segundos
  std::vector<std::string> ciudades;
  std::vector<std::vector<int>> distancias;

  if (!InstanciaTSP::LeerInstancia(ruta, ciudades, distancias)) {
    std::cerr << "Error al leer instancia.\n";
    return;
  }

  std::cout << "Instancia: " << ruta << "\n";

  // Fuerza Bruta
  Algoritmo* algoritmo = new FuerzaBruta(tiempo_limite);
  auto start = std::chrono::high_resolution_clock::now();
  auto resultado = algoritmo->resolver(distancias, ciudades);
  auto end = std::chrono::high_resolution_clock::now();

  auto duracion =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start)
          .count();
  int valor_fuerza_bruta = resultado.second;
  auto ruta_fuerza_bruta = resultado.first;

  long tiempo_fuerza_bruta = duracion;
  delete algoritmo;

  // Programación Dinámica
  algoritmo = new ProgramacionDinamica(tiempo_limite);
  start = std::chrono::high_resolution_clock::now();
  resultado = algoritmo->resolver(distancias, ciudades);
  end = std::chrono::high_resolution_clock::now();

  duracion = std::chrono::duration_cast<std::chrono::microseconds>(end - start)
                 .count();
  int valor_programacion_dinamica = resultado.second;
  auto ruta_prog_din = resultado.first;
  long tiempo_programacion_dinamica = duracion;
  delete algoritmo;

  // Voraz
  algoritmo = new Voraz(tiempo_limite);
  start = std::chrono::high_resolution_clock::now();
  resultado = algoritmo->resolver(distancias, ciudades);

  end = std::chrono::high_resolution_clock::now();
  duracion = std::chrono::duration_cast<std::chrono::microseconds>(end - start)
                 .count();
  int valor_voraz = resultado.second;
  auto ruta_voraz = resultado.first;
  long tiempo_voraz = duracion;
  delete algoritmo;

  // Voraz medio
  algoritmo = new VorazMedio(tiempo_limite);
  start = std::chrono::high_resolution_clock::now();
  resultado = algoritmo->resolver(distancias, ciudades);
  end = std::chrono::high_resolution_clock::now();
  duracion = std::chrono::duration_cast<std::chrono::microseconds>(end - start)
                 .count();
  int valor_voraz_medio = resultado.second;
  auto ruta_voraz_medio = resultado.first;
  long tiempo_voraz_medio = duracion;
  delete algoritmo;

  std::cout << " | Instancia";
  std::cout << " | Valor Fuerza Bruta";
  std::cout << " | Tiempo Fuerza Bruta (us)";
  std::cout << " | Valor Prog. Dinámica";
  std::cout << " | Tiempo Prog. Dinámica (us)";
  std::cout << " | Valor Voraz";
  std::cout << " | Tiempo Voraz (us)";
  std::cout << " | Valor Voraz Medio (us)";
  std::cout << " | Tiempo Voraz Medio (us)";
  std::cout << "\n";
  std::cout << ruta << " | ";
  std::cout << valor_fuerza_bruta << " | ";

  if (tiempo_fuerza_bruta > tiempo_limite) {
    std::cout << "TIMEOUT | ";
  } else {
    std::cout << tiempo_fuerza_bruta << " | ";
  }
  std::cout << valor_programacion_dinamica << " | ";
  if (tiempo_programacion_dinamica > tiempo_limite) {
    std::cout << "TIMEOUT | ";
  } else {
    std::cout << tiempo_programacion_dinamica << " | ";
  }
  std::cout << valor_voraz << " | ";
  if (tiempo_voraz > tiempo_limite) {
    std::cout << "TIMEOUT\n";
  } else {
    std::cout << tiempo_voraz << "\n";
  }

  std::cout << valor_voraz_medio << " | ";
  if (tiempo_voraz_medio > tiempo_limite) {
    std::cout << "TIMEOUT\n";
  } else {
    std::cout << tiempo_voraz_medio << "\n";
  }
  std::cout << "Ruta Programación Dinámica: ";
  for (const auto& ciudad : ruta_prog_din) {
    std::cout << ciudad << " ";
  }
  std::cout << "\n";
  std::cout << "Ruta Voraz: ";
  for (const auto& ciudad : ruta_voraz) {
    std::cout << ciudad << " ";
  }
  std::cout << "\n";
  std::cout << "Ruta Voraz Medio: ";
  for (const auto& ciudad : ruta_voraz_medio) {
    std::cout << ciudad << " ";
  }
  std::cout << "\n";
  std::cout << "Ruta Fuerza Bruta: ";
  for (const auto& ciudad : ruta_fuerza_bruta) {
    std::cout << ciudad << " ";
  }
  std::cout << "\n";

}