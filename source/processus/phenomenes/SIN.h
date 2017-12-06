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

class SIN : public Phenomenon {
public:
	SIN(unsigned ID, std::string sin_name, Process* state, double sigma, double offset,
				double ampl, double phase, double sat_max, double sat_min);
	void update(unsigned tic);
	virtual ~SIN();
private:
	const double ampl_, phase_, sat_max_, sat_min_, offset_, sigma_;
};

#endif /* SOURCE_PROCESSUS_PHENOMENES_SIN_H_ */
