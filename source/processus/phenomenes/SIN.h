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
	virtual ~SIN();
};

#endif /* SOURCE_PROCESSUS_PHENOMENES_SIN_H_ */
