# LQR controller for adaptive cruise control
[![Build Status](https://travis-ci.org/ytlei/808X-mid-proj.svg?branch=master)](https://travis-ci.org/ytlei/808X-mid-proj)
[![Coverage Status](https://coveralls.io/repos/github/ytlei/808X-mid-proj/badge.svg?branch=master)](https://coveralls.io/github/ytlei/808X-mid-proj?branch=master)
---

## Overview

The program is a implementation of LQR controller for cruise control. It will be developed in C++ under Linux Ubuntu system and run on Ubuntu. We will be using LQR control algorithms to implement the cruise control system.
Based on the state-space model the discrete-time LQR controller will can be designed.
There will be three major steps to implement the controller:
	•	Implement a discrete-time plant TF 
	•	Design a negative feedback LQR controller with trajectory tracking and implement the closed-loop system
	•	Implement the controller and plant computations in their own respective threads and write output to file or screen
The interface will be:
	Inputs: Read data from randomly generated speed to simulate car speed.
	Outputs: Generate corresponding speed according to the input.


## Current status

Under early stage development. Planned to be finished by 10/17/2017

## Standard install via command-line
```
git clone --recursive https://github.com/ytlei/808X-mid-proj.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```



