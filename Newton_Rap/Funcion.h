#ifndef _FUNCION_H_
#define _FUNCION_H_

#include <string>
#include <vector>
#include "Monomio.h"

class Funcion{
private:
    std::vector<Monomio> monomios;
    std::string constante;

public:
    Funcion(std::string);

	std::string get_constante();
	void set_constante(std::string);

	std::string get_cadena_funcion();
	double evaluar_funcion(std::vector<char>, std::vector<double>);
};
#endif
