#include <iostream>
#include <string>
#include <vector>
#include "Funciones.hpp"
#include "Diferencias_Divididas.hpp"
#include "Spline_Cubico.hpp"

std::vector<std::vector<double>> capturar_vectores();
void menu_metodos(std::vector<double> x, std::vector<double> fx);
int cambiar_numero(const std::vector<double> &vect, std::string nombre);

int imprimir_menu(std::vector<std::string> opciones);
bool si_no(std::string texto);
bool numero(std::string cadena);

void metodo_diferencias_divididas(std::vector<double>, std::vector<double>);
void metodo_spline_cubico(std::vector<double>, std::vector<double>);

void nombres();
void borrar_pantalla();
void no_valido(bool borrar = false);

template<typename T>
T mientras_no_sea_numero(std::string texto, bool borrar = true) {
	std::string respuesta;

	do {
		std::cout << texto;
		std::cin >> respuesta;
		if (!numero(respuesta))
			no_valido(borrar);
	} while (!numero(respuesta));

	return static_cast<T>(stod(respuesta));
}


int main(){
	bool repetir {};
	std::vector<std::vector<double>> vectores;

	do{
		vectores = capturar_vectores();
		menu_metodos(vectores[0],vectores[1]);
		repetir = si_no("¿Desea repetir?[s/n]: ");
	}while(repetir);
	
	return 0;
}

std::vector<std::vector<double>> capturar_vectores() {
	std::vector<double> x;
	std::vector<double> fx;
	int n{};
	std::string menu {"¿Cuantos valores desea insertar? "};
	
	do {
		n = mientras_no_sea_numero<int>(menu);
		if (n < 1)
			no_valido(true);
	} while (n < 1);
	borrar_pantalla();
	for (int i{}; i < n; i++) {
		menu = "x[" + std::to_string(i) + "]: ";
		double sub_indice{mientras_no_sea_numero<double>(menu)};
		x.push_back(sub_indice);
		menu = "f(" + std::to_string(sub_indice) + ") = ";
		fx.push_back(mientras_no_sea_numero<double>(menu));
		std::cout << std::endl;
	}
	borrar_pantalla();
	bool seguir {};
	do {
		std::vector<std::vector<double>> imprimir{x, fx};
		std::vector<std::string> nombres{"x", "f(x)"};

		menu = imprimir_vectores(imprimir, nombres) + "¿Estan correctos todos estos datos? [s/n]: ";
		seguir = si_no(menu);
		borrar_pantalla();
		if (!seguir) {
			std::vector<std::string> opciones{"Cambiar un dato de x","Cambiar un dato de f(x)"};
			int r {imprimir_menu(opciones)};
			int opcion{};

			borrar_pantalla();
			if (r == 1) {
				opcion = cambiar_numero(x, "x");
				x[opcion] = mientras_no_sea_numero<double>("x[" + std::to_string(opcion) + "]: ");
			}
			if (r == 2) {
				opcion = cambiar_numero(fx, "f(x)");
				fx[opcion] = mientras_no_sea_numero<double>("f(" + std::to_string(x[opcion]) + ") = ");
			}
		}
	} while (!seguir);

	std::vector<std::vector<double>> vecotres {x,fx};
	return vecotres;
}

void menu_metodos(std::vector<double> x, std::vector<double> fx) {
	std::vector<std::string> opciones {"Diferencias Divididas","Ajuste de curvas"};
	int r {imprimir_menu(opciones)};

	switch(r){
		case 1: metodo_diferencias_divididas(x, fx);
			break;
		case 2: metodo_spline_cubico(x, fx);
			break;
		case 3:
			break;
	}
}

void metodo_diferencias_divididas(std::vector<double> vect_x, std::vector<double> vect_fx) {
	Diferencias_Divididas diferencias{vect_x, vect_fx};
	bool repetir {};

	do {
		std::cout << diferencias.imprimir_tabla() << std::endl;
		std::cout << diferencias.imprimir_potencias(mientras_no_sea_numero<double>("Inserte un numero para encontrar su valor: "));

		repetir = si_no("¿Quieres bucar otro número? [s/n]: ");
	} while (repetir);
}

void metodo_spline_cubico(std::vector<double> vect_x, std::vector<double> vect_fx) {
	Spline_Cubico spline {vect_x, vect_fx};

	borrar_pantalla();
	std::cout << spline.imprimir_todas() << std::endl;
	std::cout << spline.matriz_rectangular.imprimir_tabla_transpuesta() << std::endl;
	std::cout << spline.matriz_cuadrada.imprimir_tabla_matriz() << std::endl;
	std::cout << spline.matriz_cuadrada.imprimir_tabla_inversa() << std::endl;
	std::cout << spline.coeficientes() << std::endl;
}

bool si_no(std::string texto){
	std::string respuesta;

	do{
		std::cout << texto;
		std::cin >> respuesta;
		for (size_t i{}; i < respuesta.size(); i++)
			respuesta[i] = tolower(respuesta[i]);
		if(respuesta !=	"s"&&respuesta != "n")
			no_valido(true);
	}while(respuesta !=	"s"&&respuesta != "n");
	if(respuesta == "n")
		return false;
	return true;
}

int imprimir_menu(std::vector<std::string> opciones){
	int r;
	std::string menu;
	
	for(size_t i{};i < opciones.size();i++)
			menu += (std::to_string(i+1) + ") " + opciones[i] + "\n");
	menu += "\nElige una opcion: ";
	do{
		r = mientras_no_sea_numero<int>(menu);
		if(r < 1||r > static_cast<int>(opciones.size()))
			no_valido(true);
	} while(r < 1||r > static_cast<int>(opciones.size()));

	return r;
}

int cambiar_numero(const std::vector<double> &vect, std::string nombre) {
	std::string menu {imprimir_vector(vect, nombre, true) + "\nElige una opcion: "};
	int opcion{};
	int maximo{static_cast<int>(vect.size())};

	do {
		opcion = mientras_no_sea_numero<int>(menu);
		if (opcion < 0 || opcion >= maximo)
			no_valido(true);
	} while (opcion < 0 || opcion >= maximo);

	return opcion;
}


bool numero(std::string cadena) {
	bool punto{false};

	for (size_t i{}; i < cadena.size(); i++) {
		if (i == 0 && (cadena[i] == '-' || cadena[i] == '+'))
			;
		else if (cadena[i] == '.') {
			if (punto == true)
				return false;
			punto = true;
		}
		else if (!isdigit(cadena[i]))
			return false;
	}

	return true;
}

void no_valido(bool borrar) {
	if (borrar)
		borrar_pantalla();
	std::cout << "Ingreso una opcion no valida. Intente de nuevo" << std::endl << std::endl;
}

void borrar_pantalla() {
	// system("cls");
	system("clear");
}

