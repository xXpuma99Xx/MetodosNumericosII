#include <iostream>
#include <vector>

#ifndef MATRIZ_H
#define MATRIZ_H

using namespace std;

class Matriz {
    public:
    vector<vector<double>> matrizCuadrada {};
    vector<vector<double>> inversa {};

    Matriz(vector<vector<double>> valorMatriz){
        matrizCuadrada = valorMatriz;
        inversaMatriz();
    }

    void inversaMatriz(){
        vector<vector<double>> auxMatriz {matrizCuadrada};
        vector<vector<double>> matrizIdentidad {};

        for(int i = 0;i < (int) auxMatriz.size();i++){
            vector<double> auxVector {};
            for(int j = 0;j < (int) auxMatriz[i].size();j++){
                if(i == j)
                    auxVector.push_back(1.0);
                else 
                    auxVector.push_back(0.0);
            }
            matrizIdentidad.push_back(auxVector);
        }

        for(int i = 0;i < (int) auxMatriz.size();i++){
            if(auxMatriz[i][i] == 0){
                for(int j = i + 1;j < (int) auxMatriz[i].size();j++){
                    if(auxMatriz[j][i] != 0){
                        vector<double> auxVector {auxMatriz[i]};

                        auxMatriz[i] = auxMatriz[j];
                        auxMatriz[j] = auxVector;
                        
                        auxVector = matrizIdentidad[i];
                        matrizIdentidad[i] = matrizIdentidad[j];
                        matrizIdentidad[j] = auxVector;
                        break;
                    }
                }
            }
        
            double divisor {auxMatriz[i][i]};
            for(int j = 0;j < (int) auxMatriz[i].size();j++){
                auxMatriz[i][j] /= divisor;
                matrizIdentidad[i][j] /= divisor;
            }
            
            for(int j = 0;j < (int) auxMatriz.size();j++){                
                double numero {auxMatriz[j][i]};
                for(int k = 0;k < (int) auxMatriz[i].size();k++){
                    if(j != i){
                        auxMatriz[j][k] += (-1) * numero * auxMatriz[i][k];
                        matrizIdentidad[j][k] += (-1) * numero * matrizIdentidad[i][k];
                    }
                }
            }
        }
        inversa = matrizIdentidad;
    }
};

#endif