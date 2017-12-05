/*
 * simulator.h
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#ifndef SOURCES_SIMULATOR_H_
#define SOURCES_SIMULATOR_H_

#include "./parseur/parser.h"
#include "./processus/Process.h"
#include "./processus/Server.h"
#include <string>
#include <vector>

using namespace std;

class Simulator {
public:
	Simulator(vector<Process*> Process_list, int nTicks);
	virtual ~Simulator();

	void run();

	void set_process_list(Process* process_new) {Process_list_.push_back(process_new);}

	//string get_tick_unit() {return tick_unit_;}

private:
	vector<Process*> Process_list_;
	int nTicks_;
};

#endif /* SOURCES_SIMULATOR_H_ */
