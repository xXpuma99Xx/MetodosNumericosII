#include "Metodo_Numerico.hpp"

Metodo_Numerico::Metodo_Numerico() {}

Metodo_Numerico::Metodo_Numerico(std::vector<double> x, std::vector<double> fx) 
	: x{x}, fx{fx} {
}

std::vector<double> Metodo_Numerico::get_x() const {
	return x;
} void Metodo_Numerico::set_x(std::vector<double> x) {
	this->x = x;
}

std::vector<double> Metodo_Numerico::get_fx() const {
	return fx;
}

void Metodo_Numerico::set_fx(std::vector<double> fx) {
	this->fx = fx;
}

std::string Metodo_Numerico::imprimir_fx(size_t t) {
	return imprimir_vector<double>(fx,t,"F(x)");
}

std::string Metodo_Numerico::imprimir_x(size_t t) {
	return imprimir_vector<double>(x,t,"x");
}

std::string Metodo_Numerico::imprimir_x_fx(size_t t) {
	Matriz<double> m{std::vector<std::vector<double>> {x,fx}};
	Matriz<double> transpuesta{m.transpuesta()};

	return imprimir_matriz<double>(transpuesta.get_matriz(), std::vector<size_t> {t,t}, std::vector<std::string> {"x","F(x)"});
}
