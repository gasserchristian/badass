/*
 * P.h
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */


#ifndef SOURCES_PROCESSUS_CONTROLLER_P_H_
#define SOURCES_PROCESSUS_CONTROLLER_P_H_

#include "../Control.h"
#include <limits>

class P : public Control {
public:
	//constructor/destructor
	P(int ID, string name, Server* server, State* state,
			double set_point, double gain, double sat) :
				Control(ID, name, server, state), set_point_(set_point), gain_(gain), sat_(sat) {

	}
	virtual ~P() {}

	//actions
	void update(int tic);
private:
	double set_point_;
	double gain_;
	double sat_;
	double state_curr_min_ = std::numeric_limits<double>::infinity();
	double state_curr_max_ = -state_curr_min_;
};

#endif /* SOURCES_PROCESSUS_CONTROLLER_P_H_ */
