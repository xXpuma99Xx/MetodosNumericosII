#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

const size_t length = 15;

std::string imprimir_celda(std::string texto, size_t t = length, bool centrar = true);
std::string linea(size_t t, bool espacios = false);
std::string linea_completa(size_t n,std::vector<size_t> t);
void llenar_t(std::vector<size_t> &t,size_t n);
std::string imprimir_renglon(std::vector<std::string> celdas, std::vector<size_t> t);
std::string imprimir_headers(std::vector<std::string> nombres, bool linea_final = true, bool linea_inicial = true, std::vector<size_t> t = std::vector<size_t> {});
void ordenar_dos_vectores(std::vector<double> &x, std::vector<double> &fx);

bool si_no(std::string texto);
int imprimir_menu(std::vector<std::string> opciones);
bool numero(std::string cadena);
void no_valido(bool borrar = true);
void borrar_pantalla();

template<typename T>
std::string imprimir_numero(T numero, size_t t = length){
	std::stringstream stream;
	std::string numero_str;
	size_t aux{};

	stream << std::fixed << std::setprecision(15) << numero;
	numero_str = stream.str();
	for(size_t i{};i < numero_str.size();i++) {
		if(numero_str[i] == '.'){
			aux = i;
			for(size_t j{i + 1};j < numero_str.size();j++){
				if(numero_str[j] > '0')
					aux = j + 1;
				i = j;
			}
		}
	}
	if(aux)
		numero_str = numero_str.substr(0,aux);
	if(numero_str.size() > t)
		numero_str = numero_str.substr(0,t);
	return numero_str;
}

template<typename T>
size_t obtener_n(std::vector<std::vector<T>> m){
	size_t n{};

	for(size_t i{};i < m.size();i++)
		if(m[i].size() > n)
			n = m[i].size();
	return n;
}

template<typename T>
std::string imprimir_tabla(std::vector<std::string> nombres, std::vector<std::vector<T>> datos, std::vector<size_t> t = std::vector<size_t> {}){
	std::string tabla;
	size_t n{obtener_n<T>(datos)};

	llenar_t(t,nombres.size());
	tabla = imprimir_headers(nombres, true, true, t);
	for(size_t i{};i < n + 1;i++){
		std::string renglon;

		for(size_t j{};j < datos.size();j++){
			if(i < datos[j].size()){
				if(j == 0)
					renglon += "|";
				if(renglon[renglon.size() - 1] == '-')
					renglon += "|" + imprimir_celda(imprimir_numero<T>(datos[j][i],t[j]),t[j],false);
				else if(renglon[renglon.size() - 1] == ' ')
					renglon += "|" + imprimir_celda(imprimir_numero<T>(datos[j][i],t[j]),t[j],false);
				else
					renglon += imprimir_celda(imprimir_numero<T>(datos[j][i],t[j]),t[j],false);
			} else if(i == datos[j].size()){
				if(j == 0||renglon[renglon.size() - 1] == ' '||renglon[renglon.size() - 1] == '-')
					renglon += "+" + linea(t[j]);
				else if(renglon[renglon.size() - 1] == '|')
					renglon += linea(t[j]);
				if(j == datos.size() - 1)
					renglon += "+";
			} else if(i > datos[j].size()){
				if(j == 0||renglon[renglon.size() - 1] == ' ')
					renglon += linea(t[j] + 1, true);
				else if(renglon[renglon.size() - 1] == '-')
					renglon += "+" + linea(t[j], true);
				else
					renglon += linea(t[j], true);
			}
		}
		tabla += renglon + "\n";
	}
	return tabla;
}

template<typename T>
std::string imprimir_matriz(std::vector<std::vector<T>> m, std::vector<size_t> t = std::vector<size_t> {}, std::vector<std::string> nombres_h = std::vector<std::string> {}, std::vector<std::string> nombres_v = std::vector<std::string> {}){
	size_t n {obtener_n<T>(m)};
	std::string linea;
	std::string tabla_matriz;

	if(nombres_h.size()){
		llenar_t(t,nombres_h.size());
		tabla_matriz = imprimir_headers(nombres_h,false,true,t);
		linea = linea_completa(nombres_h.size(),t);
	} else{
		llenar_t(t,n);
		linea = linea_completa(n,t);
	}
	tabla_matriz += "\n" + linea;
	for(size_t i{};i < m.size();i++){
		std::string renglon{};

		if(nombres_v.size())
			renglon += imprimir_headers(std::vector<std::string> {nombres_v[i]},false,false,std::vector<size_t> {t[0]});
		else
			renglon += "|";
		for(size_t j{};j < n;j++){
			if(nombres_v.size())
				renglon += imprimir_celda(imprimir_numero<T>(m[i][j],t[j + 1]),t[j + 1],false);
			else
				renglon += imprimir_celda(imprimir_numero<T>(m[i][j],t[j]),t[j],false);
		}
		tabla_matriz += renglon + "\n" + linea;
	}
	return tabla_matriz;
}

template <typename T>
std::string imprimir_vector(std::vector<T> v,size_t t = length, std::string nombre = ""){
	std::string tabla_vector;
	std::string linea{linea_completa(1,std::vector<size_t> {t})};

	if(nombre.size() > 0)
		tabla_vector += imprimir_headers(std::vector<std::string> {nombre}, false, true, std::vector<size_t> {t}) + "\n";
	tabla_vector += linea;
	for(size_t i{};i < v.size();i++){
		tabla_vector += "|" + imprimir_celda(imprimir_numero<T>(v[i],t),t,false) + "\n" + linea;
	}
	return tabla_vector;
}

template <typename T>
T mientras_no_sea_numero(std::string texto) {
	std::string respuesta;

	do {
		std::cout << texto;
		std::cin >> respuesta;
		if (!numero(respuesta))
			no_valido();
	} while (!numero(respuesta));
	return static_cast<T>(stod(respuesta));
}

#endif
