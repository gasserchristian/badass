/*
 * TOR.h
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#ifndef SOURCES_PROCESSUS_CONTROLLER_TOR_H_
#define SOURCES_PROCESSUS_CONTROLLER_TOR_H_

#include "../Control.h"
#include "../Process.h"
#include "../Server.h"

class TOR : public Control {
public:
	TOR(int ID, string name, Process* server, Process* state, double val_sat, double consigne);
	virtual ~TOR();
	void update();


	virtual double workValphen(double val = 0, bool set = false)  { return state_->workValphen(); }
	virtual double etatCurr(double val = 0, bool set = false)  { return state_->etatCurr(); }
private:
	Process* server_;
	Process* state_;
};

#endif /* SOURCES_PROCESSUS_CONTROLLER_TOR_H_ */
