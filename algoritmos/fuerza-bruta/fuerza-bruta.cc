#include "fuerza-bruta.h"
#include <numeric>
#include <climits>
#include <algorithm>

std::pair<std::vector<std::string>, int> FuerzaBruta::resolver(const std::vector<std::vector<int>>& distancias, const std::vector<std::string>& ciudades) {
    std::vector<int> permutacion(ciudades.size());
    std::iota(permutacion.begin(), permutacion.end(), 0);

    int mejor_coste = INT_MAX;
    std::vector<std::string> mejor_ruta;

    do {
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
    } while (std::next_permutation(permutacion.begin(), permutacion.end()));
    return {mejor_ruta, mejor_coste};
}
