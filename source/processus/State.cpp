/*
 * State.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#include "State.h"

State::State(int ID, string name, double i_phen, double i_ctrl,
			 double val_phen, double state_curr)
	: State_curr_(state_curr), I_phen_(i_phen), I_ctrl_(i_ctrl),
	  val_phen_(val_phen), val_ctrl_(0.0), Process(ID, name) {}

State::~State() {}


void State::update(unsigned tic) {
	State_curr_ = State_curr_
			+ (val_phen_ - State_curr_) * I_phen_
			+ (val_ctrl_ - State_curr_) * I_ctrl_;
}
