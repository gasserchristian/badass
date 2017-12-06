


#include "utilitaire.h"

double box_muller() {
	double x1 = static_cast<double>(rand())/RAND_MAX;
	double x2 = static_cast<double>(rand())/RAND_MAX;
	double y = sqrt(-2*log(x1))*cos(2*M_PI*x2);
	return y;
}
