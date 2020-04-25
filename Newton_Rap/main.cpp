#include <iostream>
#include "Funcion.h"
#include <string>
#include <vector>

int main(){
	std::string b{};

	std::cout << "Dame una funcion: "; std::cin >> b;
	Funcion a {b};

	std::cout << a.get_cadena_funcion()<< std::endl;
	std::cout << std::boolalpha << (b == a.get_cadena_funcion())<< std::endl;
	
	return 0;
}
