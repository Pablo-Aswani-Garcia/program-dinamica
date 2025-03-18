/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 * Práctica 4 Experimentación con Programación Dinámica
 *
 * @author Pablo Aswani García
 * @since Fri 14 Mar 2025
 * @brief Definición de la clase Voraz
 * @see
 */

#include "voraz.h"
#include <algorithm>
#include <climits>
#include <algorithm>

/**
 * @brief Resuelve el problema del TSP mediante un algoritmo voraz.
 * @param transiciones matriz de distancias entre ciudades.
 * @param ciudades vector con los nombres de las ciudades.
 * @return ruta y coste de la solución encontrada.
 */
std::pair<std::vector<std::string>, int> Voraz::resolver(const std::vector<std::vector<int>>& transiciones, const std::vector<std::string>& ciudades) {
  int numero_ciudades = ciudades.size();
  std::vector<std::string> ruta;
  std::vector<int> visitados;
  int actual = 0;
  int costo = 0;

  ruta.push_back(ciudades[actual]);
  visitados.push_back(actual);

  while (ruta.size() < int(numero_ciudades)) {
    int mejor_coste = INT_MAX;
    int siguiente = -1;
    for (int i = 0; i < int(numero_ciudades); ++i) {
      if (std::find(visitados.begin(), visitados.end(), i) 
          == visitados.end() && transiciones[actual][i] < mejor_coste) {
        mejor_coste = transiciones[actual][i];
        siguiente = i;
      }
    }
    if (siguiente == -1) break;
    costo += mejor_coste;
    actual = siguiente;
    ruta.push_back(ciudades[actual]);
    visitados.push_back(actual);
  }

  costo += transiciones[actual][0];
  ruta.push_back(ciudades[0]);  
  return {ruta, costo};
}