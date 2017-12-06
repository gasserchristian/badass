/*
 * main.cpp
 *
 *  Created on: 13 Nov 2017
 *      Author: maxch
 */

#include "./parseur/parser.h"
#include "Simulator.h"


using namespace std;

int main() {
	Simulator* Sim = new Simulator();
	parse(Sim);
	Sim->run();
	return 0;
}
