#include "Variable.h"
#include <cmath>

Variable::Variable(std::string cadena){
	size_t n{};

	if (isalpha(cadena[n])){
		if(cadena[n] == 'e')
			numero = cadena[n];
		else
			variable = cadena[n];
		n++;
	}
	else if(isdigit(cadena[n])){
		unsigned contador{};

		for (size_t i{n}; i < cadena.size(); i++){
			if (!isdigit(cadena[i])) break;
			contador++;
		}
		numero = cadena.substr(n, contador);
		n += contador;
	}

	if (n++ < cadena.size()){
		if (cadena[n] == '('){
			n++;
			if(cadena[n] == '-'){
				if(isalpha(cadena[n+1])){
					exponente = "-1";
					variable_exponente = cadena[n+1];
				}
				else if(isdigit(cadena[n+1])){
					unsigned contador{1};

					for (size_t i{n+1}; i < cadena.size(); i++){
						if (!isdigit(cadena[i])) break;
						contador++;
					}
					exponente = cadena.substr(n, contador);
					n += contador;
					if(cadena[n] != ')')
						variable_exponente = cadena[n];
				}
			}
			else if(isdigit (cadena[n])){
				unsigned contador{};

				for (size_t i{n}; i < cadena.size(); i++){
					if (!isdigit(cadena[i])) break;
					contador++;
				}
				exponente = cadena.substr(n, contador);
				n += contador;
				if(cadena[n] != ')')
					variable_exponente = cadena[n];
			}
		}
		else if (isalpha(cadena[n])){
			exponente = "1";
			variable_exponente = cadena[n];
		}
		else if(isdigit(cadena[n]))
			exponente = cadena.substr(n,cadena.size()-n);
	}
	else
		exponente = "1";
}

char Variable::get_variable(){
	return variable;
}

void Variable::set_variable(char variable){
	this->variable = variable;
}

std::string Variable::get_exponente(){
	return exponente;
}

void Variable::set_exponente(std::string exponente){
	this->exponente = exponente;
}

char Variable::get_variable_exponente(){
	return variable_exponente;
}

void Variable::set_variable_exponente(char variable_exponente){
	this->variable_exponente = variable_exponente;
}

std::string Variable::get_numero(){
	return numero;
}

void Variable::set_numero(std::string numero){
	this->numero = numero;
}

std::string Variable::get_cadena_variable(){
	std::string cadena;

	if (variable)
		cadena = variable;
	else
		cadena = numero;
	if (exponente.size() > 0 && variable_exponente && exponente != "1"){
		cadena = cadena + "^(";
		if (exponente == "-1")
			cadena = cadena + "-";
		else
			cadena = cadena + exponente;
		cadena = cadena + variable_exponente + ")";
	}
	else if (variable_exponente)
		cadena = cadena + "^" + variable_exponente;
	else if (exponente.size() > 0){
		if (exponente[0] == '-')
			cadena = cadena + "^(" + exponente + ")";
		else if (exponente != "1")
			cadena = cadena + "^" + exponente;
	}
	else if (exponente == "0")
		cadena = "1";

	return cadena;
}

double Variable::evaluar_variable(std::vector<char> variables, std::vector<double> valores){
	double resultado{};
	
	for(size_t i {};i < variables.size();i++){
		if(variable&&variable_exponente){
			if(variable == variables[i]){
				for(size_t j{};j < variables.size();j++){
					if(variable_exponente == variables[i]){
						resultado = pow(valores[i],stoi(exponente) * valores[j]);
						break;
					}
				}
				break;
			}
		}
		else if(variable){
			if(variable == variables[i]){
				resultado = pow(valores[i],stoi(exponente));
				break;
			}
		}
		else if(variable_exponente){
			if(variable_exponente == variables[i]){
				if(numero == "e")
					resultado = exp(stoi(exponente) * valores[i]);
				else 
					resultado = pow(stod(numero), stoi(exponente) * valores[i]);
				break;
			}
		}
	}

	return resultado;
}

std::string Variable::derivar_variable(){
	std::string cadena;
	
	if(variable){
		int exponente {stoi(this->exponente) - 1};
		
		cadena = variable;
		if(exponente == 0)
			cadena = "1";
		else if(exponente != 1)
			cadena = cadena + "^" + std::to_string(exponente);
	}
	else if(variable_exponente){
		if(numero == "e")
			cadena = get_cadena_variable();
		
	}

	return cadena;
}
