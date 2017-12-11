/*
 * TOR.h
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#ifndef SOURCES_PROCESSUS_CONTROLLER_TOR_H_
#define SOURCES_PROCESSUS_CONTROLLER_TOR_H_

#include "../Control.h"

class TOR : public Control {
public:
	//constructor/destructor
	TOR(int ID, string name, Server* server, State* state,
		double tresh_low, double tresh_high, double ctrl_min, double ctrl_max) :
			Control(ID, name, server, state), tresh_low_(tresh_low), tresh_high_(tresh_high),
			ctrl_min_(ctrl_min), ctrl_max_(ctrl_max) {
	}
	virtual ~TOR() {}

	//actions
	void update(int tic);
private:
	double tresh_low_;
	double tresh_high_;
	double ctrl_min_;
	double ctrl_max_;
};

#endif /* SOURCES_PROCESSUS_CONTROLLER_TOR_H_ */
