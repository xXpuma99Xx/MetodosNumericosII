#include "Funciones.hpp"

std::string imprimir_numero(double numero){
	std::string numero_string {std::to_string(numero)};

	if(numero_string.size() > length)
		numero_string = numero_string.substr(0,length);
	for(size_t i {};i < numero_string.size();i++){
		if(numero_string[i] == '.'){
			unsigned contador {};

			for(size_t j = i+1;j < numero_string.size();j++){
				if(numero_string[j] == '0')
					contador++;
				else{
					i = j;
					contador = 0;
				}
			}
			if(contador > 0)
				numero_string = numero_string.erase(i+1,contador);
			break;
		}
	}
	if(numero_string[numero_string.size() - 1] == '.')
		numero_string.erase(numero_string.size()-1);
	if(numero_string.size() < length){
		for(size_t i {numero_string.size()};i < length;i++)
			numero_string += " ";
	}

	return numero_string;
}

std::string imprimir_headers(std::vector<std::string> nombres){
	size_t n {nombres.size()};
	std::string headers{};
	std::string linea {};

	for(size_t i {};i < n;i++){
		linea += "+";
		for(size_t j {}; j < length;j++)
			linea += "-";
	}
	linea += "+\n";
	headers = linea + "|";
	for(size_t i {};i < n;i++){
		std::string celda {nombres[i]};
		int espacios_izquierda {static_cast<int>((length - nombres[i].size()) / 2)};
		int espacios_derecha {((length - nombres[i].size()) % 2) == 0 ? espacios_izquierda : espacios_izquierda + 1};

		for(int j {}; j < espacios_izquierda;j++)
			celda = " " + celda;
		for(int j {}; j < espacios_derecha;j++)
			celda += " ";
		headers = headers + celda + "|";
	}

	return headers + "\n" + linea;
}

std::string imprimir_vector(std::vector<double> array, std::string texto, bool enumerar){
	std::vector<std::string> nombres {texto};
	std::string tabla {imprimir_headers(nombres)};
	
	for(size_t i {};i < array.size();i++){
		if(enumerar)
			tabla = tabla + "|" + imprimir_numero(array[i]) + "| " + std::to_string(i) + "\n";
		else
			tabla = tabla + "|" + imprimir_numero(array[i]) + "|\n";
	}
	tabla += "+";
	for(size_t j {}; j < length;j++)
		tabla +=  "-";

	return tabla + "+\n";
}

std::string imprimir_vectores(std::vector<double> x, std::vector<double> fx){
	std::vector<std::string> nombres {"x","f(x)"};
	std::string tabla {imprimir_headers(nombres)};

	for(size_t i {};i < x.size();i++)
		tabla = tabla + "|" + imprimir_numero(x[i]) + "|" + imprimir_numero(fx[i]) + "|\n";
	for(size_t i {};i < nombres.size();i++){
		tabla += "+";
		for(size_t j {}; j < length;j++)
			tabla += "-";
	}
	
	return tabla + "+\n" ;
}

std::string imprimir_matriz(std::vector<std::vector<double>> m){
	std::string tabla;
	std::string linea;

	for(size_t i {};i < m[0].size();i++){
		linea += "+";
		for(size_t j {}; j < length;j++)
			linea += "-";
	}
	linea += "+\n";
	tabla += linea;
	for(size_t i{};i < m.size();i++){
		std::string fila {"|"};
		for(size_t j{};j < m[i].size();j++)
			fila += imprimir_numero(m[i][j]) + "|";
		tabla += fila + "\n" + linea;
	}

	return tabla;
}

