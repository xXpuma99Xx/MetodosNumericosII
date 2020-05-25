#include "Metodo_Numerico.hpp"

Metodo_Numerico::Metodo_Numerico() {}

Metodo_Numerico::Metodo_Numerico(std::vector<double> x, std::vector<double> fx, size_t precision, size_t t) 
	: x{x}, fx{fx}, precision{precision}, t{t}{
}

Metodo_Numerico::Metodo_Numerico(std::vector<double> x, std::vector<double> fx) 
	: Metodo_Numerico(x,fx,length,length) {
}

Metodo_Numerico::Metodo_Numerico(std::vector<double> x, std::vector<double> fx, size_t precision) 
	: Metodo_Numerico(x,fx,precision,length) {
}

std::vector<double> Metodo_Numerico::get_x() const {
	return x;
}

void Metodo_Numerico::set_x(std::vector<double> x) {
	this->x = x;
}

std::vector<double> Metodo_Numerico::get_fx() const {
	return fx;
}

void Metodo_Numerico::set_fx(std::vector<double> fx) {
	this->fx = fx;
}

std::string Metodo_Numerico::imprimir_fx() {
	return imprimir_vector(fx,t,precision,"F(x)");
}

std::string Metodo_Numerico::imprimir_x() {
	return imprimir_vector(x,t,precision,"x");
}

std::string Metodo_Numerico::imprimir_x_fx() {
	Matriz<double> m{std::vector<std::vector<double>> {x,fx}};
	Matriz<double> transpuesta{m.transpuesta()};

	return imprimir_matriz<double>(transpuesta.get_matriz(), std::vector<size_t> {t,t},precision, std::vector<std::string> {"x","F(x)"});
}
