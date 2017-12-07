/*
 * control.h
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#ifndef SOURCES_PROCESSUS_CONTROL_H_
#define SOURCES_PROCESSUS_CONTROL_H_

#include "Server.h"
#include "State.h"

class Control : public Process {
public:
	Control() : Process(0, "no name"), val_sat_(0.0), consigne_(0.0),
		server_(NULL), state_(NULL) {}
	Control(int ID, string name, double val_sat, double consigne,
			Server* server, State* state) :
				Process(ID, name), val_sat_(val_sat), consigne_(consigne),
				server_(server), state_(state) {}
	virtual ~Control() {};

	//autres
	void update(int tic) = 0;
	virtual double workValphen(double val = 0, bool set = false)
		{ return state_->workValphen(); }
	virtual double etatCurr(double val = 0, bool set = false)
		{ return state_->etatCurr(); }

protected:
	double val_sat_;
	double consigne_;
	Server* server_;
	State* state_;
};

#endif /* SOURCES_PROCESSUS_CONTROL_H_ */
