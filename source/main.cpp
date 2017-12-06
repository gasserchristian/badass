/*
 * main.cpp
 *
 *  Created on: 13 Nov 2017
 *      Author: maxch
 */

#include <list>
#include <string>
#include <stdio.h>
#include <iostream>
#include "./parseur/parser.h"
#include "./processus/Process.h"
#include "./processus/Control.h"
#include "./processus/Phenomenon.h"
#include "./processus/State.h"
#include "./processus/Server.h"
#include "Simulator.h"


using namespace std;

int main() {
	parser();
	//Simulator* Simulator_new = parser(); // le simulateur est lancé directement depuis la fonction parser
	//Simulator_new->run();
	return 0;
}
