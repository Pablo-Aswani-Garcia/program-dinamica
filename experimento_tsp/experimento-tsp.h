
#ifndef EXPERIMENTOTSP_H
#define EXPERIMENTOTSP_H

#include "../algoritmos/algoritmo.h"
#include "../instancia_tsp/instancia-tsp.h"
#include "../algoritmos/fuerza-bruta/fuerza-bruta.h"
#include "../algoritmos/voraz/voraz.h"
#include "../algoritmos/programacion-dinamica/programacion-dinamica.h"
#include <chrono>
#include <iostream>

class ExperimentoTSP {
public:
    static void Ejecutar(const std::string& ruta);
};

#endif
