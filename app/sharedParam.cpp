/** @file sharedParam.cpp
 *  @brief
 *
 *  @Created on: Oct 1, 2017
 *  @Author: yitinglei
 */

#include "sharedParam.hpp"

sharedParam::sharedParam() {
	x = 0;
	u = 0;
	dx = 0;
	eof = false;
	*sys = new ssSystem(0.1, 2.0, 3.0);
}

sharedParam::~sharedParam() {
	// TODO Auto-generated destructor stub
}

