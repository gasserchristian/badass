/*
 * TOR.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#include "TOR.h"
#include <cassert>

void TOR::update(int tic) {
	double etat_curr, valctr;
	etat_curr = state_->get_StateCurr();
	if(etat_curr > tresh_high_) {
		valctr = ctrl_min_;
	}
	else if(etat_curr < tresh_low_) {
		valctr = ctrl_max_;
	}
	else {
		valctr = etat_curr;
	}

	state_->set_valCtrl(valctr);

	server_->log_value(state_->get_valPhen());
	server_->log_value(etat_curr);
	server_->log_value(valctr);
}

