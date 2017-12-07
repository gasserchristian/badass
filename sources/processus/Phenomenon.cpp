/*
 * phenomenon.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#include "Phenomenon.h"

Phenomenon::Phenomenon(unsigned ID, string name, Process* state)
	: Process(ID, name), state_(state)  {
}

