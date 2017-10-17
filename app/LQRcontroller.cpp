/** @file LQRcontroller.cpp
 *  @brief cpp file for LQRcontroller
 *
 *  This file contains implementation for methods for LQR calculation
 *
 *  @Created on: Oct 1, 2017
 *  @Author: yitinglei
 */

#include "LQRcontroller.hpp"
#include "sharedParam.hpp"
#include <cmath>

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

void LQRcontroller::lqrGains(sharedParam *d, double *K, double *F) {
  //state-space model
  double A = d->sys.A;
  double B = d->sys.B;
  double C = d->sys.C;

  //LQR tuning parameters
  double R = 1.0;
  double Q = C*C*3.0;

  //control policy
  double p = ((R-A*R*A-B*Q*B)/B*B);
  double q = -(R*Q)/(B*B);
  double P = -(p)/2 - sqrt((p/2)*(p/2) - q); //important to choose the second solution here

  //gains
  *K = (B*P*A)/(R+B*P*B);
  *F = 1/(C*B/(1-(A+B**K)));
}

/**
 *
 *   @brief  compute the controller output
 *
 *   @param  shared d pointer, current setpoint r, control gain K, setpoint gain F
 *   @return control output
 */

double LQRcontroller::lqr(sharedParam *d, double r, double K, double F) {
  //LQR with setpoint tracking
  double u = K*d->dx + F*r;

  return u;
}

/**
 *
 *   @brief  compute the plant output
 *
 *   @param  shared d pointer
 *   @return plant output
 */

double LQRcontroller::plant(sharedParam *d) {
  //state space model derived from the given TF
  double A = d->sys.A;
  double B = d->sys.B;
  double C = d->sys.C;

  d->x = A*d-> dx + B*d->u;
  double y = C*d-> dx;

  return y;
}
