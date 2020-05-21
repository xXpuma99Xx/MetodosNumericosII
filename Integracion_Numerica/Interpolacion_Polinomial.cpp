#include "Interpolacion_Polinomial.hpp"
#include "Funciones.hpp"

/* Constructores */

Interpolacion_Polinomial::Interpolacion_Polinomial(std::vector<double> vect_x, std::vector<double> vect_fx)
	: x{vect_x}, fx{vect_fx} {
	ordenar_vectores(x,fx);
}

/* Gets y Sets de Atributos */

std::vector<double> Interpolacion_Polinomial::get_x() const {
	return x;
}

std::vector<double> Interpolacion_Polinomial::get_fx() const {
	return fx;
}

/* Metodos */

std::string Interpolacion_Polinomial::imprimir_x_fx() {
	std::vector<std::vector<double>> imprimir{x, fx};
	std::vector<std::string> nombres{"x", "fx"};

	return imprimir_vectores(imprimir, nombres);
}

std::string Interpolacion_Polinomial::imprimir_f() {
	return imprimir_vector(x, "x", false);
}

std::string Interpolacion_Polinomial::imprimir_fx() {
	return imprimir_vector(fx, "f(x)", false);
}
