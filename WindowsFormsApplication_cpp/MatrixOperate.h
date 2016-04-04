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
	int Ope3(String^ input, std::vector<std::vector<Vector>> matrixs);
	std::vector<Vector> Ope4(String^ input, std::vector<std::vector<Vector>> matrixs);
	std::vector<Vector> Ope5(String^ input, std::vector<std::vector<Vector>> matrixs);
	double Ope6(String^ input, std::vector<std::vector<Vector>> matrixs);
	std::vector<Vector> Ope7(String^ input, std::vector<std::vector<Vector>> matrixs);
	std::vector<Vector> Ope8(String^ input, std::vector<std::vector<Vector>> matrixs);
	std::vector<Vector> Ope9(String^ input, std::vector<std::vector<Vector>> matrixs);
	std::vector<Vector> Ope10(String^ input, std::vector<std::vector<Vector>> matrixs);
	std::vector<Vector> Ope11(String^ input, std::vector<std::vector<Vector>> matrixs);
	std::vector<Vector> Ope12(String^ input, std::vector<std::vector<Vector>> matrixs);
};