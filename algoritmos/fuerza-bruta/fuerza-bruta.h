#ifndef FUERZABRUTA_H
#define FUERZABRUTA_H

#include "../algoritmo.h"

class FuerzaBruta : public Algoritmo {
public:
    std::pair<std::vector<std::string>, int> resolver(const std::vector<std::vector<int>>& matriz, const std::vector<std::string>& ciudades) override;
};

#endif