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
	gnu_ << "# time[" << tick_unit_ << "]   " << endl;
	// mettre ici le reste des headers du gnu et enlever le endl au dessus  val_phen   state_curr    val_control"
}

//JOURNAL
void Server::log_file(string text) {
	journal_ << text << endl;
}

//GNU
void Server::log_file(double value, bool end_line) {
	if(end_line) gnu_ << value << endl;
	else gnu_ << value << " ";
}

//Close all files
void Server::close_files() {
	journal_.close();
	gnu_.close();
}
