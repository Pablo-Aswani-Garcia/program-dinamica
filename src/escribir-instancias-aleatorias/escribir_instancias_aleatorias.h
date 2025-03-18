/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 * Práctica 4 Experimentación con Programación Dinámica
 *
 * @author Pablo Aswani García
 * @since Fri 14 Mar 2025
 * @brief Declaración de la clase EscribirInstanciasAleatorias
 * @see
 */

#ifndef ESCRIBIR_INSTANCIAS_ALEATORIAS_H
#define ESCRIBIR_INSTANCIAS_ALEATORIAS_H

#include <string>

/**
 * @brief Permite generar instancias aleatorias del problema del TSP.
 */
class EscribirInstanciasAleatorias {
public:
    static void GenerarInstancias(const std::string& archivoBase, int numCiudades, int numInstancias);
};

#endif // WRITE_RANDOMIZED_INSTANCES_H