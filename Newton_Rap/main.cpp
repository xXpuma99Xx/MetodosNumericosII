#include <iostream>
#include <vector>
#include "Funcion.h"
#include "NewtonRaphson.h"

void nombres () {
    cout <<"Navarro Ramos Karen"<<endl;
    cout <<"Gómez González Astrid"<<endl;
    cout <<"Márquez Rosas Lemuel Helon"<<endl;
}

int menu() {
    int respuesta {};
    cout <<"\t\t.:Menu:."<<endl;
    cout <<"1) Conjunto Uno"<<endl;
    cout <<"2) Conjunto Dos"<<endl;
    cout <<"3) Conjunto Tres"<<endl;
    cout <<"4) Conjunto Cuatro"<<endl;
    cout <<"5) Salir"<<endl;

    cout <<endl <<"Escoje una opcion: ";
    cin >> respuesta;

    return respuesta;
}

int main() {
    int r {};
    nombres();

    do{
        vector<string> funcion {};
        vector<string> var {};
        vector<double> valoresIniciales {};
        string aux {};
        int iteraciones {};
        double error {};

        r = menu();
        switch(r){
            case 1: 
                funcion.push_back("+x^2 +xy -10");
                funcion.push_back("+y +3xy^2 -50");
                var.push_back("x");
                var.push_back("y");
                break;
            case 2: 
                var.push_back("x");
                var.push_back("y");
                break;
            case 3: 
                funcion.push_back("+2x^2 -4x +y^2 +3z^2 +6z +2");
                funcion.push_back("+x^2 +y^2 -2y +2z^2 -5");
                funcion.push_back("+3x^2 -12x +y^2 -3z^2 +8");
                var.push_back("x");
                var.push_back("y");
                var.push_back("z");
                break;
            case 4: 
                funcion.push_back("+x^2 -4x +y^2");
                funcion.push_back("+x^2 -x -12y +1");
                funcion.push_back("+3x^2 -12x +y^2 -3z^2 +8");
                var.push_back("x");
                var.push_back("y");
                var.push_back("z");
                break;
        }

        NewtonRaphson newton {funcion,var};


        for(int i = 0;i < (int) var.size();i++){
            cout<< "Interte el valor inicial de " << var[i]<< ": ";
            cin>> aux;
            valoresIniciales.push_back(stod(aux));
        }

        cout << "Numero maximo de iteraciones que debe realizar el programa: ";
        cin >> aux;
        iteraciones = stoi(aux);
        cout << "Error minimo permitido: ";
        cin >> aux;
        error = stod(aux);

        
        newton.resolverSisterma(error,iteraciones,valoresIniciales);
    }while (r != 5);

    return 0;
}