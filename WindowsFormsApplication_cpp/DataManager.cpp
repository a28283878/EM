#include"DataManager.h"

DataManager::DataManager()
{
	VectorVariableIndex = 0;
	MatrixVariableIndex = 0;
}

bool DataManager::LoadVectorData()
{
	int vectornum;//助教的範例在處理最後一個vector會多出一個數字
	int tempnum;//目前讀入向量中的哪一個數
	std::fstream fin;
	//開啟檔案，傳入open函數的參數有兩個，欲開起的檔案名稱，開啟檔案的模式參數(這邊std::ios::in為讀取(輸入)狀態)
	fin.open(FileName, std::ios::in);
	//讀取失敗回傳false
	if (!fin)
	{
		return false;
	}
	else
	{
		//標記當前讀取向量ID
		int currentLoadVectorID = 0;
		//定義向量資料暫存變數
		std::vector<double> tempVectorData;
		//定義讀取檔案字串暫存變數
		std::string tempSring;
		//從檔案讀取字串，解析掉向量總數
		fin >> tempSring;
		
		//執行讀檔迴圈，並在讀到檔案結尾時結束
		while (!fin.eof())
		{
			//從檔案讀取字串
			fin >> tempSring;
			//解析到向量標記"V"
			if (tempSring == "V")
			{
				if (currentLoadVectorID != 0)
				{
					//定義暫存向量資料結構
					Vector tempVector;
					//存入向量資料
					tempVector.Data = tempVectorData;
					//定義向量變數名稱，依VectorVariableIndex變數作名稱的控管
					std::string vectorVariableTemp = "$v" + std::to_string(VectorVariableIndex);
					//存入向量變數名稱
					tempVector.Name = vectorVariableTemp;
					//存入向量
					Vectors.push_back(tempVector);
					//遞增VectorVariableIndex，以確保變數名稱不重複
					VectorVariableIndex++;
					//清除向量資料暫存
					tempVectorData.clear();
				}
				//遞增currentLoadVectorID，標記到當前讀取向量ID
				currentLoadVectorID++;
				//從檔案讀取字串，解析掉向量維度
				fin >> tempSring;
				vectornum = (double)strtod(tempSring.c_str(), NULL);
				tempnum = 0;
			}
			else if(tempnum < vectornum)
			{
				//讀取向量資料，並將string轉為double
				double value;
				value = (double)strtod(tempSring.c_str(), NULL);
				//將向量資料存入暫存
				tempVectorData.push_back(value);
				tempnum++;
			}
			
		}
		//讀入輸入檔案中最後一個向量資訊
		Vector tempVector;
		tempVector.Data = tempVectorData;
		std::string vectorVariableTemp = "$v" + std::to_string(VectorVariableIndex);
		tempVector.Name = vectorVariableTemp;
		Vectors.push_back(tempVector);
		VectorVariableIndex++;
		//讀取成功回傳false
		return true;
	}
}

bool DataManager::LoadMatrixData() {
	int row, column;
	int matrixnum;//助教的範例在處理最後一個vector會多出一個數字
	int tempnum;//目前讀入向量中的哪一個數
	std::fstream fin;
	//開啟檔案，傳入open函數的參數有兩個，欲開起的檔案名稱，開啟檔案的模式參數(這邊std::ios::in為讀取(輸入)狀態)
	fin.open(FileName, std::ios::in);
	//讀取失敗回傳false
	if (!fin)
	{
		return false;
	}
	else
	{
		//標記當前讀取向量ID
		int currentLoadVectorID = 0;
		//定義向量資料暫存變數
		std::vector<double> tempMatrixData;
		//定義讀取檔案字串暫存變數
		std::string tempSring;
		//從檔案讀取字串，解析掉向量總數
		fin >> tempSring;

		//執行讀檔迴圈，並在讀到檔案結尾時結束
		while (!fin.eof())
		{
			//從檔案讀取字串
			fin >> tempSring;
			//解析到向量標記"M"
			if (tempSring == "M")
			{
				if (currentLoadVectorID != 0)
				{
					std::vector<Vector> tempMatrix;
					std::string matrixVariableTemp = "$m" + std::to_string(MatrixVariableIndex);
					for (int i = 0; i < row; i++) {
						Vector vector;//matrix裡面的vector
						for (int j = 0; j < column; j++) {
							vector.Data.push_back(tempMatrixData[i*column + j]);
							vector.Name = matrixVariableTemp;
						}
						tempMatrix.push_back(vector);
					}
					Matrixs.push_back(tempMatrix);;
					MatrixVariableIndex++;
					tempMatrixData.clear();
					/*//定義暫存向量資料結構
					Vector tempVector;
					//存入向量資料
					tempVector.Data = tempMatrixData;
					//定義向量變數名稱，依VectorVariableIndex變數作名稱的控管
					std::string vectorVariableTemp = "$v" + std::to_string(VectorVariableIndex);
					//存入向量變數名稱
					tempVector.Name = vectorVariableTemp;
					//存入向量
					Vectors.push_back(tempVector);
					//遞增VectorVariableIndex，以確保變數名稱不重複
					VectorVariableIndex++;
					//清除向量資料暫存
					tempVectorData.clear();*/
				}
				//遞增currentLoadVectorID，標記到當前讀取向量ID
				currentLoadVectorID++;
				//從檔案讀取字串，解析掉向量維度
				fin >> tempSring;
				row = (double)strtod(tempSring.c_str(), NULL);
				fin >> tempSring;
				column = (double)strtod(tempSring.c_str(), NULL);
				matrixnum = row*column;
				tempnum = 0;
			}
			else if (tempnum < matrixnum)
			{
				//讀取向量資料，並將string轉為double
				double value;
				value = (double)strtod(tempSring.c_str(), NULL);
				//將向量資料存入暫存
				tempMatrixData.push_back(value);
				tempnum++;
			}

		}
		//讀入輸入檔案中最後一個向量資訊
		std::vector<Vector> tempMatrix;
		std::string matrixVariableTemp = "$m" + std::to_string(MatrixVariableIndex);
		for (int i = 0; i < row; i++) {
			Vector vector;//matrix裡面的vector
			for (int j = 0; j < column; j++) {
				vector.Data.push_back(tempMatrixData[i*column + j]);
				vector.Name = matrixVariableTemp;
			}
			tempMatrix.push_back(vector);
		}
		Matrixs.push_back(tempMatrix);;
		MatrixVariableIndex++;
		tempMatrixData.clear();
		//讀取成功回傳true
		return true;
	}
}
std::vector<Vector> DataManager::GetVectors()
{
	return Vectors;
}
std::vector<std::vector<Vector>> DataManager::GetMatrixs() {
	return Matrixs;
}
void DataManager::SetFileName(std::string fileName)
{
	FileName = fileName;
}
void DataManager::ResetVectors() {
	Vectors.clear();
}

void DataManager::ResetMatrixs() {
	Matrixs.clear();
}