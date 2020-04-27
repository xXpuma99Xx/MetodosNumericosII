#include "Matriz.hpp"
#include "Funciones.hpp"

Matriz::Matriz(std::vector<std::vector<double>> m, bool cuadrada)
	: matriz{m} {
		if(cuadrada)
			invertir();
}

std::vector<std::vector<double>> Matriz::get_matriz(){
	return matriz;
}

std::vector<std::vector<double>>  Matriz::get_inversa(){
	return inversa;
}
	
std::string Matriz::imprimir_tabla_matriz(){
	return imprimir_matriz(matriz);
}

std::string Matriz::imprimir_tabla_inversa(){
	return imprimir_matriz(inversa);
}

void Matriz::invertir(){
	std::vector<std::vector<double>> identidad;
	std::vector<std::vector<double>> aux{matriz};
	size_t n {aux.size()};

	for(size_t i {};i < n;i++){
		std::vector<double> fila;
		for(size_t j{};j < n;j++){
			if(i == j)
				fila.push_back(1);
			else
				fila.push_back(0);
		}
		identidad.push_back(fila);
	}
	for(size_t i {};i < n;i++){
		if(aux[i][i] == 0){
			for(size_t j {i + 1};j < n;j++){
				if(aux[j][i] != 0){
					std::vector<double> aux_vect {aux[i]};
					aux[i] = aux[j];
					aux[j] = aux_vect;
					aux_vect = identidad[i];
					identidad[i] = identidad[j];
					identidad[j] = aux_vect;
					break;
				}
			}
		}
		if(aux[i][i] != 1){
			double numero {aux[i][i]};
			for(size_t j{};j < n;j++){
				aux[i][j] /= numero;
				identidad[i][j] /= numero;
			}
		}
		for(size_t j{};j < n;j++){
			if(j != i){
				double numero{aux[j][i]};
				for(size_t k{};k < n;k++){
					aux[j][k] = aux[j][k] - (aux[i][k] * numero);
					identidad[j][k] = identidad[j][k] - (identidad[i][k] * numero);
				}
			}
		}
	}

	inversa = identidad;
}

