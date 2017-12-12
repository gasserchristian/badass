/*
 * simulator.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */


#include "Simulator.h"

void Simulator::run() {
	//mise à jour et log des valeurs à chaque step:
	for(int iTick = 0; iTick < nTicks_; iTick++) {
		static int checkpoint = 0;
		if(iTick>checkpoint) {
			cout << "Simulation status: " << 100*iTick/(nTicks_-1) << "% completed" << endl;
			checkpoint += (nTicks_-1)*step_/100;
		}
		for(int i = 0, c = Process_list_.size(); i < c; i ++) {
			Process_list_[i]->update(iTick);
			}
	}
}
