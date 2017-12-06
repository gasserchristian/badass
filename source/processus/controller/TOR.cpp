/*
 * TOR.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#include "TOR.h"

TOR::TOR(int ID, string name, Process* server, Process* state,
	double tresh_low, double tresh_high, double ctrl_min, double ctrl_max) :
		Control(ID, name, ctrl_max, tresh_high, state, server), tresh_low_(tresh_low), tresh_high_(tresh_high),
		ctrl_min_(ctrl_min), ctrl_max_(ctrl_max) {

}

TOR::~TOR() {
	// TODO Auto-generated destrucTOR stub
}

void TOR::update(double tic) {
	double etat_curr, valctr;
	Server* serv = dynamic_cast <Server*> (server_);
	etat_curr = state_->etatCurr();
	State* etat = dynamic_cast <State*> ( state_ );
	if(etat_curr > tresh_high_) {
		valctr = ctrl_min_;
		serv->log_journal(string("State ")
				+ to_string(ID_)
				+ " (\"" + string(name_) + "\"). Relative error command/state "
				+ to_string((etat_curr - consigne_)/consigne_*100)
				+ "%. Control activated, tresh_high.........");
	}
	else if(etat_curr < tresh_low_) {
		valctr = ctrl_max_;
		serv->log_journal(string("State ")
				+ to_string(ID_)
				+ " (\"" + string(name_) + "\"). Relative error command/state "
				+ to_string((etat_curr - consigne_)/consigne_*100)
				+ "%. Control activated, tresh_down.........");
	}
	else {
		valctr = 0;
	}

	etat->set_valCtrl(valctr);

	serv->log_value(etat->workValphen(0,false));
	serv->log_value(etat_curr);
	serv->log_value(valctr);
}

