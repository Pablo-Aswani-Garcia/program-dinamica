/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 * Práctica 4 Experimentación con Programación Dinámica
 *
 * @author Pablo Aswani García
 * @since Fri 14 Mar 2025
 * @brief Definición de la clase VorazMedio
 * @see
 */

#include "voraz-medio.h"

#include <algorithm>
#include <climits>


/**
 * @brief Resuelve el problema del TSP mediante un algoritmo vorazMedio.
 * @param transiciones matriz de distancias entre ciudades.
 * @param ciudades vector con los nombres de las ciudades.
 * @return ruta y coste de la solución encontrada.
 */
std::pair<std::vector<std::string>, int> VorazMedio::resolver(
    const std::vector<std::vector<int>>& transiciones,
    const std::vector<std::string>& ciudades) {
  int numero_ciudades = ciudades.size();
  std::vector<std::string> ruta;
  std::vector<int> visitados;
  int actual = 0;
  int costo = 0;

  ruta.push_back(ciudades[actual]);
  visitados.push_back(actual);
  while (ruta.size() < int(numero_ciudades)) {
    std::vector<std::pair<int, int>> coste_destino;
    int coste_medio = 0;

    int siguiente = -1;
    for (int i = 0; i < int(numero_ciudades); ++i) {
      if (std::find(visitados.begin(), visitados.end(), i) == visitados.end()) {
        coste_destino.push_back({transiciones[actual][i], i});
      }
    }
    std::sort(coste_destino.begin(), coste_destino.end());
    siguiente = coste_destino[coste_destino.size() / 2].second;
    coste_medio = coste_destino[coste_destino.size() / 2].first;
    if (siguiente == -1)
      break;
    costo += coste_medio;
    actual = siguiente;
    ruta.push_back(ciudades[actual]);
    visitados.push_back(actual);
  }

  costo += transiciones[actual][0];
  ruta.push_back(ciudades[0]);
  return {ruta, costo};
}