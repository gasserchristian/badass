/*
 * Random.cpp
 *
 *  Created on: Nov 27, 2017
 *      Author: pcoo13
 */

#include "RAND.h"

RAND::RAND(int ID, string name, Process* state, double val_min, double val_max)
	: val_min_(val_min), val_max_(val_max), Phenomenon(ID, name, state) {

}

RAND::~RAND() {

}

void RAND::update() {
	srand(time(NULL));
	double random = static_cast<double>(rand())*(val_max_-val_min_)/RAND_MAX;
	state_->workValphen(random, true);
}

