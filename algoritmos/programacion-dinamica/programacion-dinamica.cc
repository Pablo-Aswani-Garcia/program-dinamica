#include "programacion-dinamica.h"
#include <limits>
#include <climits>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <chrono>

/* 
 * Implementación del algoritmo de programación dinámica para resolver el problema del TSP.
 * @param transiciones Matriz de distancias entre ciudades.
 * @param ciudades Vector con los nombres de las ciudades.
 * @return std::pair<std::vector<std::string>, int> Un par con la mejor ruta y su coste.
 **/
std::pair<std::vector<std::string>, int> ProgramacionDinamica::resolver(
  const std::vector<std::vector<int>>& transiciones, 
  const std::vector<std::string>& ciudades) {
  
  int num_ciudades = ciudades.size();
  int VISITED_ALL = (1 << num_ciudades) - 1;
  
  // Tabla de memoización para almacenar costos mínimos
  std::vector<std::vector<int>> tabla_memoizacion(1 << num_ciudades, std::vector<int>(num_ciudades, INT_MAX));
  
  tabla_memoizacion[1][0] = 0; // Estado inicial: solo la ciudad 0 visitada, costo 0
  
  // Llenado de la tabla de programación dinámica
  // la variable mask representa cada una de las ciudades visitadas
  // de la siguiente manera:
  // mask
  // 0001 -> Ciudad 1
  // 0011 -> Ciudad 1 y 2
  // 0101 -> Ciudad 1 y 3
  for (int mask = 1; mask < (1 << num_ciudades); ++mask) {
    for (int ciudad = 0; ciudad < num_ciudades; ++ciudad) {
      if (mask & (1 << ciudad)) { // Si la ciudad ya fue visitada
        for (int ciudad_destino = 0; ciudad_destino < num_ciudades; ++ciudad_destino) {
          if (!(mask & (1 << ciudad_destino))) { // Si la ciudad no ha sido visitada
            int nueva_mask = mask | (1 << ciudad_destino);
            if (tabla_memoizacion[mask][ciudad] != INT_MAX) { // Evitar suma con INT_MAX
              tabla_memoizacion[nueva_mask][ciudad_destino] = std::min(
                  tabla_memoizacion[nueva_mask][ciudad_destino], 
                  tabla_memoizacion[mask][ciudad] + transiciones[ciudad][ciudad_destino]);
            }
          }
        }
      }
    }
  }
  
  // Cálculo del costo mínimo regresando a la ciudad inicial
  int costo_minimo = INT_MAX;
  int ultima_ciudad = -1;
  
  for (int i = 1; i < num_ciudades; ++i) {
    if (tabla_memoizacion[VISITED_ALL][i] != INT_MAX) { // Evita sumar INT_MAX
      int costo_actual = tabla_memoizacion[VISITED_ALL][i] + transiciones[i][0];
      if (costo_actual < costo_minimo) {
        costo_minimo = costo_actual;
        ultima_ciudad = i;
      }
    }
  }
  
  
  // Reconstrucción de la mejor ruta
  std::vector<std::string> ruta(num_ciudades + 1);
  int mask = VISITED_ALL;
  int pos = ultima_ciudad;
  
  for (int i = num_ciudades - 1; i >= 0; --i) {
    ruta[i] = ciudades[pos];
    int next_pos = -1;
    
    for (int j = 0; j < num_ciudades; ++j) {
      if ((mask & (1 << j)) && tabla_memoizacion[mask][pos] != INT_MAX &&
          tabla_memoizacion[mask][pos] == tabla_memoizacion[mask ^ (1 << pos)][j] + transiciones[j][pos]) {
        next_pos = j;
        break;
      }
    }
  
    mask ^= (1 << pos);
    pos = next_pos;
  }
  
  ruta[num_ciudades] = ciudades[0]; // Volver al inicio
  
  return {ruta, costo_minimo};
}
