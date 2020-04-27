#ifndef _MATRIZ_M_
#define _MATRIZ_M_

#include <vector>
#include <string>

class Matriz {
protected:
	std::vector<std::vector<double>> matriz;
	std::vector<std::vector<double>> inversa;

	void invertir();

public:
	Matriz(std::vector<std::vector<double>>, bool);

	std::vector<std::vector<double>> get_matriz();
	std::vector<std::vector<double>> get_inversa();
	
	std::string imprimir_tabla_matriz();
	std::string imprimir_tabla_inversa();
};

#endif

