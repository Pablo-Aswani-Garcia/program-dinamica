#ifndef VORAZ_H
#define VORAZ_H

#include "../algoritmo.h"

class Voraz : public Algoritmo {
public:
    Voraz(long tiempo_limite) : Algoritmo(tiempo_limite) {};
    std::pair<std::vector<std::string>, int> resolver(const std::vector<std::vector<int>>& transiciones, const std::vector<std::string>& ciudades) override;
};

#endif