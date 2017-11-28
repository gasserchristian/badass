/*
 * TOR.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#include "TOR.h"

TOR::TOR(int ID, string name, Process* server, Process* state, double val_sat, double consigne) :
 Control(ID, name, val_sat, consigne), state_(state), server_(server) {

}

TOR::~TOR() {
	// TODO Auto-generated destructor stub
}

void TOR::update() {
	double etat_curr, valctr;
	etat_curr = state_->etatCurr();
	State* etat = dynamic_cast <State*> ( state_ );
	if(etat_curr <= consigne_) {
		valctr = val_sat_;
	}
	else {
		valctr = 0;
	}

	etat->set_valCtrl(valctr);

	Server* serv = dynamic_cast <Server*> (server_);
	serv->log_file(etat->workValphen(0,false), false);
	serv->log_file(etat_curr, false);
	serv->log_file(valctr);
}

