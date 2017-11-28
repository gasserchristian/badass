/*
 * server.cpp
 *
 *  Created on: 19 Nov 2017
 *      Author: maxch
 */

#include "Server.h"

Server::Server(string tick_unit): tick_unit_(tick_unit) {}

Server::~Server() {}

//Create and open files
void Server::create_files() {
	journal_.open("journal.txt");
	gnu_.open("gnu.txt");
}

//JOURNAL
void Server::log_file(string text) {
	journal_ << text << endl;
}

//GNU
void Server::gnu_header(int zone_count) {
	gnu_ << "# time[" << tick_unit_ << "]";
	for(int i = 0; i < zone_count; i++) {
		gnu_ << "    val_phen" << i+1 << "    state_curr" << i+1 << "   val_control" << i+1;
	}
	gnu_ << endl;
}

void Server::log_file(double value) {
	gnu_ << value << "    ";
}

void Server::gnu_endl() {
	gnu_ << endl;
}

//Close all files
void Server::close_files() {
	journal_.close();
	gnu_.close();
}
