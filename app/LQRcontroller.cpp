/** @file LQRcontroller.cpp
 *  @brief cpp file for LQRcontroller
 *
 *  This file contains implementation for methods for LQR calculation
 *
 *  @Created on: Oct 1, 2017
 *  @Author: yitinglei
 */
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include "LQRcontroller.hpp"
#include "sharedParam.hpp"
#include "ssSystem.hpp"

LQRcontroller::LQRcontroller() {
}

LQRcontroller::~LQRcontroller() {
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
	double A = d->sys->getA();
	double B = d->sys->getB();
	double C = d->sys->getC();

	//LQR tuning parameters
	double R = 1.0;
	double Q = C * C * 3.0;

	//control policy
	double p = ((R - A * R * A - B * Q * B) / B * B);
	double q = -(R * Q) / (B * B);
	double P = -(p) / 2 - sqrt((p / 2) * (p / 2) - q); //important to choose the second solution here

	//gains
	*K = (B * P * A) / (R + B * P * B);
	*F = 1 / (C * B / (1 - (A + B * *K)));
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
	double u = K * d->dx + F * r;

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
	double A = d->sys->getA();
	double B = d->sys->getB();
	double C = d->sys->getC();

	d->x = A * d->dx + B * d->u;
	double y = C * d->dx;

	return y;
}

void LQRcontroller::controllerThread() {
	sharedParam *param = new sharedParam();

	struct timespec sleepValue;
	sleepValue.tv_sec = 1;  // 1s
	sleepValue.tv_nsec = 0;

	int BUF = 128;        //line buffer
	//char line[BUF];
	int n = 0;

	//compute the control gains
	double K = 0;
	double F = 0;
	lqrGains(param, &K, &F);

	string line;
	ifstream speedFile("speed1.txt");
	//open the setpointvalues.txt file

	if (!speedFile) {
		printf("unable to read setpointvalues.txt\n");
		return;
	}

	int i = 0;

	//read setpoints line by line

	if (speedFile.is_open()) {
		while (getline(speedFile, line)) {
			double r;
			r = std::stod(line);
			cout << line << '\n';
			param->u = lqr(param, r, K, F);  //calculate the current control output
		}
		speedFile.close();
	}
}
void LQRcontroller::plantThread() {
	struct timespec sleepValue;
	sleepValue.tv_sec = 0;
	sleepValue.tv_nsec = 100000000;  // 0.1s

	sharedParam *d = new sharedParam();

	//open the setpointvalues.txt file
	string line;
	ofstream speedOutFile("speedOut.txt");

	if (!speedOutFile.is_open()) {
		cout << "unable to open out.txt" << endl;
		return;
	}

	int i = 0;

	while (1) {

		//stop when there are no more setpoints to read
		if (d->eof) {
			break;
		}

		d->dx = d->x;        //next cycle
		double y = plant(d);    //compute current plant output
		speedOutFile << y << endl;
		cout << "u:" << d->u << " y:" << y;

		nanosleep(&sleepValue, NULL);
		i++;
	}
	speedOutFile.close();
	cout << i << " output values written to out.txt" << endl;
}
