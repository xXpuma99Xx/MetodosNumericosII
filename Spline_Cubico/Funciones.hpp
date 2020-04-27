#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

#include <string>
#include <vector>

const size_t length = 12;

std::string imprimir_numero(double numero);
std::string imprimir_headers(std::vector<std::string> nombres);
std::string imprimir_vector(std::vector<double> array, std::string texto, bool enumerar);
std::string imprimir_vectores(std::vector<std::vector<double>> vectores, std::vector<std::string> nombres);
std::string imprimir_matriz(std::vector<std::vector<double>> m);

#endif

