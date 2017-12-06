/*
 * PUL.h
 *
 *  Created on: 6 déc. 2017
 *      Author: Christian
 */

#ifndef SOURCE_PROCESSUS_PHENOMENES_PUL_H_
#define SOURCE_PROCESSUS_PHENOMENES_PUL_H_

#include "../Phenomenon.h"

class PUL : public Phenomenon {
public:
	PUL(unsigned pul_ID, string pul_name, Process* State_new, double pul_std_dev,
			double pul_v_low, double pul_v_high, long int pul_t_del,
			long int pul_t_rise, long int pul_pwidth, long int pul_t_fall,
			long int pul_period) :  sigma_(pul_std_dev), v_low_(pul_v_low),
			v_high_(pul_v_high), t_del_(pul_t_del),
			pwidth_(pul_pwidth), t_fall_(pul_t_fall), period_(pul_period) {}
	virtual ~PUL() {}
	void update(int tic);
private:
	double sigma_;
	double v_low_;
	double v_high_;
	long int t_del_;
	long int pwidth_;
	long int t_fall_;
	long int period_;
};

#endif /* SOURCE_PROCESSUS_PHENOMENES_PUL_H_ */
