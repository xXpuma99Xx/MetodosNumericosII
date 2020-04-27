#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Diferencias_Divididas.h"

const double length = 10;

void metodo_numerico();
void nombres();
void borrar_pantalla();
void no_valido(bool borrar = true);

std::vector<std::vector<double>> capturar_vectores();
std::string imprimir_numero(double);
std::string mientras_no_sea_numero(std::string , bool borrar = true);
std::string si_no(std::string , bool borrar = true);
int cambiar_numero(const std::vector<double> &, std::string);

bool numero(std::string);
void lower(std::string &);

void imprimir_headers(std::vector<std::string> nombres);
void imprimir_array(std::vector<double> , std::string );
void imprimir_vectores(std::vector<double>, std::vector<double>);
void imprimir_tabla(std::vector<std::vector<double>> );
void imprimir_p(std::vector<double> );

int main(){
	std::string respuesta;

	nombres();
	do{
		do{
			std::cout << std::endl << "1) Diferencias Divididas\n2) Ajuste de curvas\n\nElige una opcion: ";
			std::cin >> respuesta;
			if(respuesta != "1"&&respuesta != "2")
				no_valido();
		}while(respuesta != "1"&&respuesta != "2");
		if(respuesta == "1")
			metodo_numerico();
		else
			std::cout << "aun no esta listo"<< std::endl;
		
		respuesta = si_no("¿Quieres repetir el programa? [s/n]: ");
	}while(respuesta == "s");
	return 0;
}

void metodo_numerico(){
	Diferencias_Divididas ejemplo{capturar_vectores()};
	std::string respuesta;

	do{
		borrar_pantalla();
		imprimir_vectores(ejemplo.get_vector_x(),ejemplo.get_vector_fx());
		imprimir_tabla(ejemplo.get_tabla());
		imprimir_p(ejemplo.potencias(stod(mientras_no_sea_numero("Inserte un numero para encontrar su valor: "))));
		
		respuesta = si_no("¿Quieres bucar otro número? [s/n]: ");
	}while(respuesta == "s");
	borrar_pantalla();
}

std::vector<std::vector<double>> capturar_vectores(){
	int n {};
	std::string aux;
	std::vector<double> x;
	std::vector<double> fx;

	borrar_pantalla();
	do{
		n = stoi(mientras_no_sea_numero("¿Cuántos valores desea insertar? "));
		if(n < 1)
			no_valido();
	}while(n < 1);
	borrar_pantalla();
	for(int i {};i < n;i++){
		std::string sub_indice {mientras_no_sea_numero("x[" + std::to_string(i) + "]: ")};
		x.push_back(stod(sub_indice));
		fx.push_back(stod(mientras_no_sea_numero("f(" + sub_indice + ") = ")));
	}
	borrar_pantalla();
	do{
		imprimir_vectores(x,fx);
		aux = si_no("¿Estan correctos todos estos datos? [s/n]: ",false);
		borrar_pantalla();
		if(aux == "n"){
			std::string aux2;
			int opcion {};

			do{
				std::cout << "1)Cambiar un dato de x\n2)Cambiar un dato de f(x)\n\nElige una opcion: ";
				std::cin >> aux2;
				if(aux2 != "1"&&aux2 != "2")
					no_valido();
			}while(aux2 != "1"&&aux2 != "2");
			borrar_pantalla();
			if(aux2 == "1"){
				opcion = cambiar_numero(x,"x");
				x[opcion] = stod(mientras_no_sea_numero("x[" + std::to_string(opcion) + "]: "));
			}
			if(aux2 == "2"){
				opcion = cambiar_numero(fx,"f(x)");
				fx[opcion] = stod(mientras_no_sea_numero("f(" + std::to_string(x[opcion]) + ") = "));
			}
		}
	}while(aux == "n");

	std::vector<std::vector<double>> vectores {x,fx};
	return vectores;
}

bool numero(std::string cadena){
	bool si_es {true};
	bool punto {false};

	for(size_t i {};i < cadena.size();i++){
		if(i == 0&&(cadena[i] == '-'||cadena[i] == '+'))
			si_es = true;
		else if(cadena[i] == '.'){
			if(punto == true){
				si_es = false;
				break;
			}
			punto = true;
		}
		else if(!isdigit(cadena[i])){
			si_es = false;
			break;
		}
	}
	return si_es;
}

void imprimir_headers(std::vector<std::string> nombres){
	for(size_t i {};i < nombres.size();i++){
		std::cout << "+";
		for(double j {}; j < length;j++)
			std::cout << "-";
	}
	std::cout << "+" << std::endl << "|";
	for(size_t i {};i < nombres.size();i++){
		int espacios_izquierda {static_cast<int>(floor((length - nombres[i].size())/2))};
		int espacios_derecha {static_cast<int>(ceil((length - nombres[i].size())/2))};

		for(int j {}; j < espacios_izquierda;j++)
			std::cout << " ";
		std::cout << nombres[i];
		for(int j {}; j < espacios_derecha;j++)
			std::cout << " ";
		std::cout << "|";
	}
	std::cout << std::endl;
	for(size_t i {};i < nombres.size();i++){
		std::cout << "+";
		for(double j {}; j < length;j++)
			std::cout << "-";
	}
	std::cout << "+" << std::endl;
}

