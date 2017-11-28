/*
 * control.h
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#ifndef SOURCES_PROCESSUS_CONTROL_H_
#define SOURCES_PROCESSUS_CONTROL_H_

#include "Process.h"
#include "State.h"

class Control: public Process {
public:
	Control();
	Control(int ID, string name, double val_sat, double consigne);
	virtual ~Control();

	//autres
	virtual void update() = 0;
	virtual double workValphen(double val = 0, bool set = false) = 0;
	virtual double etatCurr(double val = 0, bool set = false) = 0;

protected:
	double val_sat_;
	double consigne_;
};

#endif /* SOURCES_PROCESSUS_CONTROL_H_ */
