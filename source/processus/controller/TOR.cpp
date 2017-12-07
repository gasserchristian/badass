/*
 * TOR.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#include "TOR.h"
#include <iostream> //DELETE AFTER

TOR::TOR(int ID, string name, Process* server, Process* state,
	double tresh_low, double tresh_high, double ctrl_min, double ctrl_max) :
		Control(ID, name, ctrl_max, tresh_high, state, server), tresh_low_(tresh_low), tresh_high_(tresh_high),
		ctrl_min_(ctrl_min), ctrl_max_(ctrl_max) {

}

TOR::~TOR() {
}

void TOR::update(int tic) {
	cout << "ctrl1" << endl;
	double etat_curr, valctr;
	Server* serv = dynamic_cast <Server*> (server_);
	etat_curr = state_->etatCurr();
	State* etat = dynamic_cast <State*> ( state_ );
	if(etat_curr > tresh_high_) {
		cout << "ctrl2" << endl;
		valctr = ctrl_min_;
		serv->log_journal(string("State ")
				+ to_string(ID_)
				+ " (\"" + string(name_) + "\"). Relative error command/state "
				+ to_string((etat_curr - consigne_)/consigne_*100)
				+ "%. Control activated, tresh_high.........");
	}
	else if(etat_curr < tresh_low_) {
		cout << "ctrl3" << endl;
		valctr = ctrl_max_;
		/*
		serv->log_journal(string("State ")
				+ to_string(ID_)
				+ " (\"" + string(name_) + "\"). Relative error command/state "
				+ to_string((etat_curr - consigne_)/consigne_*100)
				+ "%. Control activated, tresh_down.........");
		*/
		cout << "ctrl3" << endl;
	}
	else {
		cout << "ctrl4" << endl;
		valctr = 0;
	}
	cout << "ctrl4" << endl;
	etat->set_valCtrl(valctr);
	cout << "ctrl4" << endl;
	serv->log_value(etat->workValphen(0,false));
	cout << "ctrl4" << endl;
	serv->log_value(etat_curr);
	cout << "ctrl4" << endl;
	serv->log_value(valctr);
	cout << "ctrl4" << endl;
}