void imprimir_vectores(std::vector<double> x, std::vector<double> fx){
	std::vector<std::string> nombres {"x","f(x)"};
	imprimir_headers(nombres);
	for(size_t i {};i < x.size();i++){
		std::cout << "|" << imprimir_numero(x[i]) << "|" << imprimir_numero(fx[i]) << "|" << std::endl;
	}
	for(size_t i {};i < nombres.size();i++){
		std::cout << "+";
		for(double j {}; j < length;j++)
			std::cout << "-";
	}
	std::cout << "+" << std::endl;
}

void imprimir_array(std::vector<double> array, std::string texto){
	std::vector<std::string> nombres {texto};
	imprimir_headers(nombres);
	for(size_t i {};i < array.size();i++)
		std::cout << "|" << imprimir_numero(array[i]) << "|" << " " << i << std::endl;
	for(size_t i {};i < nombres.size();i++){
		std::cout << "+";
		for(double j {}; j < length;j++)
			std::cout << "-";
	}
	std::cout << "+" << std::endl;
}

void imprimir_tabla(std::vector<std::vector<double>> tabla){
	std::vector<std::string> nombres;

	for(size_t i{1};i <= tabla.size();i++)
		nombres.push_back("f"+ std::to_string(i));
	
	imprimir_headers(nombres);
	for(size_t i{};i < tabla.size();i++){
		for(size_t j{};j < tabla.size() - i;j++){
			std::cout << "|" << imprimir_numero(tabla[j][i]);
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "+";
	for(double j {}; j < length;j++)
		std::cout << "-";
	std::cout << "+" << std::endl;
}

void imprimir_p(std::vector<double> resultados){
	std::vector<std::string> nombres;

	for(size_t i{};i < resultados.size();i++)
		nombres.push_back("p"+ std::to_string(i + 1));
	imprimir_headers(nombres);
	for(size_t i{};i < resultados.size();i++){
		double aux {};
		for(size_t j{};j <= i;j++)
			aux += resultados[j];
		std::cout << "|" << imprimir_numero(aux);
	}
	std::cout << "|" << std::endl;
	for(size_t i {};i < nombres.size();i++){
		std::cout << "+";
		for(double j {}; j < length;j++)
			std::cout << "-";
	}
	std::cout << "+" << std::endl;
}

std::string imprimir_numero(double numero){
	unsigned contador {};
	std::string numero_string {std::to_string(numero)};
	size_t i {};

	for(i = 0;i < numero_string.size();i++){
		if(numero_string[i] == '.'){
			for(size_t j = i+1;j < numero_string.size();j++){
				if(numero_string[j] == '0')
					contador++;
				else{
					i = j;
					contador = 0;
				}
			}
			break;
		}
	}
	numero_string = numero_string.erase(i+1,contador);
	if(numero_string.size() > static_cast<int>(length))
		numero_string = numero_string.substr(0,length);
	if(numero_string[numero_string.size() - 1] == '.')
		numero_string.erase(numero_string.size()-1);
	for(i = numero_string.size();i < static_cast<int>(length);i++)
		numero_string += " ";
	return numero_string;
}

void lower(std::string &texto){
	for(size_t i{};i < texto.size();i++)
		texto[i] = tolower(texto[i]);
}

void no_valido(bool borrar){
	if(borrar)
		borrar_pantalla();
	std::cout << "Ingreso una opcion no valida. Intente de nuevo" << std::endl << std::endl;
}

void borrar_pantalla(){
	// system("cls");
	system("clear");
}

std::string mientras_no_sea_numero(std::string texto, bool borrar){
	std::string aux;

	do{
		std::cout << texto;
		std::cin >> aux;
		if(!numero(aux))
			no_valido(borrar);
	}while(!numero(aux));
	return aux;
}

std::string si_no(std::string texto, bool borrar){
	std::string respuesta;

	do{
			std::cout << texto;
			std::cin >> respuesta;
			lower(respuesta);
			if(respuesta != "s"&&respuesta != "n")
				no_valido(borrar);
	}while(respuesta != "s"&&respuesta != "n");
	return respuesta;
}

int cambiar_numero(const std::vector<double> &vect, std::string nombre){
	int opcion {};
	int maximo {static_cast<int>(vect.size())};
	do{ 
		imprimir_array(vect, nombre);
		opcion = stoi(mientras_no_sea_numero("\nElige una opcion: ", false));
		if(opcion < 0||opcion >= maximo)
			no_valido();
	}while(opcion < 0||opcion >= maximo);
	return opcion;
}

void nombres () {
	borrar_pantalla();
  std::cout << "Gómez González Astrid" << std::endl;
  std::cout << "Márquez Rosas Lemuel Helon" << std::endl;
  std::cout << "Navarro Ramos Karen" << std::endl;
	std::cout << "Pérez Romero Jonathan " << std::endl;
}
