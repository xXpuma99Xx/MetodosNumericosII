#ifndef _MATRIZ_H_
#define _MATRIZ_H_

#include <vector>
#include <string>
#include "Funciones.hpp"

template<class T>
class Matriz {
protected:
	std::vector<std::vector<T>> matriz;

public:
	Matriz();
	Matriz(std::vector<std::vector<T>> m);

	std::vector<std::vector<T>> get_matriz();
	void set_matriz(std::vector<std::vector<T>> m);

	std::string imprimir_tabla_matriz(size_t tamanio = length, size_t precision = length);
	
	Matriz inversa();
	Matriz transpuesta();

	std::vector<T> vector_x_matriz(std::vector<T> v);

	Matriz matriz_x_matriz(std::vector<std::vector<T>> m);
	Matriz matriz_x_matriz(Matriz m);

	Matriz matriz_s_matriz(std::vector<std::vector<T>> m);
	Matriz matriz_s_matriz(Matriz m);
};

#endif

