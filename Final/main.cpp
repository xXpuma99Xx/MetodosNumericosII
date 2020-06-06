#include <iostream>
#include "Funciones.hpp"
#include "Diferencias_Divididas.hpp"

int main(){
	std::vector<double> x{1,2.7,3.2,4.8,5.6};
	std::vector<double> fx{14.2,17.8,22,38.3,51.7};
	Diferencias_Divididas a{x,fx};

	std::cout << a.imprimir_x_fx() << std::endl;
	std::cout << a.imprimir_x() << std::endl;
	std::cout << a.imprimir_fx() << std::endl;
	std::cout << a.imprimir_tabla_escalonada() << std::endl;
	std::cout << a.imprimir_potencias(3) << std::endl;
	return 0;
}
