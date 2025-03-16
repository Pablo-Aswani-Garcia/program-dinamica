#include "instancia-tsp.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

bool InstanciaTSP::leerInstancia(const std::string& ruta, std::vector<std::string>& ciudades, std::vector<std::vector<int>>& matriz) {
    std::ifstream file(ruta);
    if (!file) return false;

    int n;
    file >> n;
    ciudades.resize(n);
    matriz.assign(n, std::vector<int>(n, 0));

    std::string c1, c2;
    int distancia;
    int ciudadesLeidas = 0;
    while (file >> c1 >> c2 >> distancia) {
        int i = std::find(ciudades.begin(), ciudades.end(), c1) - ciudades.begin();
        int j = std::find(ciudades.begin(), ciudades.end(), c2) - ciudades.begin();
        if (i == n) { 
          ciudades[ciudadesLeidas] = c1;
          i = ciudadesLeidas;
          ciudadesLeidas++;
         
        }
        if (j == n) {
          ciudades[ciudadesLeidas] = c2;
          j = ciudadesLeidas;
          ciudadesLeidas++;
        }
        matriz[i][j] = matriz[j][i] = distancia;
    }

    return true;
}
