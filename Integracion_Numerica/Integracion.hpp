#ifndef _INTEGRACION_H_
#define _INTEGRACION_H_

#include "Interpolacion_Polinomial.hpp"

class Integracion: public Interpolacion_Polinomial {
protected:
	double h;

public:
	Integracion(std::vector<double>, std::vector<double>);

	double get_h() const;

	std::string imprimir_todo();
};

#endif
