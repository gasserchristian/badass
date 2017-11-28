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
#include "Process.h"

class Phenomenon: public Process {
public:
	Phenomenon() {}
	Phenomenon(unsigned ID, string name, Process* state);
	virtual ~Phenomenon();

	// autres

	virtual void update() = 0;
	virtual double workValphen(double val = 0, bool set = false) { return NULL; }
	virtual double etatCurr(double val = 0, bool set = false) { return NULL; }
protected:
	string name_;
	Process* state_;
};

#endif /* SOURCES_PROCESSUS_PHENOMENON_H_ */
