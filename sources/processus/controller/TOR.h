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
	TOR(int ID, string name, Server* server, State* state,
			double tresh_low, double tresh_high, double ctrl_min, double ctrl_max);
	virtual ~TOR();
	void update(int tic);


	virtual double workValphen(double val = 0, bool set = false)
		{ return state_->workValphen(); }
	virtual double etatCurr(double val = 0, bool set = false)
		{ return state_->etatCurr(); }
private:
	double tresh_low_;
	double tresh_high_;
	double ctrl_min_;
	double ctrl_max_;
};

#endif /* SOURCES_PROCESSUS_CONTROLLER_TOR_H_ */
