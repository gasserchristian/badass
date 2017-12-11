/*
 * TOR.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#include "TOR.h"
#include <iostream> //DELETE AFTER

void TOR::update(int tic) {
	double etat_curr, valctr;
	etat_curr = state_->get_StateCurr();
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
		/*
		server_->log_journal(string("State ")
				+ to_string(ID_)
				+ " (\"" + string(name_) + "\"). Relative error command/state "
				+ to_string((etat_curr - consigne_)/consigne_*100)
				+ "%. Control activated, tresh_down.........");
		*/
	}
	else {
		valctr = 0;
	}

	state_->set_valCtrl(valctr);

	server_->log_value(state_->get_StateCurr());
	server_->log_value(etat_curr);
	server_->log_value(valctr);
}

