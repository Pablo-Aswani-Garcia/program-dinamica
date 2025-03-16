#include "instancia-tsp.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

bool InstanciaTSP::LeerInstancia(const std::string& ruta, std::vector<std::string>& ciudades, std::vector<std::vector<int>>& distancias) {
    std::ifstream file(ruta);
    if (!file) return false;

    int numero_ciudades;
    file >> numero_ciudades;
    ciudades.resize(numero_ciudades);
    distancias.assign(numero_ciudades, std::vector<int>(numero_ciudades, 0));

    std::string primera_ciudad, segunda_ciudad;
    int distancia;
    int ciudadesLeidas = 0;
    while (file >> primera_ciudad >> segunda_ciudad >> distancia) {
        int origen = std::find(ciudades.begin(), ciudades.end(), primera_ciudad) - ciudades.begin();
        int destino = std::find(ciudades.begin(), ciudades.end(), segunda_ciudad) - ciudades.begin();
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
