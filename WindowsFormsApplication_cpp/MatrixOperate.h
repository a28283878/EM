#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include "DataManager.h"

using namespace System;
class MatrixOperate {
public:
	MatrixOperate() {

	};
	std::vector<Vector> Ope1(String^ input, std::vector<std::vector<Vector>> matrixs);


};