/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 * Práctica 4 Experimentación con Programación Dinámica
 *
 * @author Pablo Aswani García
 * @since Fri 14 Mar 2025
 * @brief Declaración de la clase InstanciaTsp
 * @see
 */

#ifndef INSTANCIA_TSP_H_
#define INSTANCIA_TSP_H_

#include <string>
#include <vector>

/**
 * @brief Clase que permite leer una instancia del problema del TSP desde un archivo.
 */
class InstanciaTSP {
public:
  static bool LeerInstancia(const std::string& ruta,
                            std::vector<std::string>& ciudades,
                            std::vector<std::vector<int>>& distancias);
};

#endif  // INSTANCIA_TSP_H_
