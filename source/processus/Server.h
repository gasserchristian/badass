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

class Server : public Process {
public:
	Server(std::string tick_unit);
	virtual ~Server();

	virtual void update() {};
	virtual double workValphen(double val = 0, bool set = false) { return NULL; }
	virtual double etatCurr(double val = 0, bool set = false) { return NULL; }

	//create and open files
	void create_files();

	//Journal
	void log_file(std::string text);

	//GNU
	void gnu_header(int zone_count);
	void log_file(double value);
	void gnu_endl();

	//close all files
	void close_files();

private:
	std::ofstream journal_;
	std::ofstream gnu_;
	std::string tick_unit_;
};



#endif /* SOURCE_SERVER_H_ */
