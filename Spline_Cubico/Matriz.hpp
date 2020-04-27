#ifndef _MATRIZ_M_
#define _MATRIZ_M_

#include <vector>
#include <string>

class Matriz {
protected:
	std::vector<std::vector<double>> inversa;
	std::vector<std::vector<double>> transpuesta;

	void invertir();

public:
	std::vector<std::vector<double>> matriz;

	Matriz();
	Matriz(std::vector<std::vector<double>>, bool);

	void voltear();
	std::vector<std::vector<double>> get_matriz();
	std::vector<std::vector<double>> get_inversa();
	
	std::string imprimir_tabla_matriz();
	std::string imprimir_tabla_inversa();
	std::string imprimir_tabla_transpuesta();
	
	std::vector<double> v_x_m(std::vector<std::vector<double>>,std::vector<double>);
	std::vector<double> vector_x_matriz(std::vector<double>);
	std::vector<double> vector_x_inversa(std::vector<double>);

};

#endif

