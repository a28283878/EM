#include "MatrixOperate.h"
#include "stack"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
using namespace std;
vector<Vector> gauss(vector<Vector> input);//純消去成上三角
vector<Vector> gauss2(vector<Vector> input);//帶值在後面可以求解
vector<Vector> count(String^ input, std::vector<std::vector<Vector>> matrixs);//四則運算

vector<Vector> MatrixOperate::Ope9(String^ input, std::vector<std::vector<Vector>> matrixs) {
	double num = Ope6(input, matrixs);
	int ansnum = 0;//答案要放在矩陣的哪裡
	vector<Vector> original = count(input, matrixs);
	if (original.size() % 2 == 1) {
		num = num*(-1);
	}
	vector<Vector> identity;//eigenvalue答案
	for (int i = 0; i < original.size(); i++) {
		Vector temp;
		for (int k = 0; k < original.size(); k++) {
			temp.Data.push_back(0);
		}
		identity.push_back(temp);
	}//製作單位矩陣
	for (int i = abs(num)*(-1); i <= abs(num); i++) {
		int sample = num/i;
		if (sample == num / (double)i) {
			vector<Vector> temp;
			for (int l = 0; l < original.size(); l++) {
				Vector temps;
				for (int k = 0; k < original.size(); k++) {
					temps.Data.push_back(original[l].Data[k]);
				}
				temp.push_back(temps);
			}
			for (int k = 0; k < temp.size(); k++) {
				temp[k].Data[k] -= sample;
			}
			temp = gauss(temp);
			double detout = 1;
			for (int i = 0; i < temp.size(); i++) {
				detout *= temp[i].Data[i];
			}
			if (detout == 0) {
				identity[ansnum].Data[ansnum] = num/i;
				ansnum += 1;
				//i = abs(num / i)*(-1) - 1;
			}
		}
	}
	for (int i = 0; i < original.size(); i++) {
		for (int k = 0; k < original.size(); k++) {
			cout << identity[i].Data[k] << "  ";
		}
		cout << endl;
	}
	Vector initial;
	vector<Vector> eigenvector;
	vector<Vector> x(identity.size(), initial);
	for (int i = 0; i < identity.size(); i++) {
		vector<Vector> temp;//(A-landa)x = 0;
		for (int l = 0; l < original.size(); l++) {
			Vector temps;
			for (int k = 0; k < original.size(); k++) {
				temps.Data.push_back(original[l].Data[k]);
				if (l == k) {
					temps.Data[k] -= identity[i].Data[i];
				}
			}
			temp.push_back(temps);
		}
		/*for (int i = 0; i < temp.size(); i++) {
			for (int k = 0; k < temp[i].Data.size(); k++) {
				cout << temp[i].Data[k] << "  ";
			}
			cout << endl;
		}*/
		temp = gauss(temp);
		/*for (int i = 0; i < temp.size(); i++) {
			for (int k = 0; k < temp.size(); k++) {
				cout << temp[i].Data[k] << "  ";
			}
			cout << endl;
		}*/
		/*for (int k = temp.size() - 1; k >= 0; k--) {
			x[k].Data.push_back(temp[k].Data[temp.size()] / temp[k].Data[k]);
			for (int j = k - 1; j >= 0; j--) {
				temp[j].Data[temp.size()] -= temp[j].Data[k] * x[k].Data[i];
			}
		}*/
		//-----------------找eigenvector-----------------------
		for (int l = 1; l < temp.size()-1; l++) {
			double c;
			if (temp[l].Data[l] == 0) c = 1;
			else c = (temp[l - 1].Data[l] / temp[l].Data[l])*(-1);
			for (int k = l; k < temp[l].Data.size(); k++) {
				if (k == l) temp[l - 1].Data[k] = 0;
				else {
					temp[l - 1].Data[k] += c*temp[l].Data[k];
					if (fabs(temp[l - 1].Data[k]) < 0.000000001) temp[l - 1].Data[k] = 0;
				}
			}
		}
		int ranknum = 0;
		for (int l = 0; l < temp.size(); l++) {
			for (int k = 0; k < temp[l].Data.size(); k++) {
				if (abs(temp[l].Data[k]) > 0.0000001) {
					ranknum++;
					break;
				}
			}
		}
		//cout << 0;
		Vector eigenV;
		for (int k = 0; k < temp.size(); k++) {
			eigenV.Data.push_back(0);
		}
		//cout << ranknum;
		if (ranknum == temp.size()) {

		}
		else if (ranknum == 1) {
			for (int k = 0; k < temp.size(); k++) {
				if (temp[0].Data[k] == 0) eigenV.Data[k] = 1;				
			}
			if (temp.size() == 2) {
				eigenV.Data[0] = temp[0].Data[1] * (-1);
				eigenV.Data[1] = temp[0].Data[0];
			}
		}
		else {
			if(temp[2].Data[2]!=0){
				for (int k = 0; k < temp.size()-1; k++) {
					if (temp[0].Data[k] == 0) eigenV.Data[k] = 1;
				}
			}
			else {
				for (int k = 0; k < temp.size(); k++) {
					if (k == 0) {
						eigenV.Data[0] = temp[0].Data[temp.size() - 1] * (-1);
					}
					if (k == temp.size() - 1) {
						eigenV.Data[2] = temp[0].Data[0];
						eigenV.Data[1] = (eigenV.Data[2] * temp[1].Data[2])*(-1) / temp[1].Data[1];
					}
				}
			}
		}
		//cout << 1;
		double sum = 0;
		for (int k = 0; k < eigenV.Data.size(); k++) {
			sum += eigenV.Data[k]* eigenV.Data[k];
		}
		sum = pow(sum, 0.5);
		for (int k = 0; k < eigenV.Data.size(); k++) {
			eigenV.Data[k] = eigenV.Data[k] / sum;
		}
		eigenvector.push_back(eigenV);
	}
	for (int i = 0; i < eigenvector.size(); i++) {
		for (int k = 0; k < eigenvector[i].Data.size(); k++) {
			if (eigenvector[k].Data[i] == 0) cout << abs(eigenvector[k].Data[i]) << "  ";
			else cout << eigenvector[k].Data[i] << "  ";
		}
		cout << endl;
	}
	return original;
}

