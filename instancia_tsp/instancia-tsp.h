#ifndef INSTANCIA_TSP_H
#define INSTANCIA_TSP_H

#include <vector>
#include <string>

class InstanciaTSP {
public:
    static bool LeerInstancia(const std::string& ruta, std::vector<std::string>& ciudades, std::vector<std::vector<int>>& distancias);
};

#endif
