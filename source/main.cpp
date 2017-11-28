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
	/*
	Simulator* Sim;
	Sim = parser();  //The parser will return the adress of the simulator
	Sim->run();
	*/



	/*
	Process* server = new Server();
	Process* etat1 = new State(6.5,1.0,5.0,6.4);
	Process* phenomene1 = new Phenomenon(etat1, 0, 1000);
	Process* controller1 = new Control(server, etat1, 20, 11);

	phenomene1->update();
	controller1->update();
	etat1->update();

	cout << controller1->etatCurr() << " " << controller1->workValphen() << endl;
	*/


	return 0;
}
