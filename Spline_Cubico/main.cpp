#include <iostream>
#include <string>
#include <vector>
#include "Diferencias_Divididas.hpp"
#include "Funciones.hpp"
#include "Matriz.hpp"
#include "Spline_Cubico.hpp"

void nombres();
void borrar_pantalla();
void metodo_numerico_diferencias(std::vector<double>, std::vector<double>);
void metodo_numerico_spline(std::vector<double>, std::vector<double>);
void no_valido(bool borrar = true);
void capturar_vectores();
std::string mientras_no_sea_numero(std::string, bool borrar = true);
std::string si_no(std::string, bool borrar = true);
int cambiar_numero(const std::vector<double> &, std::string);
bool numero(std::string);
void lower(std::string &);

int main() {
	std::vector<double> x{426.69, 483.3, 497.81, 568.92, 995.61, 1422.3, 2133.45, 3555.75, 4266.9, 7111.5};
	std::vector<double> fx{2468, 2482, 2483, 2498, 2584, 2672, 2811, 3094, 3236, 3807};
	Spline_Cubico ejemplo {x,fx};
	
	std::cout << ejemplo.imprimir_todas() << std::endl;
	std::cout << ejemplo.matriz_rectangular.imprimir_tabla_transpuesta() << std::endl;
	std::cout << ejemplo.matriz_cuadrada.imprimir_tabla_matriz() << std::endl;
	std::cout << ejemplo.matriz_cuadrada.imprimir_tabla_inversa() << std::endl;
	//std::string respuesta;

	//nombres();
	//do {
		//capturar_vectores();
		//respuesta = si_no("¿Quieres repetir el programa? [s/n]: ");
	//} while (respuesta == "s");

	return 0;
}

void capturar_vectores() {
	int n{};
	std::string aux;
	std::vector<double> x;
	std::vector<double> fx;

	do {
		n = stoi(mientras_no_sea_numero("\n¿Cuantos valores desea insertar? "));
		if (n < 1)
			no_valido();
	} while (n < 1);
	borrar_pantalla();
	for (int i{}; i < n; i++) {
		std::string sub_indice{mientras_no_sea_numero("x[" + std::to_string(i) + "]: ")};
		x.push_back(stod(sub_indice));
		fx.push_back(stod(mientras_no_sea_numero("f(" + sub_indice + ") = ")));
		std::cout << std::endl;
	}
	borrar_pantalla();
	do {
		std::vector<std::vector<double>> imprimir {x,fx};
		std::vector<std::string> nombres {"x", "f(x)"};

		std::cout << imprimir_vectores(imprimir, nombres) << std::endl;
		aux = si_no("¿Estan correctos todos estos datos? [s/n]: ", false);
		borrar_pantalla();
		if (aux == "n") {
			std::string aux2;
			int opcion{};

			do {
				std::cout << "1)Cambiar un dato de x\n2)Cambiar un dato de f(x)\n\nElige una opcion: ";
				std::cin >> aux2;
				if (aux2 != "1" && aux2 != "2")
					no_valido();
			} while (aux2 != "1" && aux2 != "2");
			borrar_pantalla();
			if (aux2 == "1") {
				opcion = cambiar_numero(x, "x");
				x[opcion] = stod(mientras_no_sea_numero("x[" + std::to_string(opcion) + "]: "));
			}
			if (aux2 == "2") {
				opcion = cambiar_numero(fx, "f(x)");
				fx[opcion] = stod(mientras_no_sea_numero("f(" + std::to_string(x[opcion]) + ") = "));
			}
		}
	} while (aux == "n");

	do {
		std::cout << std::endl << "1) Diferencias Divididas\n2) Ajuste de curvas\n\nElige una opcion: ";
		std::cin >> aux;
		if (aux != "1" && aux != "2")
			no_valido();
	} while (aux != "1" && aux != "2");
	if (aux== "1")
		metodo_numerico_diferencias(x,fx);
	else
		std::cout << "aun no esta listo" << std::endl;
}

void metodo_numerico_diferencias(std::vector<double> vect_x, std::vector<double> vect_fx) {
	Diferencias_Divididas diferencias{vect_x, vect_fx};
	std::string respuesta;

	do {
		borrar_pantalla();
		std::cout << diferencias.imprimir_tabla() << std::endl;
		std::cout << diferencias.imprimir_potencias(stod(mientras_no_sea_numero("Inserte un numero para encontrar su valor: ")));

		respuesta = si_no("¿Quieres bucar otro número? [s/n]: ");
	} while (respuesta == "s");
	borrar_pantalla();
}

void metodo_numerico_spline(std::vector<double> vect_x, std::vector<double> vect_fx){
}

bool numero(std::string cadena) {
	bool si_es{true};
	bool punto{false};

	for (size_t i{}; i < cadena.size(); i++) {
		if (i == 0 && (cadena[i] == '-' || cadena[i] == '+'))
			si_es = true;
		else if (cadena[i] == '.') {
			if (punto == true) {
				si_es = false;
				break;
			}
			punto = true;
		}
		else if (!isdigit(cadena[i])) {
			si_es = false;
			break;
		}
	}

	return si_es;
}

void lower(std::string &texto) {
	for (size_t i{}; i < texto.size(); i++)
		texto[i] = tolower(texto[i]);
}

void no_valido(bool borrar) {
	if (borrar)
		borrar_pantalla();
	std::cout << "Ingreso una opcion no valida. Intente de nuevo" << std::endl
			  << std::endl;
}

void borrar_pantalla() {
	// system("cls");
	system("clear");
}

std::string mientras_no_sea_numero(std::string texto, bool borrar) {
	std::string aux;

	do {
		std::cout << texto;
		std::cin >> aux;
		if (!numero(aux))
			no_valido(borrar);
	} while (!numero(aux));

	return aux;
}

std::string si_no(std::string texto, bool borrar) {
	std::string respuesta;

	do {
		std::cout << texto;
		std::cin >> respuesta;
		lower(respuesta);
		if (respuesta != "s" && respuesta != "n")
			no_valido(borrar);
	} while (respuesta != "s" && respuesta != "n");

	return respuesta;
}

int cambiar_numero(const std::vector<double> &vect, std::string nombre) {
	int opcion{};
	int maximo{static_cast<int>(vect.size())};

	do {
		std::cout << imprimir_vector(vect, nombre, true) << std::endl;
		opcion = stoi(mientras_no_sea_numero("\nElige una opcion: ", false));
		if (opcion < 0 || opcion >= maximo)
			no_valido();
	} while (opcion < 0 || opcion >= maximo);

	return opcion;
}

void nombres() {
	borrar_pantalla();
	std::cout << "Gómez González Astrid" << std::endl;
	std::cout << "Márquez Rosas Lemuel Helon" << std::endl;
	std::cout << "Navarro Ramos Karen" << std::endl;
	std::cout << "Pérez Romero Jonathan " << std::endl;
}
