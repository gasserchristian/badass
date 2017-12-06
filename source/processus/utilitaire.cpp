


#include "utilitaire.h"
#include <math.h>

double box_muller() {
	double x1 = rand(), x2 = rand();
	double y = sqrt(-2*log(x1))*cos(2*M_PI*x2);
	return y;
}
