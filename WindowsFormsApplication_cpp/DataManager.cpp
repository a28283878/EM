#include"DataManager.h"

DataManager::DataManager()
{
	VectorVariableIndex = 0;
	MatrixVariableIndex = 0;
}

bool DataManager::LoadVectorData()
{
	int vectornum;//�U�Ъ��d�Ҧb�B�z�̫�@��vector�|�h�X�@�ӼƦr
	int tempnum;//�ثeŪ�J�V�q�������@�Ӽ�
	std::fstream fin;
	//�}���ɮסA�ǤJopen��ƪ��ѼƦ���ӡA���}�_���ɮצW�١A�}���ɮת��Ҧ��Ѽ�(�o��std::ios::in��Ū��(��J)���A)
	fin.open(FileName, std::ios::in);
	//Ū�����Ѧ^��false
	if (!fin)
	{
		return false;
	}
	else
	{
		//�аO��eŪ���V�qID
		int currentLoadVectorID = 0;
		//�w�q�V�q��ƼȦs�ܼ�
		std::vector<double> tempVectorData;
		//�w�qŪ���ɮצr��Ȧs�ܼ�
		std::string tempSring;
		//�q�ɮ�Ū���r��A�ѪR���V�q�`��
		fin >> tempSring;
		
		//����Ū�ɰj��A�æbŪ���ɮ׵����ɵ���
		while (!fin.eof())
		{
			//�q�ɮ�Ū���r��
			fin >> tempSring;
			//�ѪR��V�q�аO"V"
			if (tempSring == "V")
			{
				if (currentLoadVectorID != 0)
				{
					//�w�q�Ȧs�V�q��Ƶ��c
					Vector tempVector;
					//�s�J�V�q���
					tempVector.Data = tempVectorData;
					//�w�q�V�q�ܼƦW�١A��VectorVariableIndex�ܼƧ@�W�٪�����
					std::string vectorVariableTemp = "$v" + std::to_string(VectorVariableIndex);
					//�s�J�V�q�ܼƦW��
					tempVector.Name = vectorVariableTemp;
					//�s�J�V�q
					Vectors.push_back(tempVector);
					//���WVectorVariableIndex�A�H�T�O�ܼƦW�٤�����
					VectorVariableIndex++;
					//�M���V�q��ƼȦs
					tempVectorData.clear();
				}
				//���WcurrentLoadVectorID�A�аO���eŪ���V�qID
				currentLoadVectorID++;
				//�q�ɮ�Ū���r��A�ѪR���V�q����
				fin >> tempSring;
				vectornum = (double)strtod(tempSring.c_str(), NULL);
				tempnum = 0;
			}
			else if(tempnum < vectornum)
			{
				//Ū���V�q��ơA�ñNstring�ରdouble
				double value;
				value = (double)strtod(tempSring.c_str(), NULL);
				//�N�V�q��Ʀs�J�Ȧs
				tempVectorData.push_back(value);
				tempnum++;
			}
			
		}
		//Ū�J��J�ɮפ��̫�@�ӦV�q��T
		Vector tempVector;
		tempVector.Data = tempVectorData;
		std::string vectorVariableTemp = "$v" + std::to_string(VectorVariableIndex);
		tempVector.Name = vectorVariableTemp;
		Vectors.push_back(tempVector);
		VectorVariableIndex++;
		//Ū�����\�^��false
		return true;
	}
}

bool DataManager::LoadMatrixData() {
	int row, column;
	int matrixnum;//�U�Ъ��d�Ҧb�B�z�̫�@��vector�|�h�X�@�ӼƦr
	int tempnum;//�ثeŪ�J�V�q�������@�Ӽ�
	std::fstream fin;
	//�}���ɮסA�ǤJopen��ƪ��ѼƦ���ӡA���}�_���ɮצW�١A�}���ɮת��Ҧ��Ѽ�(�o��std::ios::in��Ū��(��J)���A)
	fin.open(FileName, std::ios::in);
	//Ū�����Ѧ^��false
	if (!fin)
	{
		return false;
	}
	else
	{
		//�аO��eŪ���V�qID
		int currentLoadVectorID = 0;
		//�w�q�V�q��ƼȦs�ܼ�
		std::vector<double> tempMatrixData;
		//�w�qŪ���ɮצr��Ȧs�ܼ�
		std::string tempSring;
		//�q�ɮ�Ū���r��A�ѪR���V�q�`��
		fin >> tempSring;

		//����Ū�ɰj��A�æbŪ���ɮ׵����ɵ���
		while (!fin.eof())
		{
			//�q�ɮ�Ū���r��
			fin >> tempSring;
			//�ѪR��V�q�аO"M"
			if (tempSring == "M")
			{
				if (currentLoadVectorID != 0)
				{
					std::vector<Vector> tempMatrix;
					std::string matrixVariableTemp = "$m" + std::to_string(MatrixVariableIndex);
					for (int i = 0; i < row; i++) {
						Vector vector;//matrix�̭���vector
						for (int j = 0; j < column; j++) {
							vector.Data.push_back(tempMatrixData[i*column + j]);
							vector.Name = matrixVariableTemp;
						}
						tempMatrix.push_back(vector);
					}
					Matrixs.push_back(tempMatrix);;
					MatrixVariableIndex++;
					tempMatrixData.clear();
					/*//�w�q�Ȧs�V�q��Ƶ��c
					Vector tempVector;
					//�s�J�V�q���
					tempVector.Data = tempMatrixData;
					//�w�q�V�q�ܼƦW�١A��VectorVariableIndex�ܼƧ@�W�٪�����
					std::string vectorVariableTemp = "$v" + std::to_string(VectorVariableIndex);
					//�s�J�V�q�ܼƦW��
					tempVector.Name = vectorVariableTemp;
					//�s�J�V�q
					Vectors.push_back(tempVector);
					//���WVectorVariableIndex�A�H�T�O�ܼƦW�٤�����
					VectorVariableIndex++;
					//�M���V�q��ƼȦs
					tempVectorData.clear();*/
				}
				//���WcurrentLoadVectorID�A�аO���eŪ���V�qID
				currentLoadVectorID++;
				//�q�ɮ�Ū���r��A�ѪR���V�q����
				fin >> tempSring;
				row = (double)strtod(tempSring.c_str(), NULL);
				fin >> tempSring;
				column = (double)strtod(tempSring.c_str(), NULL);
				matrixnum = row*column;
				tempnum = 0;
			}
			else if (tempnum < matrixnum)
			{
				//Ū���V�q��ơA�ñNstring�ରdouble
				double value;
				value = (double)strtod(tempSring.c_str(), NULL);
				//�N�V�q��Ʀs�J�Ȧs
				tempMatrixData.push_back(value);
				tempnum++;
			}

		}
		//Ū�J��J�ɮפ��̫�@�ӦV�q��T
		std::vector<Vector> tempMatrix;
		std::string matrixVariableTemp = "$m" + std::to_string(MatrixVariableIndex);
		for (int i = 0; i < row; i++) {
			Vector vector;//matrix�̭���vector
			for (int j = 0; j < column; j++) {
				vector.Data.push_back(tempMatrixData[i*column + j]);
				vector.Name = matrixVariableTemp;
			}
			tempMatrix.push_back(vector);
		}
		Matrixs.push_back(tempMatrix);;
		MatrixVariableIndex++;
		tempMatrixData.clear();
		//Ū�����\�^��true
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