#ifndef PROGRAMACIONDINAMICA_H
#define PROGRAMACIONDINAMICA_H

#include "../algoritmo.h"
#include <unordered_map>

class ProgramacionDinamica : public Algoritmo {
public:
    std::pair<std::vector<std::string>, int> resolver(const std::vector<std::vector<int>>& matriz, const std::vector<std::string>& ciudades) override;

private:
    int tsp(int pos, int mask, const std::vector<std::vector<int>>& matriz);
    std::vector<int> camino;
    std::unordered_map<int, std::unordered_map<int, int>> memo;
    int n;
};

#endif