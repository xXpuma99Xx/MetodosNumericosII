#include "Diferencias_Divididas.hpp"
#include "Funciones.hpp"

/* Constructores */

Diferencias_Divididas::Diferencias_Divididas(std::vector<std::vector<double>> vectores): Diferencias_Divididas(vectores[0], vectores[1]){
}

Diferencias_Divididas::Diferencias_Divididas(std::vector<double> vect_x, std::vector<double> vect_fx): Interpolacion_Polinomial(vect_x,vect_fx){
	llenar_tabla();
}

/* Gets y Sets de Atributos */

std::vector<std::vector<double>> Diferencias_Divididas::get_tabla(){
	return tabla;
}

/* Metodos */

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

std::string Diferencias_Divididas::imprimir_potencias(double numero){
	std::vector<double> vect_potencias {potencias(numero)};
	std::vector<std::string> nombres;

	for(size_t i{};i < vect_potencias.size();i++)
		nombres.push_back("p"+ std::to_string(i + 1));

	std::string tabla_potencias {imprimir_headers(nombres)};
	double aux {};
	
	for(size_t i{};i < vect_potencias.size();i++){
		aux += vect_potencias[i];
		tabla_potencias = tabla_potencias + "|" + imprimir_numero(aux);
	}
	tabla_potencias += "|\n";
	for(size_t i {};i < nombres.size();i++){
		tabla_potencias += "+";
		for(double j {}; j < length;j++)
			tabla_potencias += "-";
	}

	return tabla_potencias + "+\n";
}

std::string Diferencias_Divididas::imprimir_tabla(){
	std::vector<std::string> nombres {"x","f(x)"};
	std::string linea;

	for(size_t i{1};i <= tabla.size();i++)
		nombres.push_back("f"+ std::to_string(i));
	
	std::string tabla_completa {imprimir_headers(nombres)};

	for(size_t i{};i < length;i++)
		linea += "-";
	linea += "+";

	for(size_t i{};i < x.size();i++){
		tabla_completa = tabla_completa + "|" + imprimir_numero(x[i]) + "|" + imprimir_numero(fx[i]);
		for(size_t j{};j < tabla.size() - i;j++){
			tabla_completa = tabla_completa + "|" + imprimir_numero(tabla[j][i]);
		}
		if(i > 0)
			tabla_completa = tabla_completa + "|" + linea + "\n";
		else
			tabla_completa += "|\n";
	}
	tabla_completa = tabla_completa + "+" + linea + linea + "\n";

	return tabla_completa;
}

