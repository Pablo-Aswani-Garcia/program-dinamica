#ifndef PROGRAMACIONDINAMICA_H
#define PROGRAMACIONDINAMICA_H

#include "../algoritmo.h"
#include <unordered_map>

class ProgramacionDinamica : public Algoritmo {
public:
    ProgramacionDinamica(long tiempo_limite) : Algoritmo(tiempo_limite) {};
    std::pair<std::vector<std::string>, int> resolver(const std::vector<std::vector<int>>& transiciones, const std::vector<std::string>& ciudades) override;
};

#endif