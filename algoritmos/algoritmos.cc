#ifndef ALGORITMO_H
#define ALGORITMO_H

#include <vector>
#include <string>

class Algoritmo {
public:
    virtual std::pair<std::vector<std::string>, int> resolver(const std::vector<std::vector<int>>& matriz, const std::vector<std::string>& ciudades) = 0;
    virtual ~Algoritmo() = default;
};

#endif