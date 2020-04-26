#ifndef _INTERPOLACION_POLINOMIAL_H_
#define _INTERPOLACION_POLINOMIAL_H_

#include <vector>
#include <string>

class Interpolacion_Polinomial {
protected:
	std::vector<double> x;
	std::vector<double> fx;

public:
	Interpolacion_Polinomial(std::vector<double>, std::vector<double>);
	Interpolacion_Polinomial(std::vector<std::vector<double>>);
	
	std::vector<double> get_x() const;
	std::vector<double> get_fx() const;

	std::string imprimir_x_fx();
	std::string imprimir_f();
	std::string imprimir_fx();

	void ordenar();
};

#endif

