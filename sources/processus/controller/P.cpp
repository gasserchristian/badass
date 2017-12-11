/*
 * P.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#include "P.h"

void P::update(int tic) {
	double etat_curr, valctr;
	etat_curr = state_->get_StateCurr();
	valctr = etat_curr + gain_ * (set_point_ - etat_curr);

	if(valctr > sat_) {
		valctr = sat_;
		server_->log_journal(string("State ")
				+ to_string(ID_)
				+ " (\"" + string(name_) + "\"). Relative error command/state "
				+ to_string((etat_curr - consigne_)/consigne_*100)
				+ "%. Saturation (+ saturation) of control reached.........");
	}
	else if(valctr < -sat_) {
		valctr = - sat_;
		server_->log_journal(string("State ")
				+ to_string(ID_)
				+ " (\"" + string(name_) + "\"). Relative error command/state "
				+ to_string((etat_curr - consigne_)/consigne_*100)
				+ "%. Saturation () of control reached.........");
	}

	state_->set_valCtrl(valctr);

	server_->log_value(state_->get_valPhen());
	server_->log_value(etat_curr);
	server_->log_value(valctr);
}
