#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
//定義向量資料結構
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
//定義控管資料class
class DataManager
{
private:
	//儲存向量資料
	std::vector<Vector> Vectors;
	std::vector<std::vector<Vector>> Matrixs;
	//紀錄檔案路徑名稱
	std::string FileName;
public:
	//紀錄向量ID，用於控管
	int  VectorVariableIndex;
	int MatrixVariableIndex;
	DataManager();
	//讀取向量資料
	bool LoadVectorData();
	bool LoadMatrixData();
	//取得向量資料
	std::vector<Vector> GetVectors();
	std::vector<std::vector<Vector>> GetMatrixs();
	//設置檔案路徑名稱
	void SetFileName(std::string fileName);
	void ResetVectors();
	void ResetMatrixs();
};
