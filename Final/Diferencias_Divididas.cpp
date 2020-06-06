#include "Diferencias_Divididas.hpp"

Diferencias_Divididas::Diferencias_Divididas() {}

Diferencias_Divididas::Diferencias_Divididas(std::vector<double> x, std::vector<double> fx) 
	: Metodo_Numerico(x,fx){
		llenar_tabla();
}

std::vector<std::vector<double>> Diferencias_Divididas::get_tabla() {
	return tabla;
}

void Diferencias_Divididas::llenar_tabla() {
	for (size_t i{}; i < x.size() - 1; i++) {
		std::vector<double> columna;

		for (size_t j{}; j < x.size() - i - 1; j++) {
			double valor{};

			if (i == 0)
				valor = (fx[j + 1] - fx[j]) / (x[j + 1] - x[j]);
			else
				valor = (tabla[i - 1][j + 1] - tabla[i - 1][j]) / (x[j + 1 + i] - x[j]);
			columna.push_back(valor);
		}
		tabla.push_back(columna);
	}
}

std::string Diferencias_Divididas::imprimir_potencias(double numero,size_t tamanio) {
	std::string dos_tablas;
	std::vector<size_t> t;
	std::vector<std::string> nombres;
	std::vector<std::string> nombres2;
	std::vector<double> p;
	std::vector<double> p2;
	double suma{};

	for (size_t i{}; i < x.size() - 1; i++) {
		double numero;

		if (i == 0)
			numero = fx[0] + (tabla[0][0] * (numero - x[0]));
		else {
			numero = tabla[i][0];
			for (size_t j{}; j <= i; j++)
				numero *= (numero - x[j]);
		}
		p.push_back(numero);
	}
	for (size_t i{}; i < p.size(); i++){
		suma += p[i];
		p2.push_back(suma);
		nombres.push_back("f" + std::to_string(i + 1));
		nombres2.push_back("p" + std::to_string(i + 1));
		t.push_back(tamanio);
	}

	dos_tablas += imprimir_matriz<double>(std::vector<std::vector<double>> {p}, t, nombres);
	dos_tablas += imprimir_matriz<double>(std::vector<std::vector<double>> {p2}, t, nombres2);
	return dos_tablas;
}

std::string Diferencias_Divididas::imprimir_tabla_escalonada() {
	std::vector<std::string> nombres{"x", "f(x)"};
	std::vector<std::vector<double>> m{x,fx};

	for (size_t i{1}; i <= tabla.size(); i++){
		nombres.push_back("f" + std::to_string(i));
		m.push_back(tabla[i]);
	}
	return imprimir_tabla<double>(nombres, m);
}
