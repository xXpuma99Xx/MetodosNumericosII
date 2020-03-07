#include <iostream>
#include <vector>

#include "VariableIndependiente.h"

#ifndef MONOMIO_H
#define MONOMIO_H

class Monomio{
    private:
    double literal {};
    vector<VariableIndependiente> variables;

    public:
    Monomio(double valorLiteral, vector<string> valorVariables, vector<int> valorExponentes){
        int length {};

        length = valorExponentes.size();
        for(int i = 0; i < length; i++){
            VariableIndependiente aux {valorVariables[i],valorExponentes[i]};

            variables.push_back(aux);
        }

        literal = valorLiteral;
    }

    int getLiteral(){
        return literal;
    }

    void setLiteral(int literalNuevo){
        literal = literalNuevo;
    }

    double evaluar(vector<double> valores){
        double resultado {1};
        int length {};
        
        length = variables.size();
        for(int i = 0;i < length;i++){
            if(variables[i].getVariable() != "")
                resultado *= variables[i].evaluar(valores[i]);
        }
        
        resultado *= literal;
        return resultado;
    }

    string derivar(string var){
        string cadena {};
        int contador {};
        double literalDerivada {};

        for(int i = 0; i < (int) variables.size();i++){
            if(variables[i].getVariable() == var){
                VariableIndependiente derivada {var, (variables[i].getExponente() - 1)};

                contador ++;
                literalDerivada = literal * variables[i].getExponente();
                cadena += derivada.cadena();
            }
            else 
                cadena += variables[i].cadena();
        }

        if(literalDerivada == 1){
            if(cadena.size() == 0)
                cadena = "+1";
            else 
                cadena = "+" + cadena;
        }
        else if(literalDerivada == -1){
            if(cadena.size() == 0)
                cadena = "-1";
            else 
                cadena = "-" + cadena;
        }
        else if(literalDerivada < 0)
            cadena = to_string((int) literalDerivada) + cadena;
        else if(literalDerivada > 0)
            cadena = "+" + to_string((int) literalDerivada) + cadena;
        
        if(contador == 0){
            return "";
        }
        return cadena;
    }

    string cadena (){
        string cadena {""};

        if(literal == -1)
            cadena += "-";
        else if(literal == 1)
            cadena += "+";
        else if(literal < 0)
            cadena += to_string((int) literal);
        else if(literal > 0)
            cadena += "+" + to_string((int) literal);
        
        for(int i = 0;i < (int) variables.size();i++)
            cadena += variables[i].cadena();
            
        return cadena;
    }
};

#endif