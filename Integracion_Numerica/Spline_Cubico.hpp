#ifndef _SPLINE_CUBICO_H_
#define _SPLINE_CUBICO_H_

#include <vector>
#include <string>
#include "Interpolacion_Polinomial.hpp"
#include "Matriz.hpp"

class Spline_Cubico : public Interpolacion_Polinomial {
protected:
	std::vector<double> hi;
	std::vector<double> fi;
	std::vector<double> s;
	std::vector<double> p;
	std::vector<double> a;
	std::vector<double> b;
	std::vector<double> c;

public:
	Matriz matriz_rectangular;
	Matriz matriz_cuadrada;

	Spline_Cubico(std::vector<double>, std::vector<double>);

	std::vector<double> get_hi();
	std::vector<double> get_fi();
	std::vector<double> get_s();
	std::vector<double> get_p();
	std::vector<double> get_a();
	std::vector<double> get_b();
	std::vector<double> get_c();

	std::string imprimir_hi();
	std::string imprimir_fi();
	std::string imprimir_s();
	std::string imprimir_p();
	std::string imprimir_a();
	std::string imprimir_b();
	std::string imprimir_c();
	std::string imprimir_todas();

	void llenar_hi();
	void llenar_fi();
	void llenar_s();
	void llenar_p();
	void llenar_a();
	void llenar_b();
	void llenar_c();
	void llenar_matriz_rectangular();
	void llenar_matriz_cuadrada();

	std::string coeficientes();
};

#endif
