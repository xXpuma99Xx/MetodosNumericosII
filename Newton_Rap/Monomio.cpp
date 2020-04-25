#include "Monomio.h"

Monomio::Monomio(std::string cadena){
    unsigned n{};

    if(isdigit(cadena[n])){
        unsigned contador{};
            
        for(size_t i {n};i < cadena.size();i++){
            if(!isdigit(cadena[i])) break;
            contador++;
        }
        literal = cadena.substr(n,contador);
        n += contador;
    }
    else if(cadena[n] == '-'||cadena[n] == '+'){
        if(isalpha(cadena[n+1])){
            if(cadena[n] == '-')
                literal = "-1";
            else if(cadena[n] == '+')
                literal = "1";
            n++;
        }
        else if(isdigit(cadena[n+1])){
            unsigned contador{1};
            
            for(size_t i {n+1};i < cadena.size();i++){
                if(!isdigit(cadena[i])) break;
                contador++;
            }
            if(cadena[n] == '-')
                literal = cadena.substr(n,contador);
            if(cadena[n] == '+')
                literal = cadena.substr(n+1,contador-1);
            n += contador;
        }
    }
    else if(isalpha(cadena[n]))
        literal = "1";

    for(size_t i{n};i < cadena.size();i++){
        unsigned contador {};

        if(cadena[i+1] == '^'&&cadena[i+2] == '('){
            for(size_t j {i};j < cadena.size();j++){
                contador++;
                if(cadena[j] == ')') break;
            }
        }
        else if(cadena[i+1] == '^'){
            if(isalpha(cadena[i+2]))
                contador = 3;
            else if(isdigit(cadena[i+2])){
                contador = 2;
                for(size_t j {i+2};j < cadena.size();j++){
                    if(!isdigit(cadena[j])) break;
                    contador++;
                }
            }
        }
        else
            contador = 1;

        Variable variable_aux {cadena.substr(i,contador)};

        variables.push_back(variable_aux);
        i += contador - 1 ;
    }
}

std::string Monomio::get_literal(){
    return literal;
}

void Monomio::set_literal(std::string literal){
    this->literal = literal;
}

std::string Monomio::get_cadena_monomio(){
    std::string cadena;

    if(literal == "-1")
        cadena = "-";
    else if(literal != "1")
        cadena = literal;

    for(size_t i {};i < variables.size();i++)
        cadena += variables[i].get_cadena_variable();

    if(literal == "0")
        cadena = "";

    return cadena;
}

double Monomio::evaluar_monomio(std::vector<char> variables, std::vector<double> valores){
    double resultado {1};

    for(size_t i {};i < this->variables.size();i++)
        resultado *= this->variables[i].evaluar_variable(variables,valores);

    resultado *= stod(literal);
    return resultado;
}

std::string Monomio::derivar_monomio(char parcial){
    std::string cadena;
    int n {-1};

    for(size_t i {};i < variables.size();i++){
        if(variables[i].get_variable() == parcial||
        (variables[i].get_numero() == "e" &&variables[i].get_variable_exponente() == parcial)){
            std::string aux {variables[i].derivar_variable()};

            if(aux != "1"){
                cadena += aux;
                
            }

            n = i;
        }
        else 
            cadena += variables[i].get_cadena_variable();
    }

    if(n == -1)
        cadena = "";
    else {
        int literal_derivada;

        if(variables[n].get_numero() == "e")
            literal_derivada = stoi(literal);
        else
            literal_derivada = stoi(variables[n].get_exponente()) * stoi(literal);
        
        if(literal_derivada < 0){
            if(literal_derivada == -1){
                if(cadena.size() == 0)
                    cadena = "-1";
                else
                    cadena = "-" + cadena;
            }
            else 
                cadena = std::to_string(literal_derivada) + cadena;
        }
        else if(literal_derivada > 0){
            if(cadena.size() == 0&&literal_derivada == 1)
                cadena = "1";
            else if(literal_derivada != 1)
                cadena = std::to_string(literal_derivada) + cadena;
        }
    }
    return cadena;
}