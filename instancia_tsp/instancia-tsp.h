#ifndef INSTANCIA_TSP_H
#define INSTANCIA_TSP_H

#include <vector>
#include <string>

/*
 * Clase que permite leer una instancia del problema del TSP desde un archivo.
 */
class InstanciaTSP {
public:
    static bool LeerInstancia(const std::string& ruta, std::vector<std::string>& ciudades, std::vector<std::vector<int>>& distancias);
};

#endif
