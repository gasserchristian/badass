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
	//constructor/destructor
	Control() : Process(0, "no name"),
		server_(NULL), state_(NULL) {}
	Control(int ID, string name,
			Server* server, State* state) :
				Process(ID, name),
				server_(server), state_(state) {}
	virtual ~Control() {};

	//actions
	void update(int tic) = 0;

protected:
	Server* server_;
	State* state_;
};

#endif /* SOURCES_PROCESSUS_CONTROL_H_ */
