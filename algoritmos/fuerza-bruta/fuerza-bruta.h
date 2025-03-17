#ifndef FUERZABRUTA_H
#define FUERZABRUTA_H

#include "../algoritmo.h"

/**
 * Implementación del algoritmo de fuerza bruta para resolver el problema del TSP.
 **/
class FuerzaBruta : public Algoritmo {
public:
    FuerzaBruta(long tiempo_limite) : Algoritmo(tiempo_limite) {};
    std::pair<std::vector<std::string>, int> resolver(const std::vector<std::vector<int>>& transiciones, const std::vector<std::string>& ciudades) override;
};

#endif