/*
 * server.h
 *
 *  Created on: 19 Nov 2017
 *      Author: maxch
 */

#ifndef SOURCE_SERVER_H_
#define SOURCE_SERVER_H_
#include "Process.h"
#include "..\Simulator.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Server : public Process {
public:
	Server(string tick_unit);
	virtual ~Server();

	virtual void update() {};
	virtual double workValphen(double val = 0, bool set = false) { return NULL; }
	virtual double etatCurr(double val = 0, bool set = false) { return NULL; }

	//create and open files
	virtual void create_files();

	//Journal
	virtual void log_file(string text);

	//GNU
	virtual void log_file(double value, bool end_line);

	//close all files
	virtual void close_files();

private:
	ofstream journal_;
	ofstream gnu_;
	string tick_unit_;
};



#endif /* SOURCE_SERVER_H_ */
