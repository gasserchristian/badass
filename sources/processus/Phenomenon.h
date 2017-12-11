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
#include "../utilitaire.h"

class Phenomenon: public Process {
public:
	//constructor/destructor
	Phenomenon() : state_(NULL) {}
	Phenomenon(unsigned ID, string name, State* state)
		: Process(ID, name), state_(state)  {
	}
	virtual ~Phenomenon() {}

	//actions
	virtual void update(int tic) = 0;
protected:
	State* state_;
};

#endif /* SOURCES_PROCESSUS_PHENOMENON_H_ */
