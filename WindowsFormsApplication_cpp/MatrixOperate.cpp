#include "MatrixOperate.h"
#include "stack"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
using namespace std;
vector<Vector> gauss(vector<Vector> input);
vector<Vector> count(String^ input, std::vector<std::vector<Vector>> matrixs);//�|�h�B��

vector<double> MatrixOperate::Ope5(String^ input, std::vector<std::vector<Vector>> matrixs) {
	vector<Vector> origin = count(input, matrixs);
}

vector<Vector> MatrixOperate::Ope4(String^ input, std::vector<std::vector<Vector>> matrixs) {
	vector<Vector> origin = count(input, matrixs);
	vector<Vector> tran;
	for (int i = 0; i < origin[0].Data.size(); i++) {
		Vector tranin;
		tranin.Name = "$Trans";
		for (int k = 0; k < origin.size(); k++) {
			tranin.Data.push_back(origin[k].Data[i]);
		}
		tran.push_back(tranin);
	}

	return tran;
}

int MatrixOperate::Ope3(String^ input, std::vector<std::vector<Vector>> matrixs) {
	ofstream outfile("output.txt");
	vector<Vector> rank = count(input, matrixs);
	rank = gauss(rank);
	int ranknum = 0;
	for (int i = 0; i < rank.size(); i++) {
		for (int k = 0; k < rank[i].Data.size(); k++) {
			if (abs(rank[i].Data[k]) > 0.0000001) {
				cout << i << endl;
				ranknum++;
				break;
			}
		}
	}
	for (int i = 0; i < rank.size(); i++) {
		for (int k = 0; k < rank[i].Data.size(); k++) {
			outfile << rank[i].Data[k] << "  ";
		}
		outfile << endl;
	}
	return ranknum;
}

vector<Vector> MatrixOperate::Ope1(String^ input, std::vector<std::vector<Vector>> matrixs) {
	vector<Vector> add = count(input, matrixs);
	return add;
}

