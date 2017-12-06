/*
 * control.h
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#ifndef SOURCES_PROCESSUS_CONTROL_H_
#define SOURCES_PROCESSUS_CONTROL_H_

#include "State.h"
#include "Server.h"
#include "Process.h"

class Control: public Process {
public:
	Control();
	Control(int ID, string name, double val_sat, double consigne, Process* server, Process* state);
	virtual ~Control();

	//autres
	void update() = 0;
	virtual double workValphen(double val = 0, bool set = false)
		{ return state_->workValphen(); }
	virtual double etatCurr(double val = 0, bool set = false)
		{ return state_->etatCurr(); }

protected:
	double val_sat_;
	double consigne_;
	Process* server_;
	Process* state_;
};

#endif /* SOURCES_PROCESSUS_CONTROL_H_ */
