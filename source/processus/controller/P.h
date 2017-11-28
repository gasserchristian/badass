/*
 * P.h
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#ifndef SOURCES_PROCESSUS_CONTROLLER_P_H_
#define SOURCES_PROCESSUS_CONTROLLER_P_H_

#include "../Control.h"

class P : public Control {
public:
	P();
	virtual ~P();
	virtual double workValphen(double val = 0, bool set = false) { return NULL; }
	virtual double etatCurr(double val = 0, bool set = false) { return NULL; }
};

#endif /* SOURCES_PROCESSUS_CONTROLLER_P_H_ */
