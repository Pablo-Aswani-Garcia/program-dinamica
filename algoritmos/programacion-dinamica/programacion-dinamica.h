#ifndef PROGRAMACIONDINAMICA_H
#define PROGRAMACIONDINAMICA_H

#include "../algoritmo.h"
#include <unordered_map>

class ProgramacionDinamica : public Algoritmo {
public:
    std::pair<std::vector<std::string>, int> resolver(const std::vector<std::vector<int>>& transiciones, const std::vector<std::string>& ciudades) override;
};

#endif