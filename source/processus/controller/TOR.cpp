/*
 * TOR.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#include "TOR.h"

TOR::TOR(int ID, string name, Process* server, Process* state, double val_sat, double consigne) :
 Control(ID, name, server, state, val_sat, consigne) {

}

TOR::~TOR() {
	// TODO Auto-generated destructor stub
}

void TOR::update() {
	cout << "step" << endl;
	double etat_curr;
	cout << "step" << endl;
	etat_curr = state_->etatCurr();
	cout << "step" << endl;
	State* etat = dynamic_cast <State*> ( state_ );
	cout << "step" << endl;
	if(etat_curr <= consigne_) {
		cout << "step" << endl;
		etat->set_valCtrl(val_sat_);
	}
	else {
		etat->set_valCtrl(0);
	}
	cout << "step" << endl;
	Server* serv = dynamic_cast <Server*> (server_);
	cout << "step" << endl;
	serv->log_file(etat_curr, false);
	cout << "step" << endl;
	serv->log_file(etat->workValphen(0,false), false);
	serv->log_file(etat_curr, false);

}

