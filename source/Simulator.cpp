/*
 * simulator.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */


#include "Simulator.h"

Simulator::Simulator(vector<Process*> Process_list, int nTicks) : Process_list_(Process_list), nTicks_(nTicks) {

}

Simulator::~Simulator() {}


void Simulator::run() {

	int i = Process_list_.size();
	Process* proc = Process_list_[i-1];
	Server* server = dynamic_cast <Server*> (proc);

	//mise à jour et log des valeurs à chaque step:
	for(int iTick = 0; iTick < nTicks_; iTick++) {
		i = 0;
		for(int i = 0, c = Process_list_.size(); i < c; i ++) {
			Process_list_[i]->update();
		}
	}

	//Fermeture des fichiers:
	server->close_files();

}
