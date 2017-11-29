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
	Process();
	Process(unsigned ID, string name);
	virtual ~Process();

	// autres
	virtual void update() = 0;
	virtual double workValphen(double val = 0, bool set = false) = 0;
	virtual double etatCurr(double val = 0, bool set = false) = 0;

protected:
	unsigned ID_;
	string name_;
};

#endif /* SOURCES_PROCESSUS_PROCESS_H_ */
