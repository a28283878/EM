#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
//�w�q�V�q��Ƶ��c
struct Vector
{
	std::string Name;
	std::vector<double> Data;
};
struct Matrix
{
	std::string Name;
	std::vector<Vector> Data;
};
//�w�q���޸��class
class DataManager
{
private:
	//�x�s�V�q���
	std::vector<Vector> Vectors;
	std::vector<std::vector<Vector>> Matrixs;
	//�����ɮ׸��|�W��
	std::string FileName;
public:
	//�����V�qID�A�Ω󱱺�
	int  VectorVariableIndex;
	int MatrixVariableIndex;
	DataManager();
	//Ū���V�q���
	bool LoadVectorData();
	bool LoadMatrixData();
	//���o�V�q���
	std::vector<Vector> GetVectors();
	std::vector<std::vector<Vector>> GetMatrixs();
	//�]�m�ɮ׸��|�W��
	void SetFileName(std::string fileName);
	void ResetVectors();
	void ResetMatrixs();
};
