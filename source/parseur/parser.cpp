/*
 * parser.cpp
 *
 *  Created on: 13 Nov 2017
 *      Author: maxch
 */

#include "parser.h"
#include <limits>


double parser()
{
	string journal;
	vector<Process*> Process_list;
	//vecteur contenant les pointeurs vers toutes les instances des classes filles de process
	//-------------LECTURE DU FICHIER XML ET GESTION ERREUR -------------------
	// import local adress of folder and use it to open paysage.xml
	TiXmlDocument doc("paysage.xml");
	bool loadOkay = doc.LoadFile();
	if ( !loadOkay )
	{
		printf( "Lecture impossible du fichier 'paysage.xml'. Error='%s' \n",
				doc.ErrorDesc() );
		exit( 1 );
	} else
	{
		printf( "Lecture correcte du fichier 'paysage.xml'.\n");
	}
	TiXmlElement* child1 = doc.FirstChildElement();
		//méthode d'élément permet d'accéder au premier fils de l'arborescence
		//qui est l'élément Paysage

		//instancie de la classe serveur
		string tick_unit = child1->Attribute("tick_unit");
		Server* Server_new = new Server(tick_unit);

		Server_new->create_files(); 			//création du fichier journal et gnu
		journal = "---- Parsing the following values:";
		Server_new->log_file(journal);
		journal = string("Nombre de Ticks : ") + child1->Attribute("nTicks");
		Server_new->log_file(journal);
		cout << journal << endl;
		journal = string("Durée de la simulation : ") + child1->Attribute("nTicks")
						 + child1->Attribute("tick_unit");
		Server_new->log_file(journal);
		cout << journal << endl;

		//instancie le simulateur
		Simulator* Simulator_new = new Simulator(child1->Attribute("nTicks"));

		//--------------------- EXTRACTION DES ZONES: NIVEAU 1 -----------------------
		for( TiXmlElement* child2 = child1->FirstChild("zone")->ToElement();
			child2;
			child2=child2->NextSiblingElement())
		{ //BOUCLE pour extraire l'ensemble des triplets "zone" du paysage
			// Détection d'un élément zone NIVEAU 2
			if (strcmp(child2->Value(),"zone")==0){
				journal = string("Nom de la zone : ") + child2->Attribute("name");
				Server_new->log_file(journal);
				cout << journal << endl;
				// EXTRACTION attribut nom de la zone: NIVEAU 3
				journal = string("ID unique de la zone : ") + child2->Attribute( "ID");
				Server_new->log_file(journal);
				cout << journal << endl;
				// ---------EXTRACTION attribut ID de la zone: NIVEAU 3 ------------
				// ------------- EXTRACTION DE l'ETAT DE LA ZONE: NIVEAU 2
				TiXmlElement* child5 = child2->FirstChild("state")->ToElement();
				journal = string("Nom de l'état : ") + child5->Attribute( "name");
				Server_new->log_file(journal);
				cout << journal << endl;
				TiXmlElement* child6 = child5->FirstChild("param")->ToElement();
				journal = string("Valeur iphen : ") + child6->Attribute( "iphen");
				Server_new->log_file(journal);
				cout << journal << endl;
				journal = string("Valeur ictrl : ") + child6->Attribute( "ictrl");
				Server_new->log_file(journal);
				cout << journal << endl;

				//instance State_new
				int state_ID = atoi(child2->Attribute( "ID"));
				string state_name = child5->Attribute("name");
				double iphen = atof(child6->Attribute("iphen"));
				double ictrl = atof(child6->Attribute("ictrl"));
				double val_phen = 0, state_curr = 0; //optional values
				if (child6->Attribute("val_phen")) val_phen = atof(child6->Attribute("val_phen"));
				if (child6->Attribute("state_curr")) state_curr = atof(child6->Attribute("state_curr"));
				Process* State_new = new State(state_ID, state_name, iphen, ictrl, val_phen, state_curr);



				// EXTRACTION attribut nom de l'état: NIVEAU 3

				// ---------- EXTRACTION DU PHENOMENE: NIVEAU 2 --------------------
				TiXmlElement* child3 = child2->FirstChild("phenomenon")->ToElement () ;
				Phenomenon* Phenomenon_new;
				journal = string("Nom du phénomène : ") + child3->Attribute( "name");
				Server_new->log_file(journal);
				cout << journal << endl;
				// EXTRACTION attribut nom du phenomene: NIVEAU 3
				journal = string("type du phénomène : ") + child3->Attribute( "type");
				Server_new->log_file(journal);
				cout << journal << endl;
				//----- EXTRACTION attribut type du phenomene: NIVEAU 3 ----------
				// EXTRACTION DES PARAMETRES DU PHENOMENE SELON SON TYPE : NIVEAU 4
				if (strcmp(child3->Attribute("type"),"sinus")==0){
					// Détection d'un phénomène random
					TiXmlElement* child4 = child3->FirstChild("param")->ToElement();

					//Instancie la classe fille de processus
					int sin_ID = atoi(child2->Attribute( "ID"));
					string sin_name = child3->Attribute( "name");
					double sin_std_dev = atof(child4->Attribute("std_dev"));
					double sin_ampl = atof(child4->Attribute("ampl"));
					double sin_offs=0, sin_phase=0,
							sin_sat_max= std::numeric_limits<double>::infinity(),
							sin_sat_min=-sin_sat_max;
					if((child4->Attribute("offs")) sin_offs = atof(child4->Attribute("offs"));
					if(child4->Attribute("phase")) sin_phase = atof(child4->Attribute("phase"));
					if(child4->Attribute("sat_max")) sin_sat_max = atof(child4->Attribute("sat_max"));
					if(child4->Attribute("sat_min")) sin_sat_min = atof(child4->Attribute("sat_min"));
					SIN* sin_new = new SIN(sin_ID, sin_name, State_new,
											sin_std_dev, sin_offs, sin_ampl,
											sin_phase, sin_sat_max, sin_sat_min);
					Phenomenon_new = sin_new;

					//Journalisation de la nouvelle instance
					journal = string("phénomène minimum : ") + child4->Attribute( "min");
					Server_new->log_file(journal);
					cout << journal << endl;
					journal = string("phénomène maximum : ") + child4->Attribute( "max");
					Server_new->log_file(journal);
					cout << journal << endl;
				}
				if (strcmp(child3->Attribute("type"),"pulse")==0){
					// Détection d'un phénomène random
					TiXmlElement* child4 = child3->FirstChild("param")->ToElement();

					//Instancie la classe fille de processus
					int pul_ID = atoi(child2->Attribute( "ID"));
					string pul_name = child3->Attribute( "name");
					double pul_std_dev = atof(child4->Attribute("std_dev"));
					double pul_v_low = atof(child4->Attribute("v_low"));
					double pul_v_high = atof(child4->Attribute("v_high"));
					double pul_t_del = atof(child4->Attribute("v_t_del"));
					double pul_t_rise = atof(child4->Attribute("v_t_rise"));
					double pul_pwidth = atof(child4->Attribute("v_pwidth"));
					double pul_t_fall = atof(child4->Attribute("v_t_fall"));
					double pul_period = atof(child4->Attribute("v_period"));
					PUL* pul_new = new PUL(pul_ID, pul_name, State_new,
											pul_std_dev, pul_v_low, pul_v_high,
											pul_t_del, pul_t_rise, pul_pwidth,
											pul_t_fall, pul_period);
					Phenomenon_new = pul_new;

					//Journalisation de la nouvelle instance
					journal = string("phénomène minimum : ") + child4->Attribute( "min");
					Server_new->log_file(journal);
					cout << journal << endl;
					journal = string("phénomène maximum : ") + child4->Attribute( "max");
					Server_new->log_file(journal);
					cout << journal << endl;
				}


				// ------- EXTRACTION DU CONTROLE DE LA ZONE: NIVEAU 2
				TiXmlElement* child7 = child2->FirstChild("control")->ToElement();
				Control* Control_new;
				journal = string("Nom du controle : ") + child7->Attribute( "name");
				Server_new->log_file(journal);
				cout << journal << endl;
				// EXTRACTION attribut nom du contrôle: NIVEAU 3
				journal = string("Type du controle : ") + child7->Attribute( "type");
				Server_new->log_file(journal);
				cout << journal << endl;
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
				}
				if (strcmp(child7->Attribute("type"),"P")==0){
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
				}

				else {
					journal =  string("Ce n'est pas une zone, il s'agit de la balise : ")
									 + child2->Value();
					Server_new->log_file(journal);
					cout << journal << endl;
				}
				// élément autre que zone

				// population de la liste de processus dans le bon ordre
				Simulator_new->set_process_list(Phenomenon_new);
				Simulator_new->set_process_list(State_new);
				Simulator_new->set_process_list(Control_new);
			}
		}
		Process* Serv = Server_new;
		Simulator_new->set_process_list(Serv);

		//Instance simulateur
		int nTicks = atoi(child1->Attribute("nTicks"));

		journal = "----- Parser complete, now running simulator...";
		Server_new->log_file(journal);
		cout << journal << endl;

		return Simulator_new;
}


