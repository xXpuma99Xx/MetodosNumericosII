#ifndef _DIFERENCIAS_DIVIDIDAS_H_
#define _DIFERENCIAS_DIVIDIDAS_H_

#include "Interpolacion_Polinomial.hpp"

class Diferencias_Divididas : public Interpolacion_Polinomial {
protected:
	std::vector<std::vector<double>> tabla;

public:
	Diferencias_Divididas(std::vector<double>, std::vector<double>);

	std::vector<std::vector<double>> get_tabla();

	void llenar_tabla();
	std::vector<double> potencias(double);
	std::string imprimir_potencias(double);
	std::string imprimir_tabla();
};

#endif
