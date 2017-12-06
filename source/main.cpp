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
	Simulator* Sim = new Simulator();
	parser(Sim);
	Sim->run();
	return 0;
}
