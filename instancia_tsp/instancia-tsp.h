#ifndef INSTANCIA_TSP_H
#define INSTANCIA_TSP_H

#include <vector>
#include <string>

class InstanciaTSP {
public:
    static bool leerInstancia(const std::string& ruta, std::vector<std::string>& ciudades, std::vector<std::vector<int>>& matriz);
};

#endif
