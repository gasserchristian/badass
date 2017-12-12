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
	static bool on = true;
	if(valctr == etat_curr && on == true) {
		on = false;
		journal = string("[Tick: ") + to_string(tic) + "] -- " + name_ +
				" controller has switched OFF";
		server_->log_journal(journal);
	}
	if(valctr != etat_curr && on == false) {
		on = true;
		journal = string("[Tick: ") + to_string(tic) + "] -- " + name_ +
				" controller has switched ON";
		server_->log_journal(journal);
	}
}

