/*
 * server.cpp
 *
 *  Created on: 19 Nov 2017
 *      Author: maxch
 */

#include "Server.h"
#include <iomanip>
#include "time.h"

Server::Server(int nTicks, string tick_unit): nTicks_(nTicks), tick_unit_(tick_unit), temp_data_() {}

Server::~Server() {}

void Server::update(int tic) {
	//Write in GNU
	gnu_ << setprecision(3) << setw(15) << tic;
	for(unsigned int i=0; i< temp_data_.size(); i++) {
		gnu_ << setprecision(3) << setw(15) << temp_data_[i];
	}
	gnu_ << endl;
	temp_data_.clear();

	if(tic == nTicks_-1) {
		//Fermeture des fichiers:
		cout << "[i] ---- Simulation completed ----" << endl;
		Server::close_files();
	}
}


//Create and open files
void Server::create_files() {
	time_t rawtime;
	struct tm * timeinfo;
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	string journal = string("Creation time and date: ") + asctime(timeinfo);
	journal_.open("journal.txt");
	gnu_.open("gnu.txt");
	Server::log_journal(journal);
	journal = "Files created: journal.txt & gnu.txt";
	Server::log_journal(journal);
}

//JOURNAL
void Server::log_journal(string text) {
	journal_ << text << endl;
}

//GNU
void Server::gnu_header(int zone_count) {
	gnu_ << "# time[" << tick_unit_ << "]";
	for(int i = 0; i < zone_count; i++) {
		gnu_ << setw(15) << "val_phen" << i+1 << setw(15) << "state_curr"
			 << i+1 << setw(15) << "val_control" << i+1;
	}
	gnu_ << endl;
}

//Close all files
void Server::close_files() {
	journal_.close();
	gnu_.close();
}
