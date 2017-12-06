/*
 * SIN.cpp
 *
 *  Created on: 6 déc. 2017
 *      Author: Christian
 */

#include "SIN.h"

SIN::SIN(unsigned ID, std::string sin_name, Process* state, double sigma, double offset,
		double ampl, double phase, double sat_max, double sat_min) : sigma_(sigma), offset_(offset),
		ampl_(ampl), phase_(phase), sat_max_(sat_max), sat_min_(sat_min), Process(ID, sin_name) {

}

void SIN::update(double tic) {
	double valeur;
	state_->workValphen(valeur, true);
}

SIN::~SIN() {

}

