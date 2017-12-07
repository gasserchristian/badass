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

const int checkpoints = 5;

class Simulator {
public:
	Simulator();
	virtual ~Simulator();

	void run();

	void set_nTicks(int nTicks) {nTicks_ = nTicks;}

	void set_process_list(Process* process_new) {Process_list_.push_back(process_new);}

	//string get_tick_unit() {return tick_unit_;}

private:
	int nTicks_;
	vector<Process*> Process_list_;
};

#endif /* SOURCES_SIMULATOR_H_ */
