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
#include <cassert>

class SIN : public Phenomenon {
public:
	//constructor/destructor
	SIN(unsigned ID, std::string sin_name, State* state, double sigma, double offset,
			double ampl, long int phase, long int period, double sat_max, double sat_min) :
			Phenomenon(ID, sin_name, state), sigma_(sigma), offset_(offset), ampl_(ampl), phase_(phase),
				period_(period), sat_max_(sat_max), sat_min_(sat_min) {
		assert(period_>0);
	}
	virtual ~SIN() {}

	//actions
	void update(int tic);
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
