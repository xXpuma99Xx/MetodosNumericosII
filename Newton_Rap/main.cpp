#include <iostream>
#include <vector>
#include "Funcion.h"
#include "Matriz.h"

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

void uno () {
    vector<string> funcion {"+x^2 +xy -10" ,"+y +3xy^2 -50"};
    vector<Funcion> fxy {{funcion[0]},{funcion[1]}};
    vector<string> var {"x","y"};
    vector<double> valores {-2,-2};
}

void dos () {
    vector<string> funcion {"+x^2 +y^2 -9" ,"-e^x -2y -3"};
    vector<Funcion> fxy {{funcion[0]},{funcion[1]}};
    vector<string> var {"x","y"};
    vector<double> valores {1,1};
}

void tres () {
    vector<string> funcion {"+2x^2 -4x +y^2 +3z^2 +6z +2", "+x^2 +y^2 -2y +2z^2 -5", "+3x^2 -12x +y^2 -3z^2 +8"};
    vector<Funcion> fxyz {{funcion[0]}, {funcion[1]}, {funcion[2]}};
    vector<string> var {"x","y","z"};
    vector<double> valores {-2,-2,-2};
}

void cuatro () {
    vector<string> funcion {"+x^2 -4x +y^2", "+x^2 -x -12y +1", "+3x^2 -12x +y^2 -3z^2 +8"};
    vector<Funcion> fxyz {{funcion[0]}, {funcion[1]}, {funcion[2]}};
}

int main() {
    // int r {};
    // nombres();

    // do{
    //     r = menu();
    //     switch(r){
    //         case 1: uno();
    //             break;
    //         case 2: dos();
    //             break;
    //         case 3: tres();
    //             break;
    //         case 4: cuatro();
    //             break;
    //     }
    // }while (r != 5);

    vector<vector<double>> ejemplo {
        {-1.1111111111111, -4 ,6.66666666666667 },
        {1.44444444444444,-6,0.444444444444446},
        {-7.66666666666667,-4,0.666666666666668}
    };
    Matriz matrizEjemplo {ejemplo};
    matrizEjemplo.inversaMatriz();
    return 0;
}