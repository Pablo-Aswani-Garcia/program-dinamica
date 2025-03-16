#include "programacion-dinamica.h"
#include <limits>

int ProgramacionDinamica::tsp(int pos, int mask, const std::vector<std::vector<int>>& matriz) {
    if (mask == (1 << n) - 1) return matriz[pos][0]; // Volver al inicio

    if (memo[pos].count(mask)) return memo[pos][mask];

    int mejor = std::numeric_limits<int>::max();
    for (int ciudad = 0; ciudad < n; ciudad++) {
        if (!(mask & (1 << ciudad))) { // Si no ha sido visitada
            int costo = matriz[pos][ciudad] + tsp(ciudad, mask | (1 << ciudad), matriz);
            if (costo < mejor) {
                mejor = costo;
            }
        }
    }
    return memo[pos][mask] = mejor;
}

std::pair<std::vector<std::string>, int> ProgramacionDinamica::resolver(const std::vector<std::vector<int>>& matriz, const std::vector<std::string>& ciudades) {
    n = ciudades.size();
    memo.clear();

    int mejorCosto = tsp(0, 1, matriz);
    return {ciudades, mejorCosto};
}
