#ifndef WRITE_RANDOMIZED_INSTANCES_H
#define WRITE_RANDOMIZED_INSTANCES_H

#include <string>

class WriteRandomInstances {
public:
    static void generarInstancia(const std::string& archivo, int numCiudades);
    static void generarInstancias(const std::string& archivoBase, int numCiudades, int numInstancias);
};

#endif // WRITE_RANDOMIZED_INSTANCES_H