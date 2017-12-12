/*
 * parser.cpp
 *
 *  Created on: 13 Nov 2017
 *      Author: maxch
 */

#include "parser.h"
#include <limits>
#include <sstream>

void parse(Simulator* Sim)
{
	stringstream ss; //alternative method to 'to_string' C++11
	string journal;
	vector<Process*> Process_list;
	//vecteur contenant les pointeurs vers toutes les instances des classes filles de process
	//-------------LECTURE DU FICHIER XML ET GESTION ERREUR -------------------
	// import local adress of folder and use it to open paysage.xml
	TiXmlDocument doc("paysage.xml");
	bool loadOkay = doc.LoadFile();
	if ( !loadOkay )
	{
		printf( "[e] Impossible to read 'paysage.xml'. Error='%s' \n",
				doc.ErrorDesc() );
		exit( 1 );
	} else
	{
		printf( "[i] Successful read of 'paysage.xml'.\n");
	}
	TiXmlElement* child1 = doc.FirstChildElement();
		//méthode d'élément permet d'accéder au premier fils de l'arborescence
		//qui est l'élément Paysage

		//instancie de la classe serveur
		string tick_unit = child1->Attribute("tick_unit");
		int nTicks = atoi(child1->Attribute("nTicks"));
		Server* Server_new = new Server(nTicks, tick_unit);

		//création du fichier journal et gnu
		Server_new->create_files();
		cout << "[i] ---- Parsing the following instances: ----" << endl;
		journal = string("Ticks number: ") + child1->Attribute("nTicks");
		Server_new->log_journal(journal);
		journal = string("Tick unit: ") + child1->Attribute("tick_unit");
		Server_new->log_journal(journal);

		//instancie le simulateur
		Sim->set_nTicks(nTicks);
		journal = string("[i] New server");
		Server_new->log_journal(journal);
		cout << journal << endl;


		//--------------------- EXTRACTION DES ZONES: NIVEAU 1 -----------------------
		int zone_count = 0;
		for( TiXmlElement* child2 = child1->FirstChild("zone")->ToElement();
			child2;
			child2=child2->NextSiblingElement())
		{ //BOUCLE pour extraire l'ensemble des triplets "zone" du paysage
			// Détection d'un élément zone NIVEAU 2
			if (strcmp(child2->Value(),"zone")==0){
				journal = string("[i] New zone: ") + child2->Attribute("name");
				Server_new->log_journal(journal);
				cout << journal << endl;
				// EXTRACTION attribut nom de la zone: NIVEAU 3
				journal = string("Zone ID : ") + child2->Attribute( "ID");
				Server_new->log_journal(journal);
				// ---------EXTRACTION attribut ID de la zone: NIVEAU 3 ------------
				// ------------- EXTRACTION DE l'ETAT DE LA ZONE: NIVEAU 2
				TiXmlElement* child5 = child2->FirstChild("state")->ToElement();
				journal = string("New state: ") + child5->Attribute( "name");
				Server_new->log_journal(journal);
				cout << journal << endl;

				//instance State_new
				TiXmlElement* child6 = child5->FirstChild("param")->ToElement();
				int state_ID = atoi(child2->Attribute( "ID"));
				string state_name = child5->Attribute("name");
				double iphen = atof(child6->Attribute("iphen"));
				double ictrl = atof(child6->Attribute("ictrl"));
				double val_phen = 0, state_curr = 0; //optional values
				if (child6->Attribute("val_phen")) val_phen = atof(child6->Attribute("val_phen"));
				if (child6->Attribute("state_curr")) state_curr = atof(child6->Attribute("state_curr"));
				State* State_new = new State(state_ID, state_name, iphen, ictrl, val_phen, state_curr);
				ss << val_phen;
				string val_phen_string = ss.str();
				ss << state_curr;
				string state_curr_string = ss.str();
				journal = string("State ID: ") + child2->Attribute( "ID") + ", name: " + state_name +
								 ", iphen: " + child6->Attribute("iphen") + ", ictrl: " + child6->Attribute("ictrl") +
								 ", val_phen: " + val_phen_string + ", state_curr: " +
								 state_curr_string;
				Server_new->log_journal(journal);


				// ---------- EXTRACTION DU PHENOMENE: NIVEAU 2 --------------------
				TiXmlElement* child3 = child2->FirstChild("phenomenon")->ToElement () ;
				Phenomenon* Phenomenon_new;
				journal = string("New phenomenon : ") + child3->Attribute( "name");
				Server_new->log_journal(journal);
				cout << journal << endl;
				// EXTRACTION attribut nom du phenomene: NIVEAU 3
				journal = string("Phenomenon type : ") + child3->Attribute( "type");
				Server_new->log_journal(journal);

				// EXTRACTION DES PARAMETRES DU PHENOMENE SELON SON TYPE
				if (strcmp(child3->Attribute("type"),"sinus")==0){
					TiXmlElement* child4 = child3->FirstChild("param")->ToElement();

					//Instancie la classe fille de phénomène
					int sin_ID = atoi(child2->Attribute( "ID"));
					string sin_name = child3->Attribute( "name");
					double sin_std_dev = atof(child4->Attribute("std_dev"));
					double sin_ampl = atof(child4->Attribute("ampl"));
					int sin_period = atoi(child4->Attribute("period"));
					double sin_offs=0, sin_phase=0,
							sin_sat_max= std::numeric_limits<double>::infinity(),
							sin_sat_min=-sin_sat_max;
					if(child4->Attribute("offs")) sin_offs = atof(child4->Attribute("offs"));
					if(child4->Attribute("phase")) sin_phase = atoi(child4->Attribute("phase"));
					if(child4->Attribute("sat_max")) sin_sat_max = atof(child4->Attribute("sat_max"));
					if(child4->Attribute("sat_min")) sin_sat_min = atof(child4->Attribute("sat_min"));
					SIN* sin_new = new SIN(sin_ID, sin_name, State_new,
											sin_std_dev, sin_offs, sin_ampl, sin_phase,
											sin_period, sin_sat_max, sin_sat_min);
					Phenomenon_new = sin_new;
					ss << sin_offs;
					string sin_offs_string = ss.str();
					ss << sin_phase;
					string sin_phase_string = ss.str();
					ss << sin_sat_max;
					string sin_sat_max_string = ss.str();
					ss << sin_sat_min;
					string sin_sat_min_string = ss.str();
					journal = string("Sinus ID: ") + child2->Attribute( "ID") + ", name: "
									 + sin_name + ", std_dev: " + child4->Attribute("std_dev") +
									 ", offset: " + sin_offs_string + ", amplitude: " +
									 child4->Attribute("ampl") + ", phase: " + sin_phase_string
									  + ", period: " + child4->Attribute("period") +
									 ", sat_max: " + sin_sat_max_string +
									 ", sat_min: " + sin_sat_min_string;
					Server_new->log_journal(journal);

				}
				else if (strcmp(child3->Attribute("type"),"pulse")==0){
					// Détection d'un phénomène random
					TiXmlElement* child4 = child3->FirstChild("param")->ToElement();

					//Instancie la classe fille de processus
					int pul_ID = atoi(child2->Attribute( "ID"));
					string pul_name = child3->Attribute( "name");
					double pul_std_dev = atof(child4->Attribute("std_dev"));
					double pul_v_low = atof(child4->Attribute("v_low"));
					double pul_v_high = atof(child4->Attribute("v_high"));
					int pul_t_del = atoi(child4->Attribute("t_del"));
					int pul_t_rise = atoi(child4->Attribute("t_rise"));
					int pul_pwidth = atoi(child4->Attribute("pwidth"));
					int pul_t_fall = atoi(child4->Attribute("t_fall"));
					int pul_period = atoi(child4->Attribute("period"));
					PUL* pul_new = new PUL(pul_ID, pul_name, State_new,
											pul_std_dev, pul_v_low, pul_v_high,
											pul_t_del, pul_t_rise, pul_pwidth,
											pul_t_fall, pul_period);
					Phenomenon_new = pul_new;
					journal = string("Pulse ID: ") + child2->Attribute( "ID") + ", name: " + pul_name +
									 ", std_dev: " + child4->Attribute("std_dev") +
									 ", v_low: " + child4->Attribute("v_low") + ", v_high: " +
									 child4->Attribute("v_high") + ", t_del: " + child4->Attribute("t_del")
									 + ", t_rise: " + child4->Attribute("t_rise") + ", pwidth: "
									 + child4->Attribute("pwidth") + ", t_fall: " +
									 child4->Attribute("t_fall") + ", period: " + child4->Attribute("period");
					Server_new->log_journal(journal);
				}
				else{
					cout << "[e] Phenomenon type [" << child3->Attribute("type") <<
							"] not recognized by the parser.";
					exit( 1 );
				}

				// ------- EXTRACTION DU CONTROLE DE LA ZONE: NIVEAU 2
				TiXmlElement* child7 = child2->FirstChild("control")->ToElement();
				Control* Control_new;
				journal = string("New control : ") + child7->Attribute( "name");
				Server_new->log_journal(journal);
				cout << journal << endl;
				// EXTRACTION attribut nom du contrôle: NIVEAU 3
				journal = string("Control type : ") + child7->Attribute( "type");
				Server_new->log_journal(journal);


				// EXTRACTION attribut type du contrôle: NIVEAU 3
				if (strcmp(child7->Attribute("type"),"TOR")==0){
					// Détection d'un controleur de type tout ou rien
					TiXmlElement* child8 = child7->FirstChild("param")->ToElement();

					//instancie la classe fille de control
					int TOR_ID = atoi(child2->Attribute( "ID"));
					string TOR_name = child3->Attribute( "name");
					double tresh_low = atof(child8->Attribute("tresh_low"));
					double tresh_high = atof(child8->Attribute("tresh_high"));
					double ctrl_min = atof(child8->Attribute("ctrl_min"));
					double ctrl_max = atof(child8->Attribute("ctrl_max"));
					TOR* TOR_new = new TOR(TOR_ID, TOR_name, Server_new, State_new,
											tresh_low, tresh_high, ctrl_min, ctrl_max);
					Control_new = TOR_new;
					journal = string("TOR ID:") + child2->Attribute( "ID") + ", name: " + TOR_name +
									 ", tresh_low: " + child8->Attribute("tresh_low") + ", tresh_high: "
									 + child8->Attribute("tresh_high") + ", ctrl_min: " + child8->Attribute("ctrl_min")
									 + ", ctrl_max: " + child8->Attribute("ctrl_max");
					Server_new->log_journal(journal);


				}
				else if (strcmp(child7->Attribute("type"),"P")==0){
					// Détection d'un controleur de type proportionnel

					TiXmlElement* child8 = child7->FirstChild("param")->ToElement();

					//instancie la classe fille de control
					int P_ID = atoi(child2->Attribute( "ID"));
					string P_name = child3->Attribute( "name");
					double set_point = atof(child8->Attribute("set_point"));
					double gain = atof(child8->Attribute("gain"));
					double val_sat = atof(child8->Attribute("val_sat"));
					P* P_new = new P(P_ID, P_name, Server_new, State_new,
											set_point, gain, val_sat);
					Control_new = P_new;
					journal = string("Proportionnal ID:") + child2->Attribute( "ID") + ", name: "
									 + P_name + ", set_point: " + child8->Attribute("set_point")
									 + ", gain: " + child8->Attribute("gain") + ", val_sat: " +
									 child8->Attribute("val_sat");
					Server_new->log_journal(journal);
				}

				else{
					cout << "[e] Controller type [" << child7->Attribute("type") <<
							"] not recognized by the parser.";
					exit( 1 );
				}
				// élément autre que zone

				// population de la liste de processus dans le bon ordre
				Sim->set_process_list(Phenomenon_new);
				Process* State_n = State_new;
				Sim->set_process_list(State_n);
				Sim->set_process_list(Control_new);
				zone_count++;
			}
		}
		Server_new->gnu_header(zone_count);
		Process* Serv = Server_new;
		Sim->set_process_list(Serv);
		journal = "[i] ---- Parser complete, now running simulator... ----";
		Server_new->log_journal(journal);
		cout << journal << endl;
}


