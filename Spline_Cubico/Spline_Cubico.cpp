#include "Spline_Cubico.hpp"
#include "Funciones.hpp"

/* Constructores */

Spline_Cubico::Spline_Cubico(std::vector<double> x, std::vector<double> fx)
	: Interpolacion_Polinomial(x, fx) {

	llenar_hi();
	llenar_fi();
	llenar_p();
	llenar_matriz_rectangular();
	llenar_matriz_cuadrada();
	llenar_s();
	llenar_a();
	llenar_b();
	llenar_c();
}

/* Gets y Sets de los Atributos */
std::vector<double> Spline_Cubico::get_hi() {
	return hi;
}

std::vector<double> Spline_Cubico::get_fi() {
	return fi;
}

std::vector<double> Spline_Cubico::get_s() {
	return s;
}

std::vector<double> Spline_Cubico::get_p() {
	return p;
}

std::vector<double> Spline_Cubico::get_a() {
	return a;
}

std::vector<double> Spline_Cubico::get_b() {
	return b;
}

std::vector<double> Spline_Cubico::get_c() {
	return c;
}

/* Metodos */

/* imprimir info */

std::string Spline_Cubico::imprimir_hi() {
	return imprimir_vector(hi, "hi", false);
}

std::string Spline_Cubico::imprimir_fi() {
	return imprimir_vector(fi, "fi", false);
}

std::string Spline_Cubico::imprimir_s() {
	return imprimir_vector(s, "s", false);
}

std::string Spline_Cubico::imprimir_p() {
	return imprimir_vector(p, "p", false);
}

std::string Spline_Cubico::imprimir_a() {
	return imprimir_vector(a, "a", false);
}

std::string Spline_Cubico::imprimir_b() {
	return imprimir_vector(b, "b", false);
}

std::string Spline_Cubico::imprimir_c() {
	return imprimir_vector(c, "c", false);
}

std::string Spline_Cubico::imprimir_todas() {
	std::vector<std::string> nombres{"x", "f(x)", "hi", "fi", "p", "s", "a", "b", "c"};
	std::vector<std::vector<double>> imprimir{x, fx, hi, fi, p, s, a, b, c};

	return imprimir_vectores(imprimir, nombres);
}

/* Llenan los vectores con la info dada */

void Spline_Cubico::llenar_hi() {
	for (size_t i{}; i < x.size() - 1; i++)
		hi.push_back(x[i + 1] - x[i]);
}

void Spline_Cubico::llenar_fi() {
	for (size_t i{}; i < x.size() - 1; i++)
		fi.push_back((fx[i + 1] - fx[i]) / hi[i]);
}

void Spline_Cubico::llenar_matriz_rectangular() {
	std::vector<std::vector<double>> tabla;

	for (size_t i{}; i < hi.size() + 1; i++) {
		std::vector<double> fila;
		for (size_t j{}; j < hi.size() - 1; j++)
			fila.push_back(0);
		tabla.push_back(fila);
	}

	for (size_t i{}; i < hi.size() - 1; i++) {
		tabla[i][i] = hi[i];
		tabla[i + 1][i] = 2 * (hi[i] + hi[i + 1]);
		tabla[i + 2][i] = hi[i + 1];
	}

	matriz_rectangular = Matriz{tabla, false};
}

void Spline_Cubico::llenar_matriz_cuadrada() {
	std::vector<std::vector<double>> tabla;
	size_t n{matriz_rectangular.matriz.size()};

	for (size_t i{}; i < n; i++) {
		if (i != 0 && i != n - 1)
			tabla.push_back(matriz_rectangular.matriz[i]);
	}

	matriz_cuadrada = Matriz{tabla, true};
}

void Spline_Cubico::llenar_s() {
	std::vector<double> aux{matriz_cuadrada.vector_x_inversa(p)};
	s.push_back(0);
	for (size_t i{}; i < aux.size(); i++)
		s.push_back(aux[i]);
	s.push_back(0);
}

void Spline_Cubico::llenar_p() {
	for (size_t i{}; i < fi.size() - 1; i++)
		p.push_back(6 * (fi[i + 1] - fi[i]));
}

void Spline_Cubico::llenar_a() {
	for (size_t i{}; i < s.size() - 1; i++)
		a.push_back((s[i + 1] - s[i]) / (6 * hi[i]));
}

void Spline_Cubico::llenar_b() {
	for (size_t i{}; i < s.size() - 1; i++)
		b.push_back(s[i] / 2);
}

void Spline_Cubico::llenar_c() {
	for (size_t i{}; i < s.size() - 1; i++)
		c.push_back(((fx[i + 1] - fx[i]) / hi[i]) - ((s[i + 1] + (2 * s[i])) / 6) * hi[i]);
}


std::string Spline_Cubico::coeficientes(){
	std::string coeficientes;
	
	for(size_t i{};i < hi.size();i++){
		std::string coeficiente {"g" + std::to_string(i) + "(x) = "};

		if(a[i] != 0&&x[i] != 0&&a[i] != -0&&x[i] != -0)
			coeficiente += imprimir_numero(a[i],false) + "(x - " + imprimir_numero(x[i],false) + ")^3";
		if(b[i] != 0&&x[i] != 0&&b[i] != -0&&x[i] != -0){
			if(coeficiente.size() == 0)
				coeficiente += imprimir_numero(b[i],false) + "(x - " + imprimir_numero(x[i],false) + ")^2";
			else
				coeficiente += " + " + imprimir_numero(b[i],false) + "(x - " + imprimir_numero(x[i],false) + ")^2";
		}
		if(c[i] != 0&&x[i] != 0&&c[i] != -0&&x[i] != -0){
			if(coeficiente.size() == 0)
				coeficiente += imprimir_numero(c[i],false) + "(x - " + imprimir_numero(x[i],false) + ")";
			else
				coeficiente += " + " + imprimir_numero(c[i],false) + "(x - " + imprimir_numero(x[i],false) + ")";
		}
		if(fx[i] != 0&&x[i] != 0&&fx[i] != -0&&x[i] != -0){
			if(coeficiente.size() == 0)
				coeficiente += imprimir_numero(fx[i],false);
			else
				coeficiente += " + " + imprimir_numero(fx[i],false);
		}
		coeficiente += "\t|\t" + imprimir_numero(x[i],false) + " >= x <= " + imprimir_numero(x[i+1],false);
		coeficientes += coeficiente + "\n";
	}

	return coeficientes;
}
