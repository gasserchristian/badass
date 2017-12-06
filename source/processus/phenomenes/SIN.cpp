/*
 * SIN.cpp
 *
 *  Created on: 6 déc. 2017
 *      Author: Christian
 */

#include "SIN.h"

SIN::SIN(unsigned ID, std::string sin_name, Process* state, double sigma, double offset,
		double ampl, long int phase, long int period, double sat_max, double sat_min) :
		Phenomenon(ID, sin_name, state), sigma_(sigma), offset_(offset), ampl_(ampl), phase_(phase),
			period_(period), sat_max_(sat_max), sat_min_(sat_min) {
}

void SIN::update(unsigned tic) {
	double valeur = offset_ + ampl_ * sin((tic + phase_)/period_*2*M_PI);
	valeur = valeur + sigma_*box_muller();
	state_->workValphen(valeur, true);
}

SIN::~SIN() {

}

