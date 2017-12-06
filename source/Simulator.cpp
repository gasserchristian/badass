/*
 * simulator.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */


#include "Simulator.h"

Simulator::Simulator(int nTicks) :
nTicks_(nTicks), Process_list_() {}

Simulator::~Simulator() {}

void Simulator::run() {
	//mise à jour et log des valeurs à chaque step:
	for(int iTick = 0; iTick < nTicks_; iTick++) {
		for(int i = 0, c = Process_list_.size(); i < c; i ++) {
			Process_list_[i]->update();
		}
	}
}
