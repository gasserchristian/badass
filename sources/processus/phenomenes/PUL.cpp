/*
 * PUL.cpp
 *
 *  Created on: 6 déc. 2017
 *      Author: Christian
 */

#include "PUL.h"
#include <iostream> //DELETE AFTER

void PUL::update(int tic) {
	long int val = (tic - t_del_)%period_;
	double phen_val = v_low_;
	if(val < t_rise_) {
		phen_val = (double)val/t_rise_*(v_high_-v_low_)+v_low_;
	}
	else if(val < t_rise_+pwidth_) {
		phen_val = v_high_;
	}
	else if(val < t_rise_+pwidth_+t_fall_) {
		//phen_val = v_high_ - ((double)val-t_rise_+pwidth_)/t_fall_;
		phen_val = v_high_-((double)val-t_rise_-pwidth_)
				/t_fall_*(v_high_-v_low_);
	}
	phen_val = phen_val + sigma_*box_muller();
	state_->workValphen(phen_val, true);
}

