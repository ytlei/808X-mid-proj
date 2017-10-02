# C++ Boilerplate
[![Build Status](https://travis-ci.org/ytlei/808X-mid-proj.svg?branch=master)](https://travis-ci.org/ytlei/808X-mid-proj)
[![Coverage Status](https://coveralls.io/repos/github/ytlei/808X-mid-proj/badge.svg?branch=master)](https://coveralls.io/github/ytlei/808X-mid-proj?branch=master)
---

## Overview

The program is a implementation for LQR controller for cruise control. It will be developed in C++ under Linux Ubuntu system and run on Ubuntu. We will be using LQR control algorithms to implement the cruise control system.
Based on the state-space model the discrete-time LQR controller will can be designed.

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



