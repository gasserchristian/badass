/*
 * TOR.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#include "TOR.h"
#include <cassert>
#include <sstream>

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
	stringstream ss1, ss2; //alternative method to 'to_string' C++11
	ss1 << tic;
	string tic_string = ss1.str();
	ss2 << etat_curr;
	string etat_curr_string = ss2.str();
	if(etat_curr>state_curr_max_) {
		state_curr_max_ = etat_curr;
		journal = string("[Tick: ") + tic_string + "] -- [State: " + state_->get_Statename()
				+ "] reached a new maximum at " + etat_curr_string;
		server_->log_journal(journal);
	}
	else if(etat_curr<state_curr_min_) {
		state_curr_min_ = etat_curr;
		journal = string("[Tick: ") + tic_string + "] -- [State: " + state_->get_Statename()
				+ "] reached a new minimum at " + etat_curr_string;
		server_->log_journal(journal);
	}
	static bool on = true;
	if(valctr == etat_curr && on == true) {
		on = false;
		journal = string("[Tick: ") + tic_string + "] -- " + name_ +
				" controller has switched OFF";
		server_->log_journal(journal);
	}
	if(valctr != etat_curr && on == false) {
		on = true;
		journal = string("[Tick: ") + tic_string + "] -- " + name_ +
				" controller has switched ON";
		server_->log_journal(journal);
	}
}

