#ifndef _MONOMIO_H_
#define _MONOMIO_H_

#include <string>
#include <vector>
#include "Variable.h"

class Monomio {
private:
    std::string literal;
    std::vector<Variable> variables;

public:
    Monomio(std::string);

    std::string get_literal();
    void set_literal(std::string);

    std::string get_cadena_monomio();
	double evaluar_monomio(std::vector<char>, std::vector<double>);
    
    std::string derivar_monomio(char);
};
#endif
