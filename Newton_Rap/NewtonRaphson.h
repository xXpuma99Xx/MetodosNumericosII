#include <iostream>
#include <vector>
#include <iomanip>

#include "Matriz.h"
#include "Funcion.h"

#ifndef NEWTON_RAPHSON_H
#define NEWTON_RAPHSON_H

using namespace std;

class NewtonRaphson {
    private:
    vector<Funcion> funciones {};
    vector<string> variables {};

    public:
    NewtonRaphson (vector<string> valorFunciones, vector<string> valorVariables) {

        for(int i = 0;i < (int) valorFunciones.size();i++){
            Funcion auxFuncion {valorFunciones[i]};
            funciones.push_back(auxFuncion);
        }

        variables = valorVariables;
    }

    void resolverSisterma (double errorRequerido, int iteracionesMaximas,vector<double> valoresIniciales) {
        vector<double> valores {};
            valores = valoresIniciales;

        for(int i = 0; i < iteracionesMaximas;i++){
            vector<vector<double>> valoresMatriz {};
            vector<double> fxyz {};
            vector<double> jaco_fxyz {};
            vector<vector<double>> auxMatriz {};

            cout<<"Iteracion: " << i<<endl;
            imprimirVector(valores);
            for(int j = 0;j < (int) funciones.size();j++){
                vector<double> auxVector {};

                fxyz.push_back(funciones[j].evaluar(variables,valores));
                for(int k = 0;k < (int) variables.size();k++){
                    Funcion derivadaParcial {funciones[j].derivar(variables[k])};
                    auxVector.push_back(derivadaParcial.evaluar(variables,valores));
                }
                auxMatriz.push_back(auxVector);
            }

            Matriz jacobiana {auxMatriz};

            for(int j = 0;j < (int) jacobiana.matrizCuadrada.size();j++){
                double resultado {};
                for(int k = 0;k < (int) fxyz.size();k++)
                    resultado += jacobiana.inversa[j][k] * fxyz[k];
                
                jaco_fxyz.push_back(resultado);
            }

            for(int j = 0;j < (int) valores.size();j++)
                valores[j] -= jaco_fxyz[j];

            imprimirVector(fxyz);
            imprimirMatriz(jacobiana.matrizCuadrada);
            imprimirMatriz(jacobiana.inversa);
            imprimirVector(jaco_fxyz);
            imprimirVector(valores);

            if(i > 0){
                double error {};
                for(int j = 0; j < (int) jaco_fxyz.size();j++){
                    if(jaco_fxyz[j] > error)
                        error = jaco_fxyz[j];
                }
                cout << error<<endl;

                if(error == 0||error < errorRequerido)
                    break;
            }
        }
    }


    void imprimirMatriz(vector<vector<double>> m) {
        for(int i = 0; i < (int) m.size() ;i++){
            for(int j = 0; j < (int) m.size();j++)
                cout << "+-----------";
            cout<<"+"<<endl;
            for(int j = 0; j < (int) m[i].size();j++){
                cout << setprecision(8);
                cout << "|"<< m[i][j] << " ";
            }
            cout << "|"<<endl;
        }
        for(int j = 0; j < (int) m.size();j++)
            cout << "+-----------";
        cout<<"+"<<endl<<endl;
    }

    void imprimirVector(vector<double> v) {
        for(int i = 0;i < (int) v.size(); i++){
            cout << setprecision(8);
            cout << "+-----------+"<<endl<< "|"<<v[i]<<"|"<<endl;
        }
        cout << "+-----------+" <<endl<<endl;
    }
};

#endif