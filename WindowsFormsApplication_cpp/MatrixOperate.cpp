#include "MatrixOperate.h"
#include "stack"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
using namespace std;
vector<Vector> count(String^ input, std::vector<std::vector<Vector>> matrixs);//四則運算

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
	//----------------------------------------------轉後序------------------------------------------------------//
	vector<string> sorted;//後序
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
	//---------------------------------------開始算-----------------------------------//
	vector<vector<Vector>> temps;
	for (int i = 0; i < sorted.size(); i++) {
		if (sorted[i] == "+" || sorted[i] == "-" || sorted[i] == "*" || sorted[i] == "/") {
			//遇到加號
			if (sorted[i] == "+") {
				//cout << temps[temps.size() - 1].Name[0];
				//若兩個皆為int 非vector
				if (temps[temps.size() - 1][0].Name == temps[temps.size() - 2][0].Name&& temps[temps.size() - 2][0].Name == "int") {
					//增加這個進去
					vector<Vector> add;
					//定義出一個vector 名字叫int 並且跟其他的vector有一樣的長度
					for (int i = 0; i < temps[temps.size() - 1].size(); i++) {
						vector<double> v(temps[temps.size() - 1][i].Data.size(), temps[temps.size() - 1][i].Data[0] + temps[temps.size() - 2][i].Data[0]);
						add[i].Data = v;
						add[i].Name = "int";
					}
					temps.resize(temps.size() - 2);
					temps.push_back(add);
				}
				//當兩個都是vector時
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
				//一個是vector一個是int時
				else {
					if (temps[temps.size() - 1][0].Data.size() != temps[temps.size() - 2][0].Data.size()) {
						throw "Can't Compute : int + vector error: 請確實使用括號";
					}
				}
			}
			//遇到乘號
			/*else if (sorted[i] == "*") {
				//向量*純量
				if (temps[temps.size() - 1].Data.size() == 1 || temps[temps.size() - 2].Data.size() == 1) {
					//後面為純量
					if (temps[temps.size() - 1].Data.size() == 1) {
						Vector multi;
						multi.Name = "$multivector";
						double num = temps[temps.size() - 1].Data[0];//純量的值
						vector<double> v;
						for (int i = 0; i < temps[temps.size() - 2].Data.size(); i++) {
							v.push_back(temps[temps.size() - 2].Data[i] * num);
						}
						multi.Data = v;
						//將做完運算的兩個vector移除
						temps.resize(temps.size() - 2);
						//換上已算完的
						temps.push_back(multi);
					}
					else {
						Vector multi;
						multi.Name = "$multivector";
						double num = temps[temps.size() - 2].Data[0];//純量的值
						vector<double> v;
						for (int i = 0; i < temps[temps.size() - 1].Data.size(); i++) {
							v.push_back(temps[temps.size() - 1].Data[i] * num);
						}
						multi.Data = v;
						//將做完運算的兩個vector移除
						temps.resize(temps.size() - 2);
						//換上已算完的
						temps.push_back(multi);
					}
				}
				else {
					Vector multi;
					multi.Name = "int";
					double sum;
					//兩者向量各自乘
					if (temps[temps.size() - 1].Data.size() != temps[temps.size() - 2].Data.size()) {
						throw "Can't Compute : size of vectors aren't the same";
					}//處理例外
					for (int i = 0; i < temps[temps.size() - 1].Data.size(); i++) {
						sum += (temps[temps.size() - 1].Data[i] * temps[temps.size() - 2].Data[i]);
					}
					vector<double> v(temps[temps.size() - 1].Data.size(), sum);
					multi.Data = v;
					//將做完運算的兩個vector移除
					temps.resize(temps.size() - 2);
					//換上已算完的
					temps.push_back(multi);
				}
			}*/
		}
		//將sorted塞進temps
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