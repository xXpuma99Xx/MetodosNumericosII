#include <iostream>
#include "Diferencias_Divididas.h"

/*
 * Constructores
*/
Diferencias_Divididas::Diferencias_Divididas(std::vector<std::vector<double>> vectores): Diferencias_Divididas(vectores[0], vectores[1]){
}

Diferencias_Divididas::Diferencias_Divididas(std::vector<double> x, std::vector<double> fx): x{x}, fx{fx}{

	ordenar();
	llenar_tabla();
}

/*
 * Gets y Sets de Atrivutos
*/
double Diferencias_Divididas::get_x(size_t i){
	return x[i];
}

void Diferencias_Divididas::set_x(size_t i,double x){
	this->x[i] = x;
}

double Diferencias_Divididas::get_fx(size_t i){
	return fx[i];
}

void Diferencias_Divididas::set_fx(size_t i,double x){
	this->fx[i] = x;
}

std::vector<double> Diferencias_Divididas::get_vector_x(){
	return x;
}

std::vector<double> Diferencias_Divididas::get_vector_fx(){
	return fx;
}

std::vector<std::vector<double>> Diferencias_Divididas::get_tabla(){
	return tabla;
}

/*
 * Metodos
*/
void Diferencias_Divididas::ordenar(){
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

void Diferencias_Divididas::llenar_tabla(){
	for(size_t i {};i < x.size() - 1;i++){
		std::vector<double> aux;
		double valor{};

		for(size_t j {};j < x.size() - i - 1;j++){
			if(i == 0)
				valor = (fx[j+1]-fx[j])/(x[j+1]-x[j]);
			else 
				valor = (tabla[i-1][j+1]-tabla[i-1][j])/(x[j+1+i]-x[j]);
			aux.push_back(valor);
		}
		tabla.push_back(aux);
	}
}

std::vector<double> Diferencias_Divididas::potencias(double numero){
	std::vector<double> p;

	for(size_t i {};i < x.size() - 1;i++){
		double aux;
		if(i == 0)
			aux = fx[0] + (tabla[0][0] * (numero - x[0]));
		else{
			aux = tabla[i][0];
			for(size_t j{};j <= i;j++)
				aux *= (numero - x[j]);
		}
		p.push_back(aux);
	}

	return p;
}
