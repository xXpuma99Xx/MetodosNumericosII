#include <iostream>
#include <vector>

#include "Monomio.h"

#ifndef FUNCION_H
#define FUNCION_H

using namespace std;

class Funcion {
    private:
    vector<Monomio> terminos {};
    double constante {};

    public:
    Funcion (string funcion) {
        int i {};
        int j {};
        vector<string> terminosAux {};

        for(i = 0;i < (int) funcion.size();i++){
            int contador {1};

            for(j = i;j < (int) funcion.size();j++){
                if(funcion[j] == ' ')
                    break;
                contador++;
            }
            terminosAux.push_back(funcion.substr(i,contador-1));
            i += contador-1;
        }
    
        for(i = 0;i < (int) terminosAux.size();i++){
            int j {0};
            double valorLiteral {};
            vector<string> valorVariables {};
            vector<int> valorExponentes {};

            if(isdigit(terminosAux[i][j+1])){
                int contador {2};
                int k {};

                for(k = j + 2;k < (int) terminosAux[i].size();k++){
                    if(!isdigit(terminosAux[i][k]))
                        break;
                    contador++;
                }

                if(k == (int) terminosAux[i].size())
                    constante = stod(terminosAux[i].substr(j,contador));
                else 
                    valorLiteral = stod(terminosAux[i].substr(j,contador));
                
                j += contador;
            }
            else{
                if(terminosAux[i][j] == '+')
                    valorLiteral = 1;
                else 
                    valorLiteral = -1;
                j++;
            }
            
            if(constante == 0){
                for(int k = j; k < (int) terminosAux[i].size();k++){
                    valorVariables.push_back(terminosAux[i].substr(k,1));

                    if(terminosAux[i][k+1] == '^'){
                        int contador {1};

                        for(int l = k + 3;l < (int) terminosAux[i].size();l++){
                            if(!isdigit(terminosAux[i][l]))
                                break;
                            contador++;
                        }

                        valorExponentes.push_back(stoi(terminosAux[i].substr(k + 2,contador)));

                        k += contador + 1;
                    }
                    else 
                        valorExponentes.push_back(1);
                }

                Monomio termino {valorLiteral,valorVariables,valorExponentes};
                terminos.push_back(termino);
            }
        }
    }

   double evaluar(vector<string> var, vector<double> valores){
        double resultado {};
        
        for(int i = 0;i < (int) terminos.size();i++){
            resultado += terminos[i].evaluar(var,valores);
        }
        
        resultado += constante;
        return resultado;
    }

    string cadena (){
        string cadena {""};
        
        for(int i = 0;i < (int) terminos.size();i++){
            if(i == ((int) terminos.size()) - 1)
                cadena += terminos[i].cadena();
            else
                cadena += terminos[i].cadena() + " ";
        }

        if(constante == 0.0)
            cadena += "";
        else if(constante < 0.0)
            cadena += " " + to_string((int) constante);
        else if(constante > 0.0)
            cadena += " +" + to_string((int) constante);

        return cadena;
    }

    string derivar (string var){
        string cadena {""};
    
        for(int i = 0;i < (int) terminos.size();i++){
            if(terminos[i].derivar(var) != ""){
                if(i + 1 == (int) terminos.size())
                    cadena += terminos[i].derivar(var);
                else
                    cadena += terminos[i].derivar(var) + " ";
            }
        }
        
        return cadena;
    }
};

#endif