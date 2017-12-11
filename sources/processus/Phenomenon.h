/*
 * phenomenon.h
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#ifndef SOURCES_PROCESSUS_PHENOMENON_H_
#define SOURCES_PROCESSUS_PHENOMENON_H_

#include <cstdlib>
#include <string>
#include "State.h"
#include "utilitaire.h"

class Phenomenon: public Process {
public:
	Phenomenon() : state_(NULL) {}
	Phenomenon(unsigned ID, string name, Process* state);
	virtual ~Phenomenon() {}
	// autres
	virtual void update(int tic) = 0;
	virtual double workValphen(double val = 0, bool set = false) { return 0.0; }
	virtual double etatCurr(double val = 0, bool set = false) { return 0.0; }
protected:
	Process* state_;
};

#endif /* SOURCES_PROCESSUS_PHENOMENON_H_ */
