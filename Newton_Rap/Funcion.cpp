#include "Funcion.h"
#include <iostream>

Funcion::Funcion(std::string cadena){
    for(size_t i{};i < cadena.size();i++){
        unsigned contador {1};

        for (size_t j {i+1}; j < cadena.size(); j++) {
            if(cadena[j] == '-'||cadena[j] == '+') break;
            contador++;
        }

        Monomio aux {cadena.substr(i,contador)};

        monomios.push_back(aux);
        i += contador - 1;
    }
}

std::string Funcion::get_constante(){
    return constante;
}

void Funcion::set_constante(std::string constante){
    this->constante = constante;
}

std::string Funcion::get_cadena_funcion(){
    std::string cadena;

    for(size_t i{};i < monomios.size();i++){
        std::string aux {monomios[i].get_cadena_monomio()};

        if(i == 0||cadena[0] == '-')
            cadena += aux;
        else 
            cadena += "+" + aux;
    }
    
    if(constante.size() > 0){
        if(constante[0] == '-'||cadena.size() == 0)
            cadena += constante;
        else
            cadena += "+" + constante;
    }
    return cadena;
}

double Funcion::evaluar_funcion(std::vector<char>, std::vector<double>){
    double resultado {};

    return resultado;
}