/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 * Práctica 4 Experimentación con Programación Dinámica
 *
 * @author Pablo Aswani García
 * @since Fri 14 Mar 2025
 * @brief Definición de la clase FuerzaBruta
 * @see
 */

#include "fuerza-bruta.h"
#include <numeric>
#include <climits>
#include <algorithm>
#include <chrono>

/**
 * Implementación del algoritmo de fuerza bruta para resolver el problema del TSP.
 * @param distancias Matriz de distancias entre ciudades.
 * @param ciudades Vector con los nombres de las ciudades.
 * @return std::pair<std::vector<std::string>, int> Un par con la mejor ruta y su coste.
 **/
std::pair<std::vector<std::string>, int> FuerzaBruta::resolver(const std::vector<std::vector<int>>& distancias, const std::vector<std::string>& ciudades) {
    std::vector<int> permutacion(ciudades.size());
    std::iota(permutacion.begin(), permutacion.end(), 0);
    this->tiempo_limite_ *= 1000;

    int mejor_coste = INT_MAX;
    std::vector<std::string> mejor_ruta;
    long cumulative_time = 0;
    do {
      std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
      int costo = 0;
      for (int i = 0; i < int(permutacion.size()) - 1; i++) {
        costo += distancias[permutacion[i]][permutacion[i + 1]];
      }
      costo += distancias[permutacion.back()][permutacion[0]];  
      if (costo < mejor_coste) {
        mejor_coste = costo;
        mejor_ruta.clear();
        for (int i : permutacion) {
            mejor_ruta.push_back(ciudades[i]);
        }
        mejor_ruta.push_back(ciudades[permutacion[0]]);
      }
      std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
      cumulative_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
      if (cumulative_time > tiempo_limite_) {
        break;
      }
    } while (std::next_permutation(permutacion.begin(), permutacion.end()));
    return {mejor_ruta, mejor_coste};
}
