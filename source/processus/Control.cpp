/*
 * control.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#include "Control.h"

Control::Control() : Process(0, "no name"), val_sat_(0.0), consigne_(0.0),
server_(NULL), state_(NULL) {

}

Control::Control(int ID, string name, double val_sat, double consigne,
		Process* server, Process* state) :
			Process(ID, name), val_sat_(val_sat), consigne_(consigne),
			server_(server), state_(state) {

}

