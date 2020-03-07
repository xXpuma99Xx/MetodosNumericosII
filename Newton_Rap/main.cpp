#include <iostream>
#include <vector>
#include "Funcion.h"

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
    vector<string> funcion {"+x^2 +xy -10" ,"+3xy^2 +y -50"};
    vector<Funcion> fxy {{funcion[0]},{funcion[1]}};

    for(int i = 0;i < (int) fxy.size();i++){
        cout << fxy[i].cadena() << " " << (fxy[i].cadena() == funcion[i]) << " " << fxy[i].derivar("y") << endl;
    }
}

void dos () {
    // Funcion funcion1 {"+x^2 +y^2 -9",2};
    // Funcion funcion2 {"+x^2 +xy -10",2};
}

void tres () {
    vector<string> funcion {"+2x^2 -4x +y^2 +3z^2 +6z +2", "+x^2 +y^2 -2y +2z^2 -5", "+3x^2 -12x +y^2 -3z^2 +8"};
    vector<Funcion> fxyz {{funcion[0]}, {funcion[1]}, {funcion[2]}};

    for(int i = 0;i < (int) fxyz.size();i++){
        cout << fxyz[i].cadena() << " " << (fxyz[i].cadena() == funcion[i]) << " " << fxyz[i].derivar("y") << endl;
    }
}

void cuatro () {
    vector<string> funcion {"+x^2 -4x +y^2", "+x^2 -x -12y +1", "+3x^2 -12x +y^2 -3z^2 +8"};
    vector<Funcion> fxyz {{funcion[0]}, {funcion[1]}, {funcion[2]}};

    for(int i = 0;i < (int) fxyz.size();i++){
        cout << fxyz[i].cadena() << " " << (fxyz[i].cadena() == funcion[i]) << " " << fxyz[i].derivar("y") << endl;
    }
}

int main() {
    int r {};
    cout<<boolalpha;
    nombres();
    do{
        r = menu();
        switch(r){
            case 1: uno();
                break;
            case 2: dos();
                break;
            case 3: tres();
                break;
            case 4: cuatro();
                break;
        }
    }while (r != 5);

    
    return 0;
}