#include "Funciones.hpp"

std::string imprimir_celda(std::string texto, size_t t, bool centrar){
	std::string celda;
	size_t texto_t{t - texto.size()};

	if(centrar){
		size_t izquierda{texto_t/2};
		size_t derecha{(texto_t % 2 == 1) ? izquierda + 1: izquierda};

		for(size_t i{};i < izquierda;i++)
			celda += " ";
		celda += texto;
		for(size_t i{};i < derecha;i++)
			celda += " ";
	} else{
		celda += texto;
		for(size_t i{};i < texto_t;i++)
			celda += " ";
	}
	return celda + "|";
}

std::string linea(size_t t, bool espacios){
	std::string linea;

	for(size_t i{};i < t;i++){
		if(espacios)
			linea += " ";
		else
			linea += "-";
	}
	return linea;
}

std::string linea_completa(size_t n,std::vector<size_t> t){
	std::string line{"+"};

	for(size_t i{};i < n;i++)
		line += linea(t[i]) + "+";
	return line + "\n";
}

void llenar_t(std::vector<size_t> &t,size_t n){
	if(t.size() == 0)
		for(size_t i{};i < n;i++)
			t.push_back(length);
}

std::string imprimir_headers(std::vector<std::string> nombres, bool linea_final, bool linea_inicial, std::vector<size_t> t){
	std::string header;
	std::string linea;

	llenar_t(t,nombres.size());
	linea = linea_completa(nombres.size(), t);
	if(linea_inicial)
		header += linea;
	header += "|";
	for(size_t i{};i < nombres.size();i++)
		header += imprimir_celda(nombres[i],t[i]);
	if(linea_final)
		header += "\n" + linea;
	return header;
}

void ordenar_dos_vectores(std::vector<double> &x, std::vector<double> &fx) {
	for (size_t i{}; i < x.size(); i++) {
		for (size_t j{i}; j < x.size(); j++) {
			if (x[j] < x[i]) {
				double aux{};

				aux = x[j];
				x[j] = x[i];
				x[i] = aux;
				aux = fx[j];
				fx[j] = fx[i];
				fx[i] = aux;
			}
		}
	}
}

bool si_no(std::string texto) {
	std::string respuesta;

	do {
		std::cout << texto;
		std::cin >> respuesta;
		for (size_t i{}; i < respuesta.size(); i++)
			respuesta[i] = tolower(respuesta[i]);
		if (respuesta != "s" && respuesta != "n")
			no_valido();
	} while (respuesta != "s" && respuesta != "n");
	if (respuesta == "n")
		return false;
	return true;
}

int imprimir_menu(std::vector<std::string> opciones) {
	int r;
	std::string menu;

	for (size_t i{}; i < opciones.size(); i++)
		menu += (std::to_string(i + 1) + ") " + opciones[i] + "\n");
	menu += "\nElige una opcion: ";
	do {
		r = mientras_no_sea_numero<int>(menu);
		if (r < 1 || r > static_cast<int>(opciones.size()))
			no_valido();
	} while (r < 1 || r > static_cast<int>(opciones.size()));
	return r;
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


