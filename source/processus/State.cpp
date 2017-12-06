/*
 * State.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#include "State.h"

void State::update(int tic) {
	State_curr_ = State_curr_
			+ (val_phen_ - State_curr_) * I_phen_
			+ (val_ctrl_ - State_curr_) * I_ctrl_;
}
