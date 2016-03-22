#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include "DataManager.h"

using namespace System;
class VectorOperate{
public:
	VectorOperate() {
	};
	Vector Ope1(String^ a, std::vector<Vector> vectors);
	double Ope5(String^ a, std::vector<Vector> vectors);
	Vector  Ope6(String^ a, std::vector<Vector> vectors);
	Vector  Ope7(String^ a, std::vector<Vector> vectors);
	Vector  Ope8(String^ a, std::vector<Vector> vectors);
	Vector  Ope9(String^ a, std::vector<Vector> vectors);
	bool  Ope11(String^ a, std::vector<Vector> vectors);
	bool  Ope12(String^ a, std::vector<Vector> vectors);
	double  Ope13(String^ a, std::vector<Vector> vectors);
	double  Ope10(String^ a, std::vector<Vector> vectors);
	bool  Ope15(String^ a, std::vector<Vector> vectors);
	Vector Ope16(String^ a, std::vector<Vector> vectors);
	int test(String^ a, std::vector<Vector> vectors);
};