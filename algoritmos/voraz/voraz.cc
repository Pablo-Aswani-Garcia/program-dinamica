#include "voraz.h"
#include <limits>
#include <unordered_set>

std::pair<std::vector<std::string>, int> Voraz::resolver(const std::vector<std::vector<int>>& matriz, const std::vector<std::string>& ciudades) {
    int n = ciudades.size();
    std::vector<std::string> ruta;
    std::unordered_set<int> visitados;
    int actual = 0;
    int costo = 0;

    ruta.push_back(ciudades[actual]);
    visitados.insert(actual);

    while (ruta.size() < n) {
        int mejorCosto = std::numeric_limits<int>::max();
        int siguiente = -1;

        for (int i = 0; i < n; ++i) {
            if (visitados.find(i) == visitados.end() && matriz[actual][i] < mejorCosto) {
                mejorCosto = matriz[actual][i];
                siguiente = i;
            }
        }

        if (siguiente == -1) break;
        costo += mejorCosto;
        actual = siguiente;
        ruta.push_back(ciudades[actual]);
        visitados.insert(actual);
    }

    costo += matriz[actual][0];
    ruta.push_back(ciudades[0]);

    return {ruta, costo};
}