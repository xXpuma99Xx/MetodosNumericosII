#include <iostream>
#include <vector>
#include <cmath>

#ifndef VARIABLE_INDEPENDIENTE_H
#define VARIABLE_INDEPENDIENTE_H

using namespace std;

class VariableIndependiente{
    private:
    //Atributos
    string variable {};
    int exponente {};

    public:
    //Constructores
    VariableIndependiente(string valorVariable, int valorExponente){
        variable = valorVariable;
        exponente = valorExponente;
    }

    //Métodos
    int getExponente(){
        return exponente;
    }

    void setExponente(int exponenteNuevo){
        exponente = exponenteNuevo;
    }

    string getVariable(){
        return variable;
    }

    void setVariable(string variableNueva){
        variable = variableNueva;
    }

    double evaluar(double valor){
        if(exponente == 0)
            return 1;
        return pow(valor,exponente);
    }

    string cadena(){  
        if(exponente == 0) 
            return ""; 
        else if(exponente == 1)
            return variable;
        else
            return variable + "^" + to_string(exponente);
    }
};

#endif