#ifndef VORAZ_H
#define VORAZ_H

#include "../algoritmo.h"

class Voraz : public Algoritmo {
public:
    std::pair<std::vector<std::string>, int> resolver(const std::vector<std::vector<int>>& transiciones, const std::vector<std::string>& ciudades) override;
};

#endif