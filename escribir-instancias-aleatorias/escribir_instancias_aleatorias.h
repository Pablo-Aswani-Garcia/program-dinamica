#ifndef ESCRIBIR_INSTANCIAS_ALEATORIAS_H
#define ESCRIBIR_INSTANCIAS_ALEATORIAS_H

#include <string>

/*
 * Clase que permite generar instancias aleatorias del problema del TSP.
 */
class EscribirInstanciasAleatorias {
public:
    static void GenerarInstancias(const std::string& archivoBase, int numCiudades, int numInstancias);
};

#endif // WRITE_RANDOMIZED_INSTANCES_H