#ifndef _SPLINE_CUBICO_H_
#define _SPLINE_CUBICO_H_

#include "Interpolacion_Polinomial.hpp"

class Spline_Cubico: public Interpolacion_Polinomial {
protected:

public:
	Spline_Cubico(std::vector<double>, std::vector<double>);
};

#endif

