/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 * Práctica 4 Experimentación con Programación Dinámica
 *
 * @author Pablo Aswani García
 * @since Fri 14 Mar 2025
 * @brief Declaración de la clase VorazMedio
 * @see
 */

#ifndef VORAZ_MEDIO_H
#define VORAZ_MEDIO_H

#include "../algoritmo.h"
/**
 * @brief Representa un algoritmo vorazMedio para resolver el problema del TSP.
 */
class VorazMedio : public Algoritmo {
public:
  VorazMedio(long tiempo_limite) : Algoritmo(tiempo_limite) {};
  std::pair<std::vector<std::string>, int> resolver(
      const std::vector<std::vector<int>>& transiciones,
      const std::vector<std::string>& ciudades) override;
};

#endif