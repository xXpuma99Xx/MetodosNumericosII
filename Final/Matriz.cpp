#include "Matriz.hpp"

template<class T>
Matriz<T>::Matriz() {}

template<class T>
Matriz<T>::Matriz(std::vector<std::vector<T>> m)
	: matriz{m}{
}

template<class T>
std::vector<std::vector<T>> Matriz<T>::get_matriz() {
	return matriz;
}

template<class T>
void Matriz<T>::set_matriz(std::vector<std::vector<T>> m){
	matriz = m;
}

template<class T>
std::string Matriz<T>::imprimir_tabla_matriz(size_t tamanio, size_t precision){
	std::vector<size_t> t;
	size_t n{obtener_n(matriz)};

	for(size_t i{};i < n;i++)
		t.push_back(tamanio);
	return imprimir_matriz(matriz,t,precision);
}
	
template<class T>
Matriz<T> Matriz<T>::inversa() {
	std::vector<std::vector<T>> identidad;
	std::vector<std::vector<T>> matriz_aux{matriz};
	size_t n{matriz_aux.size()};

	for (size_t i{}; i < n; i++) {
		std::vector<T> fila;

		for (size_t j{}; j < n; j++) {
			if (i == j)
				fila.push_back(1);
			else
				fila.push_back(0);
		}
		identidad.push_back(fila);
	}
	for (size_t i{}; i < n; i++) {
		if (matriz_aux[i][i] == 0) {
			for (size_t j{i + 1}; j < n; j++) {
				if (matriz_aux[j][i] != 0) {
					std::vector<T> vect_aux;

					vect_aux = matriz_aux[i];
					matriz_aux[i] = matriz_aux[j];
					matriz_aux[j] = vect_aux;
					vect_aux = identidad[i];
					identidad[i] = identidad[j];
					identidad[j] = vect_aux;
					break;
				}
			}
		}
		if (matriz_aux[i][i] != 1) {
			T divisor{matriz_aux[i][i]};

			for (size_t j{}; j < n; j++) {
				matriz_aux[i][j] /= divisor;
				identidad[i][j] /= divisor;
			}
		}
		for (size_t j{}; j < n; j++) {
			if (j != i) {
				T numero{matriz_aux[j][i]};

				for (size_t k{}; k < n; k++) {
					matriz_aux[j][k] = matriz_aux[j][k] - (matriz_aux[i][k] * numero);
					identidad[j][k] = identidad[j][k] - (identidad[i][k] * numero);
				}
			}
		}
	}
	return Matriz{identidad};
}

template<class T>
Matriz<T> Matriz<T>::transpuesta(){
	std::vector<std::vector<T>> transpuesta;
	size_t filas{matriz.size()};
	size_t columnas{obtener_n(matriz)};

	for (size_t i{}; i < columnas; i++) {
		std::vector<T> fila;

		for (size_t j{}; j < filas; j++)
			fila.push_back(matriz[j][i]);
		transpuesta.push_back(fila);
	}
	return Matriz{transpuesta};
}

template<class T>
std::vector<T> Matriz<T>::vector_x_matriz(std::vector<T> v){
	std::vector<T> resultante;

	for (size_t i{}; i < matriz.size(); i++) {
		T celda{};

		for (size_t j{}; j < matriz[i].size(); j++)
			celda += v[j] * matriz[i][j];
		resultante.push_back(celda);
	}
	return resultante;
}

template<class T>
Matriz<T> Matriz<T>::matriz_x_matriz(std::vector<std::vector<T>> m){
	std::vector<std::vector<T>> resultado;
	size_t filas {matriz.size()};
	size_t columnas {obtener_n(m)};
	size_t n {m.size()};
	
	for(size_t i{};i < filas;i++){
		std::vector<T> fila;

		for(size_t j{};j < columnas;j++){
			T suma{};

			for(size_t k{};k < n;k++)
				suma += matriz[i][k] * m[k][j]; 
			fila.push_back(suma);
		}
		resultado.push_back(fila);
	}
	return Matriz{resultado};
}

template<class T>
Matriz<T> Matriz<T>::matriz_x_matriz(Matriz m) {
	return matriz_x_matriz(m.matriz);
}

template<class T>
Matriz<T> Matriz<T>::matriz_s_matriz(std::vector<std::vector<T>> m) {
	std::vector<std::vector<double>> resultado;
	size_t filas{matriz.size()};
	size_t columnas{obtener_n(matriz)};

	for(size_t i{};i < filas;i++){
		std::vector<T> fila;

		for(size_t j{};j < columnas;j++)
			fila.push_back(matriz[i][j] + m[i][j]);
		resultado.push_back(fila);
	}
	return Matriz{resultado};
}

template<class T>
Matriz<T> Matriz<T>::matriz_s_matriz(Matriz m){
	return matriz_s_matriz(m.matriz);
}