vector<Vector> MatrixOperate::Ope8(String^ input, std::vector<std::vector<Vector>> matrixs) {
	vector<Vector> adjoint;
	adjoint = Ope7(input, matrixs);
	double det = Ope6(input, matrixs);
	for (int i = 0; i < adjoint.size(); i++) {
		for (int k = 0; k < adjoint[i].Data.size(); k++) {
			adjoint[i].Data[k] = adjoint[i].Data[k]* det;
		}
	}

	return adjoint;
}

vector<Vector> MatrixOperate::Ope7(String^ input, std::vector<std::vector<Vector>> matrixs) {
	vector<Vector> inverse = count(input, matrixs);
	if(inverse.size() != inverse[0].Data.size()) throw "行列不同";//行列不同
	double det = Ope6(input, matrixs);
	if (det == 0) throw "無解";
	vector<Vector> identity;
	for (int i = 0; i < inverse.size(); i++) {
		Vector temp;
		for (int k = 0; k < inverse.size(); k++) {		
			if(i == k)temp.Data.push_back(1);
			else temp.Data.push_back(0);
		}
		identity.push_back(temp);
	}//製作單位矩陣
	Vector initial;
	vector<Vector> x(inverse.size(), initial);
	for (int i = 0; i < inverse.size(); i++) {
		vector<Vector> temp = inverse;
		for (int k = 0; k < inverse.size(); k++) {
			temp[k].Data.push_back(identity[i].Data[k]);
		}
		temp = gauss2(temp);
		for (int k = temp.size() - 1; k >= 0; k--) {
			x[k].Data.push_back(temp[k].Data[temp.size()] / temp[k].Data[k]);
			for (int j = k - 1; j >= 0; j--) {
				temp[j].Data[temp.size()] -= temp[j].Data[k] * x[k].Data[i];
			}
		}
	}
	/*for (int i = 0; i < x.size(); i++) {
		for (int k = 0; k < x.size(); k++) {
			cout << x[i].Data[k] << " ";
		}
		cout << endl;
	}*/
	return x;
}

