#include "Funciones.hpp"
#include "Diferenciacion.hpp"

Diferenciacion::Diferenciacion(std::vector<double> x, std::vector<double> fx,double h)
	:Interpolacion_Polinomial(x,fx),h{h}{
		obtener_dfx();
	}

std::vector<double> Diferenciacion::get_dfx() const{
	return dfx;
}

void Diferenciacion::set_h(double h) {
	this->h = h;
}

double Diferenciacion::get_h() const{
	return h;
}

void Diferenciacion::obtener_dfx(){
	for(size_t i{};i < fx.size()-1;i++){
		if(i == 0)
			dfx.push_back(0);
		else
			dfx.push_back((fx[i+1]-fx[i-1])/(2*h));
	}
}

std::string Diferenciacion::imprimir_todo(){
	std::vector<std::vector<double>> vectores{x,fx,dfx};
	std::vector<std::string> nombres {"x","fx","dfx"};

	return imprimir_vectores(vectores, nombres);
}
