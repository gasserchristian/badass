/*
 * PUL.cpp
 *
 *  Created on: 6 déc. 2017
 *      Author: Christian
 */

#include "PUL.h"


void PUL::update(int tic) {
<<<<<<< HEAD
	long int val = (tic - t_del_)%period_;
	double phen_val = v_low_;
	if(val < t_rise_) {
		phen_val = val/t_rise_*v_high_;
	}
	else if(val < t_rise_+pwidth_) {
		phen_val = v_high_;
	}
	else if(val < t_rise_+pwidth_+t_fall_) {
		phen_val = v_high_ - (val-t_rise_+pwidth_)/t_fall_;
	}
	state_->workValphen(phen_val, true);
=======
	//tic : intervale
>>>>>>> e76a824edcc34f60e078cd3444d51c138fb03ebc
}