vector<Vector> count(String^ input, std::vector<std::vector<Vector>> matrixs) {
	vector<string> list;
	for (int i = 0; i < input->Length; i++) {
		if ((input[i]) == '$') {
			std::string temps = "";
			int num = i;
			while (input[num] != ')' && input[num] != '(' && input[num] != '+' && input[num] != '-' && input[num] != '*' && input[num] != '/'&& num < input->Length) {
				if (num<input->Length)temps += input[num];
				num++;
				if (num == input->Length) break;
			}
			i = num - 1;
			list.push_back(temps);
		}
		else {
			string temp = "";
			temp += input[i];
			list.push_back(temp);
		}
	}
	//for (int i = 0; i < list.size(); i++) cout << list[i] << "  ";
	//----------------------------------------------����------------------------------------------------------//
	vector<string> sorted;//���
	stack<string> stack;
	for (int i = 0; i < list.size(); i++) {
		if (list[i] == "+" || list[i] == "-" || list[i] == "*" || list[i] == "/" || list[i] == "(") {
			stack.push(list[i]);
		}
		else if (list[i] == ")") {
			while (stack.top() != "(") {
				sorted.push_back(stack.top());
				stack.pop();
			}
			stack.pop();
		}
		else {
			sorted.push_back(list[i]);
		}
	}
	while (!stack.empty()) {
		sorted.push_back(stack.top());
		stack.pop();
	}
	//cout << "\n";
	//for (int i = 0; i<sorted.size(); i++) std::cout << sorted[i] << "  ";
	//---------------------------------------�}�l��-----------------------------------//
	vector<vector<Vector>> temps;
	for (int i = 0; i < sorted.size(); i++) {
		if (sorted[i] == "+" || sorted[i] == "-" || sorted[i] == "*" || sorted[i] == "/") {
			//�J��[��
			if (sorted[i] == "+") {
				//cout << temps[temps.size() - 1].Name[0];
				//�Y��ӬҬ�int �Dvector
				if (temps[temps.size() - 1][0].Name == temps[temps.size() - 2][0].Name&& temps[temps.size() - 2][0].Name == "int") {
					//�W�[�o�Ӷi�h
					vector<Vector> add;
					//�w�q�X�@��vector �W�r�sint �åB���L��vector���@�˪�����
					for (int i = 0; i < temps[temps.size() - 1].size(); i++) {
						vector<double> v(temps[temps.size() - 1][i].Data.size(), temps[temps.size() - 1][i].Data[0] + temps[temps.size() - 2][i].Data[0]);
						add[i].Data = v;
						add[i].Name = "int";
					}
					temps.resize(temps.size() - 2);
					temps.push_back(add);
				}
				//���ӳ��Ovector��
				else if (temps[temps.size() - 1][0].Name[0] == temps[temps.size() - 2][0].Name[0] && temps[temps.size() - 2][0].Name[0] == '$') {
					if (temps[temps.size() - 1][0].Data.size() != temps[temps.size() - 2][0].Data.size() || temps[temps.size() - 1].size() != temps[temps.size() - 2].size()) {
						throw "Can't Compute : size of vectors aren't the same";
					}
					vector<Vector> add;
					//add.Name = "$addvector";
					for (int i = 0; i < temps[temps.size() - 1].size(); i++) {
						Vector v;
						v.Name = "$addmatrix";
						//cout << temps[temps.size() - 1].Data[i] << "  ";
						for (int k = 0; k < temps[temps.size() - 1][i].Data.size(); k++) {
							v.Data.push_back(temps[temps.size() - 1][i].Data[k] + temps[temps.size() - 2][i].Data[k]);
						}
						add.push_back(v);
					}
					temps.resize(temps.size() - 2);
					temps.push_back(add);
				}
				//�@�ӬOvector�@�ӬOint��
				else {
					if (temps[temps.size() - 1][0].Data.size() != temps[temps.size() - 2][0].Data.size()) {
						throw "Can't Compute : int + vector error: �нT��ϥάA��";
					}
				}
			}
			//�J�쭼��
			else if (sorted[i] == "*") {
				if (temps[temps.size() - 2][0].Data.size() != temps[temps.size() - 1].size()) {
					throw "���matrix���L�k����";
				}
				else {
					vector<Vector> output;
					for (int i = 0; i < temps[temps.size() - 2].size(); i++) {
						Vector temp;
						temp.Name = "$multi";
						for (int k = 0; k < temps[temps.size() - 1][0].Data.size(); k++) {
							double num = 0;
							for (int j = 0; j < temps[temps.size() - 2][0].Data.size(); j++) {
								num += temps[temps.size() - 2][i].Data[j] * temps[temps.size() - 1][j].Data[k];
							}
							temp.Data.push_back(num);
						}
						output.push_back(temp);
					}
					temps.resize(temps.size() - 2);
					temps.push_back(output);
				}
			}
			else if (sorted[i] == "/") {

			}
		}
		//�Nsorted��itemps
		else {
			for (unsigned int j = 0; j < matrixs.size(); j++)
			{
				if (sorted[i] == matrixs[j][0].Name.c_str()) {
					temps.push_back(matrixs[j]);
					break;
				}
			}
		}
	}
	return temps[0];
}

vector<Vector> gauss(vector<Vector> input) {
	for (int i = 0; i < input.size(); i++) {
		double maxEl;
		int maxRow;
		maxEl = abs(input[i].Data[i]);
		maxRow = i;
		for (int k = i + 1; k < input.size(); k++) {
			if (abs(input[k].Data[i])>maxEl) {
				maxEl = input[k].Data[i];
				maxRow = k;
			}
		}
		for (int k = i; k < input.size(); k++) {
			double temp = input[maxRow].Data[k];
			input[maxRow].Data[k] = input[i].Data[k];
			input[i].Data[k] = temp;
		}
		for (int k = i + 1; k < input.size(); k++) {
			double c;
			if (input[i].Data[i] == 0) c = 0;
			else c = (input[k].Data[i] / input[i].Data[i])*(-1);
			for (int j = i; j < input.size(); j++) {
				if (i == j)input[k].Data[j] = 0;
				else {
					/*double check = (input[k].Data[j] / input[i].Data[j]) * (-1);
					if(check == c) input[k].Data[j] = 0;
					else
					{
						input[k].Data[j] += c*input[i].Data[j];
					}*/
					input[k].Data[j] += c*input[i].Data[j];
					if (abs(input[k].Data[j]) < 0.000000001) input[k].Data[j] = 0;
				}
			}
		}
	}
	return input;
}