/*
 * P.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#include "P.h"

P::P(int ID, string name, Process* server, Process* state,
		double set_point, double gain, double sat) :
	set_point_(set_point), gain_(gain), Control(ID, name, gain, set_point, server, state), sat_(sat) {

}

P::~P() {

}


void P::update() {
	double etat_curr, valctr;
	Server* serv = dynamic_cast <Server*> (server_);
	etat_curr = state_->etatCurr();
	State* etat = dynamic_cast <State*> ( state_ );
	valctr = gain_ * (set_point_ - etat_curr);

	if(valctr > sat_) {
		valctr = sat_;
		serv->log_file(string("State ")
				+ to_string(ID_)
				+ " (\"" + string(name_) + "\"). Relative error command/state "
				+ to_string((etat_curr - consigne_)/consigne_*100)
				+ "%. Saturation (+ saturation) of control reached.........");
	}
	else if(valctr < -sat_) {
		valctr = - sat_;
		serv->log_file(string("State ")
				+ to_string(ID_)
				+ " (\"" + string(name_) + "\"). Relative error command/state "
				+ to_string((etat_curr - consigne_)/consigne_*100)
				+ "%. Saturation () of control reached.........");
	}

	etat->set_valCtrl(valctr);

	serv->log_file(etat->workValphen(0,false));
	serv->log_file(etat_curr);
	serv->log_file(valctr);
}
