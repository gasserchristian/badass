/*
 * server.h
 *
 *  Created on: 19 Nov 2017
 *      Author: maxch
 */

#ifndef SOURCE_SERVER_H_
#define SOURCE_SERVER_H_
#include "Process.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Server : public Process {
public:
	Server(int nTicks, std::string tick_unit);
	virtual ~Server();
	void update(int tic);

	//create and open files
	void create_files();

	//Journal
	void log_journal(std::string text);

	//GNU
	void gnu_header(int zone_count);
	void log_value(double value) {temp_data_.push_back(value);}
	void gnu_endl();

	//close all files
	void close_files();

private:
	std::ofstream journal_;
	std::ofstream gnu_;
	int nTicks_;
	std::string tick_unit_;
	vector<double>temp_data_; //data per tick to store in GNU
};



#endif /* SOURCE_SERVER_H_ */
