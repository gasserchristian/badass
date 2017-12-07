/*
 * TOR.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#include "TOR.h"

TOR::TOR(int ID, string name, Server* server, State* state,
	double tresh_low, double tresh_high, double ctrl_min, double ctrl_max) :
		Control(ID, name, ctrl_max, tresh_high, server, state), tresh_low_(tresh_low), tresh_high_(tresh_high),
		ctrl_min_(ctrl_min), ctrl_max_(ctrl_max) {
}

TOR::~TOR() {
	// TODO Auto-generated destrucTOR stub
}

void TOR::update(int tic) {
	double etat_curr, valctr;
	etat_curr = state_->etatCurr();
	if(etat_curr > tresh_high_) {
		valctr = ctrl_min_;
		server_->log_journal(string("State ")
				+ to_string(ID_)
				+ " (\"" + string(name_) + "\"). Relative error command/state "
				+ to_string((etat_curr - consigne_)/consigne_*100)
				+ "%. Control activated, tresh_high.........");
	}
	else if(etat_curr < tresh_low_) {
		valctr = ctrl_max_;
		server_->log_journal(string("State ")
				+ to_string(ID_)
				+ " (\"" + string(name_) + "\"). Relative error command/state "
				+ to_string((etat_curr - consigne_)/consigne_*100)
				+ "%. Control activated, tresh_down.........");
	}
	else {
		valctr = 0;
	}

	state_->set_valCtrl(valctr);

	server_->log_value(state_->workValphen(0,false));
	server_->log_value(etat_curr);
	server_->log_value(valctr);
}

