/*
 * phenomenon.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#include "Phenomenon.h"

Phenomenon::Phenomenon(unsigned ID, string name, Process* state)
	: state_(state), Process(ID, name) {
}

Phenomenon::~Phenomenon() {
	// TODO Auto-generated destructor stub
}

