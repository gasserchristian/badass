/*
 * SIN.h
 *
 *  Created on: 6 déc. 2017
 *      Author: Christian
 */

#ifndef SOURCE_PROCESSUS_PHENOMENES_SIN_H_
#define SOURCE_PROCESSUS_PHENOMENES_SIN_H_

#include "../Phenomenon.h"
#include <string>
#include <math.h>

class SIN : public Phenomenon {
public:
	SIN(unsigned ID, std::string sin_name, Process* state, double sigma, double offset,
				double ampl, long int phase, long int period, double sat_max, double sat_min);
	void update(unsigned tic);
	virtual ~SIN();
private:
	const double sigma_;
	const double offset_;
	const double ampl_;
	long int phase_;
	long int period_;
	double sat_max_;
	double sat_min_;
};

#endif /* SOURCE_PROCESSUS_PHENOMENES_SIN_H_ */
