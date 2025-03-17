#ifndef ALGORITMO_H
#define ALGORITMO_H

#include <vector>
#include <string>

/**
 * Clase abstracta que define la interfaz de los algoritmos para resolver el problema del TSP.
 **/
class Algoritmo {
 public:
  Algoritmo(int tiempo_limite) : tiempo_limite_(tiempo_limite) {};
  virtual std::pair<std::vector<std::string>, int> resolver(const std::vector<std::vector<int>>& matriz, const std::vector<std::string>& ciudades) = 0;
  virtual ~Algoritmo() = default;
 protected:
    long tiempo_limite_;
};

#endif