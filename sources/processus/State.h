/*
 * State.h
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#ifndef SOURCES_PROCESSUS_State_H_
#define SOURCES_PROCESSUS_State_H_

#include "Process.h"

class State: public Process {
public:
	//constructor/destructor
	State(int ID, string name, double i_phen, double i_ctrl,
				 double val_phen, double state_curr) :
				 Process(ID, name), name_(name), I_phen_(i_phen), I_ctrl_(i_ctrl),
				 val_phen_(val_phen), State_curr_(state_curr), val_ctrl_(state_curr) {}
	virtual ~State() {}

	//setters
	void set_valPhen(double val) { val_phen_ = val; }
	void set_valCtrl(double val) { val_ctrl_ = val; }

	//getters
	double get_valPhen() { return val_phen_; }
	double get_StateCurr() { return State_curr_;}
	string get_Statename() { return name_;}

	//actions
	virtual void update(int tic);
private:
	string name_;
	double I_phen_;
	double I_ctrl_;
	double val_phen_;
	double State_curr_;
	double val_ctrl_;
};

#endif /* SOURCES_PROCESSUS_State_H_ */
