/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 * Práctica 4 Experimentación con Programación Dinámica
 *
 * @author Pablo Aswani García
 * @since Fri 14 Mar 2025 
 * @brief Declaración de la clase ExperimentoTsp
 * @see 
 */

#ifndef EXPERIMENTOTSP_H
#define EXPERIMENTOTSP_H

#include "../algoritmos/algoritmo.h"
#include "../instancia_tsp/instancia-tsp.h"
#include "../algoritmos/fuerza-bruta/fuerza-bruta.h"
#include "../algoritmos/voraz/voraz.h"
#include "../algoritmos/programacion-dinamica/programacion-dinamica.h"
#include <chrono>
#include <iostream>
/**
 * @brief Clase que permite ejecutar un experimento con el problema del TSP.
 */
class ExperimentoTSP {
public:
    static void Ejecutar(const std::string& ruta, const long& tiempo_limite);
};

#endif
