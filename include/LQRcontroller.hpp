/** @file LQRcontroller.hpp
 *  @brief header file for LQRcontroller
 *
 *  This file contains methods for LQR calculation
 *
 *  @Created on: Oct 1, 2017
 *  @Author: yitinglei
 */
#ifndef CPP_BOILERPLATE_INCLUDE_LQRCONTROLLER_HPP_
#define CPP_BOILERPLATE_INCLUDE_LQRCONTROLLER_HPP_
#include "sharedParam.hpp"

class LQRcontroller {
 public:
  LQRcontroller();
  virtual ~LQRcontroller();
  void lqrGains(sharedParam *d, double *K, double *F);
  double lqr(sharedParam *d, double r, double K, double F);
  double plant(sharedParam *d);
  void controllerThread();
  void plantThread();
};

#endif /* CPP_BOILERPLATE_INCLUDE_LQRCONTROLLER_HPP_ */
