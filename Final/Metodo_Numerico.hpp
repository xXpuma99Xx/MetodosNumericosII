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

public:
	Metodo_Numerico();
	Metodo_Numerico(std::vector<double> x, std::vector<double> fx);

	std::vector<double> get_x() const;
	void set_x(std::vector<double> x);
	std::vector<double> get_fx() const;
	void set_fx(std::vector<double> fx);

	std::string imprimir_x(size_t t = length);
	std::string imprimir_fx(size_t t = length);
	std::string imprimir_x_fx(size_t t = length);
};
#endif

