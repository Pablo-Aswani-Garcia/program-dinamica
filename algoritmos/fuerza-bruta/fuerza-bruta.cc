#include "fuerza-bruta.h"
#include <numeric>
std::pair<std::vector<std::string>, int> FuerzaBruta::resolver(const std::vector<std::vector<int>>& matriz, const std::vector<std::string>& ciudades) {
    std::vector<int> permutacion(ciudades.size());
    std::iota(permutacion.begin(), permutacion.end(), 0);

    int mejorCosto = INT_MAX;
    std::vector<std::string> mejorRuta;

    do {
        int costo = 0;
        for (size_t i = 0; i < permutacion.size() - 1; ++i) {
            costo += matriz[permutacion[i]][permutacion[i + 1]];
        }
        costo += matriz[permutacion.back()][permutacion[0]];

        if (costo < mejorCosto) {
            mejorCosto = costo;
            mejorRuta.clear();
            for (int i : permutacion) mejorRuta.push_back(ciudades[i]);
            mejorRuta.push_back(ciudades[permutacion[0]]);
        }
    } while (std::next_permutation(permutacion.begin(), permutacion.end()));

    return {mejorRuta, mejorCosto};
}
