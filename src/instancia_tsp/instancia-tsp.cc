/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 * Práctica 4 Experimentación con Programación Dinámica
 * 
 * @author Pablo Aswani García
 * @since Fri 14 Mar 2025
 * @brief Definición de la clase InstanciaTsp
 * @see
 */

#include "instancia-tsp.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

/**
 * Lee una instancia del problema del TSP desde un archivo.
 * @param ruta Ruta del archivo con la instancia.
 * @param ciudades Vector donde se almacenarán los nombres de las ciudades.
 * @param distancias Matriz de distancias entre ciudades.
 * @return bool True si la lectura fue exitosa, false en caso contrario.
 */
bool InstanciaTSP::LeerInstancia(const std::string& ruta,
                                 std::vector<std::string>& ciudades,
                                 std::vector<std::vector<int>>& distancias) {
  std::ifstream file(ruta);
  if (!file)
    return false;

  int numero_ciudades;
  file >> numero_ciudades;
  ciudades.resize(numero_ciudades);
  distancias.assign(numero_ciudades, std::vector<int>(numero_ciudades, 0));

  std::string primera_ciudad, segunda_ciudad;
  int distancia;
  int ciudadesLeidas = 0;
  while (file >> primera_ciudad >> segunda_ciudad >> distancia) {
    int origen = std::find(ciudades.begin(), ciudades.end(), primera_ciudad) -
                 ciudades.begin();
    int destino = std::find(ciudades.begin(), ciudades.end(), segunda_ciudad) -
                  ciudades.begin();
    if (origen == numero_ciudades) {
      ciudades[ciudadesLeidas] = primera_ciudad;
      origen = ciudadesLeidas;
      ciudadesLeidas++;
    }
    if (destino == numero_ciudades) {
      ciudades[ciudadesLeidas] = segunda_ciudad;
      destino = ciudadesLeidas;
      ciudadesLeidas++;
    }
    distancias[origen][destino] = distancias[destino][origen] = distancia;
  }

  return true;
}
