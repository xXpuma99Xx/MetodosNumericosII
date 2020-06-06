#ifndef _DIFERENCIAS_DIVIDIDAS_H_
#define _DIFERENCIAS_DIVIDIDAS_H_

#include "Metodo_Numerico.hpp"

class Diferencias_Divididas : public Metodo_Numerico {
protected:
	std::vector<std::vector<double>> tabla;

public:
	Diferencias_Divididas();
	Diferencias_Divididas(std::vector<double> x, std::vector<double> fx);

	std::vector<std::vector<double>> get_tabla();

	void llenar_tabla();
	std::string imprimir_potencias(double numero,size_t tamanio = length); 
	std::string imprimir_tabla_escalonada();
};

#endif

