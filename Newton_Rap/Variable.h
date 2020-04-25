#ifndef _VARIABLE_H_
#define _VARIABLE_H_

#include <string>
#include <vector>

class Variable{
private:
	char variable{};
	char variable_exponente{};
	std::string exponente;
	std::string numero;

public:
	Variable(std::string);

	char get_variable();
	void set_variable(char);

	std::string get_exponente();
	void set_exponente(std::string);

	char get_variable_exponente();
	void set_variable_exponente(char);

	std::string get_numero();
	void set_numero(std::string);

	std::string get_cadena_variable();
	double evaluar_variable(std::vector<char>, std::vector<double>);

	std::string derivar_variable();
};
#endif
