/*
 * parser.cpp
 *
 *  Created on: 13 Nov 2017
 *      Author: maxch
 */

#include "parser.h"


void parser()
//Simulator* parser()
{
	string journal;
	vector<Process*> Process_list;		    //vecteur contenant les pointeurs vers toutes les instances des classes filles de process
	//-------------LECTURE DU FICHIER XML ET GESTION ERREUR -------------------------------
	// import local adress of folder and use it to open paysage.xml
	TiXmlDocument doc("paysage.xml");
	bool loadOkay = doc.LoadFile();
	if ( !loadOkay )
	{
		printf( "Lecture impossible du fichier 'paysage.xml'. Error='%s' \n", doc.ErrorDesc() );
		exit( 1 );
	} else
	{
		printf( "Lecture correcte du fichier 'paysage.xml'.\n");
	}
	TiXmlElement* child1 = doc.FirstChildElement();
		//méthode d'élément permet d'accéder au premier fils de l'arborescence qui est l'élément Paysage

		//instancie de la classe serveur
		string tick_unit = child1->Attribute("tick_unit");
		Server* Server_new = new Server(tick_unit);

		Server_new->create_files(); 			//création du fichier journal et gnu
		journal = string("Nombre de Ticks : ") + child1->Attribute("nTicks");
		Server_new->log_file(journal);
		cout << journal << endl;
		journal = string("Durée de la simulation : ") + child1->Attribute("nTicks") + child1->Attribute("tick_unit");
		Server_new->log_file(journal);
		cout << journal << endl;
		//--------------------- EXTRACTION DES ZONES: NIVEAU 1 -----------------------
		for( TiXmlElement* child2 = child1->FirstChild("zone")->ToElement();
			child2;
			child2=child2->NextSiblingElement())
		{ //BOUCLE pour extraire l'ensemble des triplets "zone" du paysage

			if (strcmp(child2->Value(),"zone")==0){ // Détection d'un élément zone NIVEAU 2 -------
				journal = string("Nom de la zone : ") + child2->Attribute("name");
				Server_new->log_file(journal);
				cout << journal << endl;
				// EXTRACTION attribut nom de la zone: NIVEAU 3
				journal = string("ID unique de la zone : ") + child2->Attribute( "ID");
				Server_new->log_file(journal);
				cout << journal << endl;
				// ----------------- EXTRACTION attribut ID de la zone: NIVEAU 3 ---------------------------------

				// ------------------------------ EXTRACTION DE l'ETAT DE LA ZONE: NIVEAU 2
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
				int state_ID = stoi(child2->Attribute( "ID"));
				string state_name = child5->Attribute("name");
				double iphen = stod(child6->Attribute("iphen"));
				double ictrl = stod(child6->Attribute("ictrl"));
				Process* State_new;
				if (child6->Attribute("val_phen") && child6->Attribute("state_curr")) {
					double val_phen = stod(child6->Attribute("val_phen"));
					double state_curr = stod(child6->Attribute("state_curr"));
					State_new = new State(state_ID, state_name, iphen, ictrl, val_phen, state_curr);
				}
				else {
					State_new = new State(state_ID, state_name, iphen, ictrl);
				}



				// EXTRACTION attribut nom de l'état: NIVEAU 3

				// ------------------------------ EXTRACTION DU PHENOMENE: NIVEAU 2 --------------------
				TiXmlElement* child3 = child2->FirstChild("phenomenon")->ToElement () ;
				Phenomenon* Phenomenon_new;
				journal = string("Nom du phénomène : ") + child3->Attribute( "name");
				Server_new->log_file(journal);
				cout << journal << endl;
				// EXTRACTION attribut nom du phenomene: NIVEAU 3
				journal = string("type du phénomène : ") + child3->Attribute( "type");
				Server_new->log_file(journal);
				cout << journal << endl;
				//----------- EXTRACTION attribut type du phenomene: NIVEAU 3 -------------------------
				// --------------------- EXTRACTION DES PARAMETRES DU PHENOMENE SELON SON TYPE : NIVEAU 4 ---------
				if (strcmp(child3->Attribute("type"),"random")==0){
					// Détection d'un phénomène random
					TiXmlElement* child4 = child3->FirstChild("param")->ToElement();

					//Instancie la classe fille de processus
					int rand_ID = stoi(child2->Attribute( "ID"));
					string rand_name = child3->Attribute( "name");
					double rand_min = stod(child4->Attribute("min"));
					double rand_max = stod(child4->Attribute("max"));
					RAND* Rand_new = new RAND(rand_ID, rand_name, State_new, rand_min, rand_max);
					Phenomenon_new = Rand_new;
					// ---------- EXTRACTION d’une seule série de paramètres pour le sinus: NIVEAU 4 -------------
					journal = string("phénomène minimum : ") + child4->Attribute( "min");
					Server_new->log_file(journal);
					cout << journal << endl;
					// EXTRACTION paramètre offset du phenomene: NIVEAU 5
					journal = string("phénomène maximum : ") + child4->Attribute( "max");
					Server_new->log_file(journal);
					cout << journal << endl;
					// EXTRACTION paramètre ampl du phenomene: NIVEAU 5
				}


				// ------------------------------ EXTRACTION DU CONTROLE DE LA ZONE: NIVEAU 2
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
					int TOR_ID = stoi(child2->Attribute( "ID"));
					string TOR_name = child3->Attribute( "name");
					double tresh_high = stod(child8->Attribute("tresh_high"));
					double ctrl_min = stod(child8->Attribute("ctrl_min"));
					TOR* TOR_new = new TOR(TOR_ID, TOR_name, Server_new, State_new, tresh_high, ctrl_min);
					Control_new = TOR_new;

				}
				else {
					journal =  string("Ce n'est pas une zone, il s'agit de la balise : ") + child2->Value();
					Server_new->log_file(journal);
					cout << journal << endl;
				}
				// élément autre que zone

				// population de la liste de processus dans le bon ordre
				Process_list.push_back(Phenomenon_new);
				Process_list.push_back(State_new);
				Process_list.push_back(Control_new);
			}
		}
		Process* Serv = Server_new;
		Process_list.push_back(Serv);
		Simulator* Simulator_new = new Simulator(Process_list, stoi(child1->Attribute("nTicks")));
		//return Simulator_new;
		journal = "Parser complete, now running simulator...";
		Server_new->log_file(journal);
		cout << journal << endl;
		Simulator_new->run();

		/*
		vector<Process*> Process_list1;
		Process_list1.push_back(Server_new);
		int i = 12;
		Simulator* Simulator_new1 = new Simulator(Process_list1, i);
		return Simulator_new1;
		*/
}


