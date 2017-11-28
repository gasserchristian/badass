/*
 * control.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#include "Control.h"

Control::Control() {

}

Control::Control(int ID, string name, double val_sat, double consigne) :
			val_sat_(val_sat), consigne_(consigne), Process(ID, name) {

}

Control::~Control() {
	// TODO Auto-generated destructor stub
}

