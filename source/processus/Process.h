/*
 * processus.h
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#ifndef SOURCES_PROCESSUS_PROCESS_H_
#define SOURCES_PROCESSUS_PROCESS_H_

#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;

class Process {
public:
	Process() : ID_(0), name_("no name") {}
	Process(unsigned ID, string name);
	virtual ~Process();

	// autres
	virtual void update(int tic) = 0;
	virtual double workValphen(double val = 0, bool set = false) = 0;
	virtual double etatCurr(double val = 0, bool set = false) = 0;

	/*
	//create and open files
	virtual void create_files() {};

	//Journal
	virtual void log_file(std::string text) {};

	//GNU
	virtual void gnu_header(int zone_count) {};
	virtual void log_file(double value) {};
	virtual void gnu_endl() {};

	//close all files
	virtual void close_files() {};
	*/


protected:
	unsigned ID_;
	string name_;
};

#endif /* SOURCES_PROCESSUS_PROCESS_H_ */
