/*
 * sharedParam_test.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: yitinglei
 */

#include "sharedParam.hpp"
#include <gtest/gtest.h>




TEST(testGet,should_pass) {
	sharedParam *d = new sharedParam();

	EXPECT_EQ(d->sys->getA(),0.1);
	EXPECT_EQ(d->sys->getB(),2.0);
	EXPECT_EQ(d->sys->getC(),3.0);
}
