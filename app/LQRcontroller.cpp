/*
 * LQRcontroller.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: yitinglei
 */

#include "LQRcontroller.hpp"

LQRcontroller::LQRcontroller() {
	// TODO Auto-generated constructor stub

}

LQRcontroller::~LQRcontroller() {
	// TODO Auto-generated destructor stub
}

/**
 *
 *   @brief  compute the optimal LQR control policy based on the plant model
 *
 *   @param  shared d pointer, double K pointer, double F pointer
 *   @return K and F that are used by reference
 */

void LQRcontroller::lqrGains(struct shared *d, double *K, double *F){

}

/**
 *
 *   @brief  compute the controller output
 *
 *   @param  shared d pointer, current setpoint r, control gain K, setpoint gain F
 *   @return control output
 */

double LQRcontroller::lqr(struct shared *d, double r, double K, double F){
	return 0.0;
}

/**
 *
 *   @brief  compute the plant output
 *
 *   @param  shared d pointer
 *   @return plant output
 */

double LQRcontroller::plant(struct shared *d){
	return 0.0;
}
