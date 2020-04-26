#include "Interpolacion_Polinomial.hpp"
#include "Funciones.hpp"

/* Constructores */

Interpolacion_Polinomial::Interpolacion_Polinomial(std::vector<double> vect_x, std::vector<double> vect_fx)
	:x{vect_x},fx{vect_fx}{
		ordenar();
}

Interpolacion_Polinomial::Interpolacion_Polinomial(std::vector<std::vector<double>> vectores):Interpolacion_Polinomial(vectores[0],vectores[1]){
}

/* Gets y Sets de Atributos */

std::vector<double> Interpolacion_Polinomial::get_x() const{
	return x;
}

std::vector<double> Interpolacion_Polinomial::get_fx() const{
	return fx;
}

/* Metodos */

std::string Interpolacion_Polinomial::imprimir_x_fx(){
	return imprimir_vectores(x,fx);
}

std::string Interpolacion_Polinomial::imprimir_f(){
	return imprimir_vector(x,"x",false);
}

std::string Interpolacion_Polinomial::imprimir_fx(){
	return imprimir_vector(fx,"f(x)",false);
}

void Interpolacion_Polinomial::ordenar(){
	for(size_t i {};i < x.size();i++){
		for(size_t j {i};j < x.size();j++){
			if(x[j] < x[i]){
				double aux {};

				aux = x[j];
				x[j] = x[i];
				x[i] = aux;
				aux = fx[j];
				fx[j] = fx[i];
				fx[i] = aux;
			}
		}
	}
}

