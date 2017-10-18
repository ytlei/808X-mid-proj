/*
 * ssSystem.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: yitinglei
 */

#include "ssSystem.hpp"

ssSystem::ssSystem(double a, double b, double c) {
  // TODO Auto-generated constructor stub
  A=a;
  B=b;
  C=c;
}

ssSystem::~ssSystem() {
  // TODO Auto-generated destructor stub
}



double ssSystem:: getA() {
  return A;
}

double ssSystem:: getB() {
  return B;
}


double ssSystem:: getC() {
  return C;
}
