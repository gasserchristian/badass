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
	}
	else if(valctr < -sat_) {
		valctr = - sat_;
	}

	state_->set_valCtrl(valctr);

	//Log values in the GNU file
	server_->log_value(state_->get_valPhen());
	server_->log_value(etat_curr);
	server_->log_value(valctr);

	//Messages for the journal
	string journal;
	if(etat_curr>state_curr_max_) {
		state_curr_max_ = etat_curr;
		journal = string("[Tick: ") + to_string(tic) + "] -- [State: " + state_->get_Statename()
				+ "] reached a new maximum at " + to_string(etat_curr);
		server_->log_journal(journal);
	}
	if(etat_curr<state_curr_min_) {
		state_curr_min_ = etat_curr;
		journal = string("[Tick: ") + to_string(tic) + "] -- [State: " + state_->get_Statename()
				+ "] reached a new minimum at " + to_string(etat_curr);
		server_->log_journal(journal);
	}
}
