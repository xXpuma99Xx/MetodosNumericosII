#ifndef _METODO_NUMERICO_H_
#define _METODO_NUMERICO_H_

#include <vector>
#include <string>
#include "Matriz.hpp"
#include "Matriz.cpp"
#include "Funciones.hpp"

class Metodo_Numerico{
protected:
	std::vector<double> x;
	std::vector<double> fx;
	size_t t;
	size_t precision;

public:
	Metodo_Numerico();
	Metodo_Numerico(std::vector<double> x, std::vector<double> fx);
	Metodo_Numerico(std::vector<double> x, std::vector<double> fx, size_t precision);
	Metodo_Numerico(std::vector<double> x, std::vector<double> fx, size_t precision, size_t t);

	std::vector<double> get_x() const;
	void set_x(std::vector<double> x);
	std::vector<double> get_fx() const;
	void set_fx(std::vector<double> fx);

	std::string imprimir_x();
	std::string imprimir_fx();
	std::string imprimir_x_fx();
};
#endif

