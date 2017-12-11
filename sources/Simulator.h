/*
 * simulator.h
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#ifndef SOURCES_SIMULATOR_H_
#define SOURCES_SIMULATOR_H_

#include "./processus/Process.h"
#include "./processus/Server.h"
#include <string>
#include <vector>

using namespace std;

class Simulator {
public:
	Simulator() : nTicks_(), Process_list_() {}
	virtual ~Simulator() {}

	void run();

	void set_nTicks(int nTicks) {nTicks_ = nTicks;}

	void set_process_list(Process* process_new) {Process_list_.push_back(process_new);}

	//string get_tick_unit() {return tick_unit_;}

private:
	int nTicks_;
	vector<Process*> Process_list_;
	const int checkpoint_ = 5; //for % completed information on console
};

#endif /* SOURCES_SIMULATOR_H_ */
