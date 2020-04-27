#ifndef _DIFERENCIAS_DIVIDIDAS_H_
#define _DIFERENCIAS_DIVIDIDAS_H_

#include <string>
#include <vector>

class Diferencias_Divididas{
private:
	std::vector<double> x;
	std::vector<double> fx;
	std::vector<std::vector<double>> tabla;

public:
	Diferencias_Divididas(std::vector<std::vector<double>>);
	Diferencias_Divididas(std::vector<double>, std::vector<double>);

	double get_x(size_t);
	void set_x(size_t,double);

	double get_fx(size_t);
	void set_fx(size_t,double);

	std::vector<double> get_vector_x();
	std::vector<double> get_vector_fx();
	std::vector<std::vector<double>> get_tabla();

	void ordenar();
	void llenar_tabla();
	std::vector<double> potencias(double);
};
#endif