double MatrixOperate::Ope6(String^ input, std::vector<std::vector<Vector>> matrixs) {
	vector<Vector> det = count(input,matrixs);
	det = gauss(det);
	double detout = 1;
	for (int i = 0; i < det.size(); i++) {
		detout *= det[i].Data[i];
	}

	return abs(detout);
}

vector<Vector> MatrixOperate::Ope5(String^ input, std::vector<std::vector<Vector>> matrixs) {
	vector<Vector> origin = count(input, matrixs);
	return origin;
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
			else if (sorted[i] == "*") {
				if (temps[temps.size() - 2][0].Data.size() != temps[temps.size() - 1].size()) {
					throw "兩個matrix為無法互乘";
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
				for (int k = 0; k < temps[temps.size() - 2].size(); k++) {
					temps[temps.size() - 2][k].Data.push_back(temps[temps.size() - 1][k].Data[0]);
				}
				//塞進gauss2 再求B
				vector<Vector> out = gauss2(temps[temps.size() - 2]);
				Vector initial;
				vector<Vector> x(out.size(),initial);
				for (int k = out.size() - 1; k >= 0; k--) {
					x[k].Data.push_back(out[k].Data[out.size()] / out[k].Data[k]);
					for (int j = k - 1; j >= 0; j--) {
						out[j].Data[out.size()] -= out[j].Data[k]*x[k].Data[0];
					}
				}
				temps.resize(temps.size() - 2);
				temps.push_back(x);
			}
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

/*vector<Vector> gauss(vector<Vector> input) {
	int n = input.size();
	int row = input.size();
	int col = input[0].Data.size();
	for (int k = 0; k<n; k++)
	{
		for (int i = k; i<row; i++)
		{
			if (input[i].Data[k] != 0)
			{
				for (int j = 0; j<col; j++)
				{
					double temp = input[i].Data[j];
					input[i].Data[j] = input[k].Data[j];
					input[k].Data[j] = temp;
				}
				break;
			}
		}
		for (int i = k + 1; i<row; i++)
		{
			double percent = input[i].Data[k] / input[k].Data[k];
			if (input[k].Data[k] != 0 && input[i].Data[k] != 0)
			{
				for (int j = 0; j<col; j++)
				{
					input[i].Data[j] -= input[k].Data[j] * percent;
					if (fabs(input[i].Data[j]) < 0.0000000001)
						input[i].Data[j] = 0;
				}
			}
		}
	}
	int flag = 0;
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		flag = 0;
		for (int j = 0; j < col; j++)
		{
			if (input[i].Data[j] != 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag) count++;
	}
	return input;
}*/

vector<Vector> gauss(vector<Vector> input) {
	for (int i = 0; i< input.size(); i++) {
		double maxEl = 0;
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
					input[k].Data[j] += c*input[i].Data[j];
					if (fabs(input[k].Data[j]) < 0.000000001) input[k].Data[j] = 0;
				}
			}
		}
	}
	if (input[input.size()-1].Data[input.size()-1] != 0) {
		for (int i = 0; i < input.size()-1; i++) {
			int count = 0;
			for (int k = 0; k < input[i].Data.size(); k++) {
				if (input[i].Data[k] != 0) count++;
			}
			if (input[i].Data[input.size()-1] != 0 && count == 1) {
				input[i].Data[input.size()-1] = 0;
			}
		}
	}
	return input;
}
//a+x 後面有加x 
vector<Vector> gauss2(vector<Vector> input) {
	for (int i = 0; i < input.size(); i++) {
		/*double maxEl;
		int maxRow;
		maxEl = abs(input[i].Data[i]);
		maxRow = i;
		for (int k = i + 1; k < input.size(); k++) {
			if (abs(input[k].Data[i])>maxEl) {
				maxEl = input[k].Data[i];
				maxRow = k;
			}
		}
		for (int k = i; k < input.size()+1; k++) {
			double temp = input[maxRow].Data[k];
			input[maxRow].Data[k] = input[i].Data[k];
			input[i].Data[k] = temp;
		}*/
		for (int k = i + 1; k < input.size(); k++) {
			double c;
			if (input[i].Data[i] == 0) c = 0;
			else c = (input[k].Data[i] / input[i].Data[i])*(-1);
			for (int j = i; j < input.size() +1 ; j++) {
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