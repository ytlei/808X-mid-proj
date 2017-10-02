/** @file LQRcontroller.hpp
 *  @brief header file for LQRcontroller contains methods for calculation
 *
 *  @Created on: Oct 1, 2017
 *  @Author: yitinglei
 */
#ifndef CPP_BOILERPLATE_INCLUDE_LQRCONTROLLER_HPP_
#define CPP_BOILERPLATE_INCLUDE_LQRCONTROLLER_HPP_

class LQRcontroller {
public:
	LQRcontroller();
	virtual ~LQRcontroller();
	void lqrGains(struct shared *d, double *K, double *F);
	double lqr(struct shared *d, double r, double K, double F);
	double plant(struct shared *d);
};

#endif /* CPP_BOILERPLATE_INCLUDE_LQRCONTROLLER_HPP_ */
