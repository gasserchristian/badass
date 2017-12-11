/*
 * SIN.cpp
 *
 *  Created on: 6 déc. 2017
 *      Author: Christian
 */

#include "SIN.h"

void SIN::update(int tic) {
	double valeur = offset_ + ampl_ * sin((double)(tic + phase_)/period_*2*M_PI);
	valeur = valeur + sigma_*box_muller();
	state_->workValphen(valeur, true);
}

