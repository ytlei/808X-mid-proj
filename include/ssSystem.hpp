/** @file ssSystem.hpp
 *  @brief state-space system module for the controller
 *
 *  @Created on: Oct 1, 2017
 *  @Author: yitinglei
 */
#ifndef CPP_BOILERPLATE_INCLUDE_SSSYSTEM_HPP_
#define CPP_BOILERPLATE_INCLUDE_SSSYSTEM_HPP_

class ssSystem {
private:
	double A, B, C;
public:
	ssSystem();
	virtual ~ssSystem();
};

#endif /* CPP_BOILERPLATE_INCLUDE_SSSYSTEM_HPP_ */
