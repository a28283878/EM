#include "MatrixOperate.h"
#include "stack"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
using namespace std;
vector<Vector> count(String^ input, std::vector<std::vector<Vector>> matrixs);//�|�h�B��

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
			/*else if (sorted[i] == "*") {
				//�V�q*�¶q
				if (temps[temps.size() - 1].Data.size() == 1 || temps[temps.size() - 2].Data.size() == 1) {
					//�᭱���¶q
					if (temps[temps.size() - 1].Data.size() == 1) {
						Vector multi;
						multi.Name = "$multivector";
						double num = temps[temps.size() - 1].Data[0];//�¶q����
						vector<double> v;
						for (int i = 0; i < temps[temps.size() - 2].Data.size(); i++) {
							v.push_back(temps[temps.size() - 2].Data[i] * num);
						}
						multi.Data = v;
						//�N�����B�⪺���vector����
						temps.resize(temps.size() - 2);
						//���W�w�⧹��
						temps.push_back(multi);
					}
					else {
						Vector multi;
						multi.Name = "$multivector";
						double num = temps[temps.size() - 2].Data[0];//�¶q����
						vector<double> v;
						for (int i = 0; i < temps[temps.size() - 1].Data.size(); i++) {
							v.push_back(temps[temps.size() - 1].Data[i] * num);
						}
						multi.Data = v;
						//�N�����B�⪺���vector����
						temps.resize(temps.size() - 2);
						//���W�w�⧹��
						temps.push_back(multi);
					}
				}
				else {
					Vector multi;
					multi.Name = "int";
					double sum;
					//��̦V�q�U�ۭ�
					if (temps[temps.size() - 1].Data.size() != temps[temps.size() - 2].Data.size()) {
						throw "Can't Compute : size of vectors aren't the same";
					}//�B�z�ҥ~
					for (int i = 0; i < temps[temps.size() - 1].Data.size(); i++) {
						sum += (temps[temps.size() - 1].Data[i] * temps[temps.size() - 2].Data[i]);
					}
					vector<double> v(temps[temps.size() - 1].Data.size(), sum);
					multi.Data = v;
					//�N�����B�⪺���vector����
					temps.resize(temps.size() - 2);
					//���W�w�⧹��
					temps.push_back(multi);
				}
			}*/
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