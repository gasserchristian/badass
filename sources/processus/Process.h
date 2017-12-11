/*
 * processus.h
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#ifndef SOURCES_PROCESSUS_PROCESS_H_
#define SOURCES_PROCESSUS_PROCESS_H_

#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;

class Process {
public:
	//constructor/destructor
	Process() : ID_(0), name_("no name") {}
	Process(unsigned ID, string name) : ID_(ID), name_(name) {}
	virtual ~Process() {}

	//actions
	virtual void update(int tic) = 0;

protected:
	unsigned ID_;
	string name_;
};

#endif /* SOURCES_PROCESSUS_PROCESS_H_ */
