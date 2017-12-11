/*
 * PUL.h
 *
 *  Created on: 6 déc. 2017
 *      Author: Christian
 */

#ifndef SOURCE_PROCESSUS_PHENOMENES_PUL_H_
#define SOURCE_PROCESSUS_PHENOMENES_PUL_H_

#include "../Phenomenon.h"
#include <cassert>
#include <iostream> //DELETE AFTER

class PUL : public Phenomenon {
public:
	PUL(unsigned pul_ID, string pul_name, State* State_new, double pul_std_dev,
			double pul_v_low, double pul_v_high, long int pul_t_del,
			long int pul_t_rise, long int pul_pwidth, long int pul_t_fall,
			long int pul_period) :  Phenomenon(pul_ID, pul_name, State_new), sigma_(pul_std_dev), v_low_(pul_v_low),
			v_high_(pul_v_high), t_del_(pul_t_del), t_rise_(pul_t_rise),
			pwidth_(pul_pwidth), t_fall_(pul_t_fall), period_(pul_period) {
		assert(t_del_>=0);
		assert(t_rise_>=0);
		assert(pwidth_>=0);
		assert(t_fall_>=0);
		assert(period_>=0);
	}
	virtual ~PUL() {}
	void update(int tic);
private:
	double sigma_;
	double v_low_;
	double v_high_;
	long int t_del_;
	long int t_rise_;
	long int pwidth_;
	long int t_fall_;
	long int period_;
};

#endif /* SOURCE_PROCESSUS_PHENOMENES_PUL_H_ */
