/** @file sharedParam.hpp
 *  @brief interface for the shared parameters for calculation
 *
 *  @Created on: Oct 1, 2017
 *  @Author: yitinglei
 */
#include "ssSystem.hpp"


#ifndef CPP_BOILERPLATE_INCLUDE_SHAREDPARAM_HPP_
#define CPP_BOILERPLATE_INCLUDE_SHAREDPARAM_HPP_

class sharedParam {
 private:
  double x, u, dx;
  ssSystem *sys;
 public:
  sharedParam();
  virtual ~sharedParam();
};
#endif /* CPP_BOILERPLATE_INCLUDE_SHAREDPARAM_HPP_ */

