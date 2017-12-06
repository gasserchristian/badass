/*
 * P.h
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */


#ifndef SOURCES_PROCESSUS_CONTROLLER_P_H_
#define SOURCES_PROCESSUS_CONTROLLER_P_H_

#include "../State.h"
#include "../Server.h"
#include "../Control.h"

class P : public Control {
public:
	P(int ID, string name, Server* server, State* state,
			double set_point, double gain, double sat);
	virtual ~P();
	virtual double workValphen(double val = 0, bool set = false)
		{ return state_->workValphen(); }
	virtual double etatCurr(double val = 0, bool set = false)
		{ return state_->etatCurr(); }
	void update(unsigned tic);
private:
	double set_point_;
	double gain_;
	double sat_;
};

#endif /* SOURCES_PROCESSUS_CONTROLLER_P_H_ */
