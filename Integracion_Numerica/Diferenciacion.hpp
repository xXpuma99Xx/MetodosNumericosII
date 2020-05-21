#ifndef _DIFERENCIACION_H_
#define _DIFERENCIACION_H_

#include "Interpolacion_Polinomial.hpp"

class Diferenciacion: public Interpolacion_Polinomial {
protected:
	std::vector<double> dfx;
	double h;

public:
	Diferenciacion(std::vector<double>, std::vector<double>,double);

	std::vector<double> get_dfx() const;

	void set_h(double h);
	double get_h() const;

	std::string imprimir_todo();
	void obtener_dfx();
};

#endif

