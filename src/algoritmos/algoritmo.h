/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 * Práctica 4 Experimentación con Programación Dinámica
 *
 * @author Pablo Aswani García
 * @since Fri 14 Mar 2025
 * @brief Declaración de la clase Algoritmo
 * @see
 */

#ifndef ALGORITMO_H
#define ALGORITMO_H

#include <string>
#include <vector>

/**
 * @brief Define la interfaz de los algoritmos para resolver el
 * problema del TSP.
 */
class Algoritmo {
public:
  Algoritmo(int tiempo_limite) : tiempo_limite_(tiempo_limite) {};
  virtual std::pair<std::vector<std::string>, int> resolver(
      const std::vector<std::vector<int>>& matriz,
      const std::vector<std::string>& ciudades) = 0;
  virtual ~Algoritmo() = default;

protected:
  long tiempo_limite_;
};

#endif