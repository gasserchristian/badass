/*
 * xml_extract.h
 *
 *  Created on: 13 Nov 2017
 *      Author: maxch
 */

#ifndef SOURCE_PARSER_H_
#define SOURCE_PARSER_H_

#include "../Simulator.h"
#include "../processus/Phenomenon.h"
#include "../processus/State.h"
#include "../processus/Control.h"
#include "../processus/Server.h"
#include "../processus/Process.h"
#include "../processus/controller/TOR.h"
#include "../processus/controller/P.h"
#include "../processus/phenomenes/PUL.h"
#include "../processus/phenomenes/SIN.h"
#include <vector>
#include <string>
#include "../../TinyXML/tinyxml.h"

void parse(Simulator* Sim);

#endif /* SOURCE_PARSER_H_ */


