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
    string funcion1 {"+x^2 +xy -10"};
    string funcion2 {"+3xy^2 +y -50"};
    Funcion fx1 {funcion1,2};
    Funcion fx2 {funcion2,2};

    cout << fx1.cadena() << " " << (fx1.cadena() == funcion1) << " " << fx1.derivar("y") << endl;
    cout << fx2.cadena() << " " << (fx2.cadena() == funcion2) << " " << fx2.derivar("y") << endl;


}

void dos () {
    // Funcion funcion1 {"+x^2 +y^2 -9",2};
    // Funcion funcion2 {"+x^2 +xy -10",2};
}

void tres () {
    string funcion1 {"+2x^2 -4x +y^2 +3z^2 +6z +2"};
    string funcion2 {"+x^2 +y^2 -2y +2z^2 -5"};
    string funcion3 {"+3x^2 -12x +y^2 -3z^2 +8"};
    Funcion fx1 {funcion1,3};
    Funcion fx2 {funcion2,3};
    Funcion fx3 {funcion3,3};

    cout << fx1.cadena() << " " << (fx1.cadena() == funcion1) << " " << fx1.derivar("z") << endl;
    cout << fx2.cadena() << " " << (fx2.cadena() == funcion2) << " " << fx2.derivar("z") << endl;
    cout << fx3.cadena() << " " << (fx3.cadena() == funcion3) << " " << fx3.derivar("z") << endl;
}

void cuatro () {
    string funcion1 {"+x^2 -4x +y^2"};
    string funcion2 {"+x^2 -x -12y +1"};
    string funcion3 {"+3x^2 -12x +y^2 -3z^2 +8"};
    Funcion fx1 {funcion1,3};
    Funcion fx2 {funcion2,3};
    Funcion fx3 {funcion3,3};

    cout << fx1.cadena() << " " << (fx1.cadena() == funcion1) << " " << fx1.derivar("z") << endl;
    cout << fx2.cadena() << " " << (fx2.cadena() == funcion2) << " " << fx2.derivar("z") << endl;
    cout << fx3.cadena() << " " << (fx3.cadena() == funcion3) << " " << fx3.derivar("z") << endl;
}

int main() {
    int r {};
    // string funcion {"x^2+xy-10"};
    // int n {2};
    // Funcion a {funcion, n};
    // cout << boolalpha;
    // cout << (funcion == a.cadena()) << " " << a.cadena() << endl << a.derivar("x")<< endl;
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