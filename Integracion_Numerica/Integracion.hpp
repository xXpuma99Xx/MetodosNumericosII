#ifndef _INTEGRACION_H_
#define _INTEGRACION_H_

#include "Interpolacion_Polinomial.hpp"

class Integracion: public Interpolacion_Polinomial {
protected:
	std::vector<double> s;
	std::vector<double> p;
	double h;
	double integral;

public:
	Integracion(std::vector<double>, std::vector<double>,double);

	std::vector<double> get_s();
	std::vector<double> get_p();

	void set_h(double);
	double get_h() const;

	void set_integral(double);
	double get_integral() const;

	std::string imprimir_todo();
	void obtener_s();
	void obtener_p();
	void obtener_integral();
};

#endif
