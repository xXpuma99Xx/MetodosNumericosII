#include "Integracion.hpp"
#include "Funciones.hpp"

Integracion::Integracion(std::vector<double> x, std::vector<double> fx, double h)
	:Interpolacion_Polinomial(x,fx),h{h}{
		obtener_s();
		obtener_p();
		obtener_integral();
	}

std::vector<double> Integracion::get_s(){
	return s;
}

std::vector<double> Integracion::get_p(){
	return p;
}

void Integracion::set_h(double h){
	this->h = h;
}

double Integracion::get_h() const{
	return h;
}

void Integracion::set_integral(double integral){
	this->integral = integral;
}

double Integracion::get_integral() const{
	return integral;
}

std::string Integracion::imprimir_todo(){
	std::vector<std::vector<double>> vectores{x,fx,s,p};
	std::vector<std::string> nombres {"x","fx"," ", " "};
	std::string tabla {imprimir_vectores(vectores, nombres)};

	if(x.size() % 2 == 1)
		tabla += "S 1/3 = " + std::to_string(integral);
	else
		tabla += "S 1/3 + S 3/8 = " + std::to_string(integral);
	return tabla;
}

void Integracion::obtener_s(){
	size_t n {x.size()};

	if(n % 2 == 1){
		for(size_t i{};i < n;i++){
			if(i == 0||i == n - 1)
				s.push_back(1);
			else if(i % 2 == 0)
				s.push_back(2);
			else
				s.push_back(4);
		}
	} else{
		for(size_t i{};i < n - 4;i++){
			if(i == 0||i == n - 1)
				s.push_back(1);
			else if(i % 2 == 0)
				s.push_back(2);
			else
				s.push_back(4);
		}
		s.push_back(1);
		s.push_back(3);
		s.push_back(3);
		s.push_back(1);
	}
}

void Integracion::obtener_p(){
	for(size_t i{};i < x.size();i++)
		p.push_back(fx[i] * s[i]);
}

void Integracion::obtener_integral(){
	size_t n {x.size()};
	double suma {};

	if(n % 2 == 1) {
		for(size_t i{};i < n;i++)
			suma += p[i];
		integral = suma * (h/3);
	} else{
		for(size_t i{};i < n - 3;i++)
			suma += p[i];
		integral = suma * (h/3);
		suma = 0;
		for(size_t i{n - 4};i < n;i++)
			suma += p[i];
		integral += suma * (3*h/8);
	}
}

