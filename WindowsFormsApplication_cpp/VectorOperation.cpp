#include "VectorOperate.h"
#include "stack"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"

#define PI 3.14159265
using namespace std;
Vector guess(vector<Vector> v);
Vector count(String^ input, std::vector<Vector> vectors);//四則運算
Vector VectorOperate::Ope16(String^ input, std::vector<Vector> vectors) {
	int num = 0;
	String^ a, ^ b;
	for (int i = 0; i < input->Length; i++) {
		if (input[i] == '(') num++;
		else if (input[i] == ')') break;
		else if (input[i] == ',') num++;
		else if (num == 1) {
			a += input[i];
		}
		else {
			b += input[i];
		}
	}
	//cout << s[0] << endl;
	//cout << s[1];
	int from = 0;
	int to = 0;
	//cout << "1";
	string s = "";
	for (int i = 0; i < a->Length; i++) {
		s += a[i];
	}
	//cout << s;
	for (unsigned int j = 0; j<vectors.size(); j++)
	{
		if (s == vectors[j].Name.c_str()) {
			from = j;
			break;
		}
	}
	s = "";
	for (int i = 0; i < b->Length; i++) {
		s += b[i];
	}
	//cout << s;
	for (unsigned int j = 0; j<vectors.size(); j++)
	{
		if (s == vectors[j].Name.c_str()) {
			to = j;
			break;
		}
	}
	//cout << from <<"  "<<to;
	Vector v;
	String^ ss = vectors[from].Data.size().ToString();
	string temp = "";
	for (int i = 0; i < ss->Length; i++) {
		temp += ss[i];
	}
	v.Name = temp;
	
	vector<Vector> matrix;
	for (int i = from; i <= to; i++) {
		matrix.push_back(vectors[i]);
	}
	for (int i = 0; i < matrix.size(); i++) {
		for (int k = 0; k < i;k++){
			double dotsum =0;
			double selfdot =0;
			for (int j = 0; j < matrix[k].Data.size(); j++) {
				selfdot += matrix[k].Data[j] * matrix[k].Data[j];
				dotsum += matrix[k].Data[j] * matrix[i].Data[j];
			}
			Vector temp;
			double q = dotsum / selfdot;//除法
			for (int j = 0; j < matrix[k].Data.size(); j++) {
				temp.Data.push_back(q*matrix[k].Data[j]);
			}
			for (int j = 0; j < matrix[k].Data.size(); j++) {
				matrix[i].Data[j] -= temp.Data[j];
			}
		}
	}
	double sum = 0; //儲存平方的值
	for (int i = 0; i < matrix.size(); i++) {
		for (int k = 0; k < matrix[i].Data.size(); k++) {
			sum += matrix[i].Data[k] * matrix[i].Data[k];
		}
		sum = pow(sum, 0.5);
		for (int k = 0; k < matrix[i].Data.size(); k++) {
			v.Data.push_back(matrix[i].Data[k] / sum);
		}
		sum = 0;
	}
	return v;
}


int VectorOperate::test(String^ input, std::vector<Vector> vectors) {
	string s = "";
	for (int i = 0; i < input->Length; i++) {
		s += input[i];
	}
	Vector v;
	for (unsigned int j = 0; j<vectors.size(); j++)
	{
		if (s == vectors[j].Name.c_str()) {
			v = vectors[j];
			break;
		}
	}
	return v.Data.size();
}

bool VectorOperate::Ope15(String^ input, std::vector<Vector> vectors) {
	//cout << "0";
	int num = 0;
	String^ a, ^ b;
	for (int i = 0; i < input->Length; i++) {
		if (input[i] == '(') num++;
		else if (input[i] == ')') break;
		else if (input[i] == ',') num++;
		else if (num == 1) {
			a += input[i];
		}
		else {
			b += input[i];
		}
	}
	//cout << s[0] << endl;
	//cout << s[1];
	int from = 0;
	int to = 0;
	//cout << "1";
	string s = "";
	for (int i = 0; i < a->Length; i++) {
		s += a[i];
	}
	//cout << s;
	for (unsigned int j = 0; j<vectors.size(); j++)
	{
		if (s == vectors[j].Name.c_str()) {
			from = j;
			break;
		}
	}
	s = "";
	for (int i = 0; i < b->Length; i++) {
		s += b[i];
	}
	//cout << s;
	for (unsigned int j = 0; j<vectors.size(); j++)
	{
		if (s == vectors[j].Name.c_str()) {
			to = j;
			break;
		}
	}
	//cout << from <<"  "<<to;
	vector<Vector> matrix;
	for (int i = from; i <= to; i++) {
		matrix.push_back(vectors[i]);
	}
	//--------------------高斯消去------------------
	Vector v = guess(matrix);
	for (int i = 0; i < v.Data.size(); i++) {
		if (v.Data[i] != 0)return false;
	}
	return true;
}

double  VectorOperate::Ope10(String^ input, std::vector<Vector> vectors) {
	int num = 0;
	String^ a, ^ b;
	for (int i = 0; i < input->Length; i++) {
		if (input[i] == '(') num++;
		else if (input[i] == ')') break;
		else if (input[i] == ',') num++;
		else if (num == 1) {
			a += input[i];
		}
		else {
			b += input[i];
		}
	}
	//cout << s[0] << endl;
	//cout << s[1];
	vector<Vector> com;
	com.push_back(count(a, vectors));//a
	com.push_back(count(b, vectors));//b
	double dotsum =0;//內積
	for (int i = 0; i < com[0].Data.size(); i++) {
		dotsum += com[0].Data[i] * com[1].Data[i];
	}
	double sum[2] = { 0,0 };//|a|^2 |b|^2
	for (int i = 0; i < com[0].Data.size(); i++) {
		sum[0] += com[0].Data[i] * com[0].Data[i];
	}

	for (int i = 0; i < com[1].Data.size(); i++) {
		sum[1] += com[1].Data[i] * com[1].Data[i];
	}

	double area = pow((sum[0] * sum[1] - pow(dotsum, 2)), 0.5)*0.5;
	return area;
}

double  VectorOperate::Ope13(String^ input, std::vector<Vector> vectors) {
	int num = 0;
	String^ a, ^ b;
	for (int i = 0; i < input->Length; i++) {
		if (input[i] == '(') num++;
		else if (input[i] == ')') break;
		else if (input[i] == ',') num++;
		else if (num == 1) {
			a += input[i];
		}
		else {
			b += input[i];
		}
	}
	//cout << s[0] << endl;
	//cout << s[1];
	vector<Vector> com;
	com.push_back(count(a, vectors));//a
	com.push_back(count(b, vectors));//b
	double dotsum = 0;//內積若為0 則垂直
	for (int i = 0; i < com[0].Data.size(); i++) {
		dotsum += com[0].Data[i] * com[1].Data[i];
	}
	//算出|a| |b|
	double sum[2] = { 0,0 };
	for (int i = 0; i < com[0].Data.size(); i++) {
		sum[0] += com[0].Data[i] * com[0].Data[i];
	}

	for (int i = 0; i < com[1].Data.size(); i++) {
		sum[1] += com[1].Data[i] * com[1].Data[i];
	}
	//dotsum = cos(theta)
	dotsum = dotsum / (pow(sum[0], 0.5)*pow(sum[1], 0.5));
	double angle = acos(dotsum) * 180 / PI;
	return angle;
}

bool  VectorOperate::Ope12(String^ input, std::vector<Vector> vectors) {
	//dot(a,b)/lbl/lbl * vector(b)
	int num = 0;
	String^ a, ^ b;
	for (int i = 0; i < input->Length; i++) {
		if (input[i] == '(') num++;
		else if (input[i] == ')') break;
		else if (input[i] == ',') num++;
		else if (num == 1) {
			a += input[i];
		}
		else {
			b += input[i];
		}
	}
	//cout << s[0] << endl;
	//cout << s[1];
	vector<Vector> com;
	com.push_back(count(a, vectors));//a
	com.push_back(count(b, vectors));//b
	double dotsum = 0;//內積若為0 則垂直
	for (int i = 0; i < com[0].Data.size(); i++) {
		dotsum += com[0].Data[i] * com[1].Data[i];
	}
	if (dotsum == 0) return true;
	else return false;
}

bool  VectorOperate::Ope11(String^ input, std::vector<Vector> vectors) {
	//dot(a,b)/lbl/lbl * vector(b)
	int num = 0;
	String^ a, ^ b;
	for (int i = 0; i < input->Length; i++) {
		if (input[i] == '(') num++;
		else if (input[i] == ')') break;
		else if (input[i] == ',') num++;
		else if (num == 1) {
			a += input[i];
		}
		else {
			b += input[i];
		}
	}
	//cout << s[0] << endl;
	//cout << s[1];
	vector<Vector> com;
	com.push_back(count(a, vectors));//a
	com.push_back(count(b, vectors));//b
	//判斷有沒有向量全為0
	bool parallel = false;
	for (int i = 0; i < com[0].Data.size(); i++) {
		if (com[0].Data[i] != 0) {
			parallel = true;
			break;
		}
	}
	if (!parallel) return parallel;
	parallel = false;
	for (int i = 0; i < com[1].Data.size(); i++) {
		if (com[1].Data[i] != 0) {
			parallel = true;
			break;
		}
	}
	if (!parallel) return parallel;
	double scale = 0;//先比兩個向量第一個數
	int temp = 0;
	while (scale == 0) {
		if (com[1].Data[temp] != 0)scale = com[0].Data[temp] / com[1].Data[temp];
		temp++;
	}
	//cout << scale<<endl;

	//比對
	for (int i = 1; i < com[0].Data.size(); i++) {
		//cout << com[0].Data[i] / com[1].Data[i] << endl;
		//若都為0 掠過
		if (com[0].Data[i] == com[1].Data[i] && com[1].Data[i] == 0) continue;
		//分母為0 false
		if (com[1].Data[i] == 0 && com[0].Data[i] != 0) return false;
		if (com[0].Data[i] / com[1].Data[i] != scale) {
			parallel = false;
			break;
		}
	}

	return parallel;
}
Vector  VectorOperate::Ope9(String^ input, std::vector<Vector> vectors) {
	//dot(a,b)/lbl/lbl * vector(b)
	//把input的名字傳進s中
	int num = 0;
	String^ a, ^ b;
	for (int i = 0; i < input->Length; i++) {
		if (input[i] == '(') num++;
		else if (input[i] == ')') break;
		else if (input[i] == ',') num++;
		else if (num == 1) {
			a += input[i];
		}
		else {
			b += input[i];
		}
	}
	//cout << s[0] << endl;
	//cout << s[1];
	vector<Vector> com;
	com.push_back(count(a, vectors));//a
	com.push_back(count(b, vectors));//b
	double sum = 0;//dot value
	for (int i = 0; i < com[0].Data.size(); i++) {
		sum += com[0].Data[i] * com[1].Data[i];
	}
	double bvalue;//com 分母 b的值
	for (int i = 0; i < com[1].Data.size(); i++) {
		bvalue += com[1].Data[i] * com[1].Data[i];
	}
	bvalue = pow(bvalue, 0.5);

	double comp = sum / (bvalue*bvalue);
	Vector v;
	for (int i = 0; i < com[1].Data.size(); i++) {
		v.Data.push_back(com[1].Data[i]*comp);
	}
	return v;
}

Vector  VectorOperate::Ope8(String^ input, std::vector<Vector> vectors) {
	int num = 0;
	String^ a, ^ b;
	for (int i = 0; i < input->Length; i++) {
		if (input[i] == '(') num++;
		else if (input[i] == ')') break;
		else if (input[i] == ',') num++;
		else if (num == 1) {
			a += input[i];
		}
		else {
			b += input[i];
		}
	}
	//cout << s[0] << endl;
	//cout << s[1];
	vector<Vector> com;
	com.push_back(count(a, vectors));//a
	com.push_back(count(b, vectors));//b
	double sum = 0;//dot value
	for (int i = 0; i < com[0].Data.size(); i++) {
		sum += com[0].Data[i] * com[1].Data[i];
	}
	double bvalue;//com 分母
	for (int i = 0; i < com[1].Data.size(); i++) {
		bvalue += com[1].Data[i] * com[1].Data[i];
	}
	bvalue = pow(bvalue, 0.5);

	Vector ans;
	ans.Data.push_back(sum / bvalue);

	return ans;
}

Vector  VectorOperate::Ope7(String^ input, std::vector<Vector> vectors) {
	int num = 0;
	String^ a,^ b;
	for (int i = 0; i < input->Length; i++) {
		if (input[i] == '(') num++;
		else if (input[i] == ')') break;
		else if (input[i] == ',') num++;
		else if (num == 1) {
			a += input[i];
		}
		else {
			b += input[i];
		}
	}
	//cout << s[0] << endl;
	//cout << s[1];
	vector<Vector> cross;
	cross.push_back(count(a, vectors));//a
	cross.push_back(count(b, vectors));//b
	Vector ans;

	//cout << cross[1].Data.size();
	//外積公式
	for (int i = 0; i < 3; i++) {
		double sum = 0;
		sum += cross[0].Data[(i + 1) % 3] * cross[1].Data[(i + 2) % 3] - cross[0].Data[(i + 2) % 3] * cross[1].Data[(i + 1) % 3];
		ans.Data.push_back(sum);
	}
	/*cx = aybz − azby
		cy = azbx − axbz
		cz = axby − aybx*/
	return ans;
}

Vector  VectorOperate::Ope6(String^ input, std::vector<Vector> vectors) {
	Vector norm;
	norm = count(input, vectors);
	double sum; //儲存平方的值
	for (int i = 0; i < norm.Data.size(); i++) {
		sum += norm.Data[i] * norm.Data[i];
	}
	sum = pow(sum, 0.5);
	Vector normal;
	for (int i = 0; i < norm.Data.size(); i++) {
		normal.Data.push_back(norm.Data[i] / sum);
	}

	return normal;
}

double VectorOperate::Ope5(String^ input, std::vector<Vector> vectors) {
	Vector norm;
	norm = count(input, vectors);
	double sum; //儲存平方的值
	for (int i = 0; i < norm.Data.size(); i++) {
		sum += norm.Data[i] * norm.Data[i];
	}

	sum = pow(sum, 0.5);
	return sum;
}

Vector VectorOperate::Ope1(String^ input, vector<Vector> vectors) {
	Vector v = count(input, vectors);
	//--------------------------------------------------------------------------------//
	//cout << temps.size();
	//cout << temps[0].Name;
	//cout << temps[0].Name.size();
	//cout << temps[0].Data[0];
	//for (int i = 0; i < temps[0].Data.size(); i++) cout << temps[0].Data[i]<< " ";
	//for (int i = 0; i<temps.size(); i++) std::cout << temps[i].Name << "  ";
	//cout << "\n";
	//for (int i = 0; i<sorted.size(); i++) std::cout << sorted[i]<< "  ";
	//cout << "\n";
	return v;
}

Vector count(String^ input, std::vector<Vector> vectors) {
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
	vector<Vector> temps;
	for (int i = 0; i < sorted.size(); i++) {
		if (sorted[i] == "+" || sorted[i] == "-" || sorted[i] == "*" || sorted[i] == "/") {
			//遇到加號
			if (sorted[i] == "+") {
				//cout << temps[temps.size() - 1].Name[0];
				//若兩個皆為int 非vector
				if (temps[temps.size() - 1].Name == temps[temps.size() - 2].Name&& temps[temps.size() - 2].Name == "int") {
					//增加這個進去
					Vector add;
					add.Name = "int";
					//定義出一個vector 名字叫int 並且跟其他的vector有一樣的長度
					vector<double> v(temps[temps.size() - 1].Data.size(), temps[temps.size() - 1].Data[0] + temps[temps.size() - 2].Data[0]);
					add.Data = v;

					temps.resize(temps.size() - 2);
					temps.push_back(add);
				}
				//當兩個都是vector時
				else if (temps[temps.size() - 1].Name[0] == temps[temps.size() - 2].Name[0] && temps[temps.size() - 2].Name[0] == '$') {
					if (temps[temps.size() - 1].Data.size() != temps[temps.size() - 2].Data.size()) {
						throw "Can't Compute : size of vectors aren't the same";
					}
					Vector add;
					add.Name = "$addvector";
					vector<double> v;
					for (int i = 0; i < temps[temps.size() - 1].Data.size(); i++) {
						//cout << temps[temps.size() - 1].Data[i] << "  ";
						v.push_back(temps[temps.size() - 1].Data[i] + temps[temps.size() - 2].Data[i]);
					}
					add.Data = v;
					temps.resize(temps.size() - 2);
					temps.push_back(add);
				}
				//一個是vector一個是int時
				else {
					if (temps[temps.size() - 1].Data.size() != temps[temps.size() - 2].Data.size()) {
						throw "Can't Compute : int + vector error: 請確實使用括號";
					}
				}
			}
			//遇到乘號
			else if (sorted[i] == "*") {
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
			}
		}
		//將sorted塞進temps
		else {
			for (unsigned int j = 0; j < vectors.size(); j++)
			{
				if (sorted[i] == vectors[j].Name.c_str()) {
					temps.push_back(vectors[j]);
					break;
				}
			}
		}
	}
	return temps[0];
}

Vector guess(vector<Vector> v) {
	int datanum = v[0].Data.size();
	Vector temp;
	for (int i = 0; i < datanum; i++) {
		temp.Data.push_back(0);
	}
	v.push_back(temp);
	for (int i = 0; i < datanum; i++) {
		double maxel = abs(v[i].Data[i]);
		int maxrow = i;
		for (int k = i + 1; k < datanum; k++) {
			if (abs(v[i].Data[k])>maxel) {
				maxel = v[i].Data[k];
				maxrow = k;
			}
		}
		for (int k = i; k < datanum; k++) {
			double temp = v[k].Data[maxrow];
			v[k].Data[maxrow] = v[k].Data[i];
			v[k].Data[i] = temp;
		}
		for (int k = i + 1; k < datanum; k++) {
			double c = (v[i].Data[k] / v[i].Data[i])*(-1);
			for (int j = i; j < datanum; j++) {
				if (i == j) {
					v[j].Data[k] = 0;
				}
				else {
					v[j].Data[k] += c*v[j].Data[i];
				}
			}
		}
	}
	Vector out;
	vector<double> x(datanum,0);
	for (int i = datanum-1; i >= 0; i--) {
		if (v[i].Data[i] == 0) x[i] = 0;
		else x[i] = v[datanum].Data[i] / v[i].Data[i];
		for (int k = i - 1; k >= 0; k--) {
			v[datanum].Data[k] -= v[i].Data[k] * x[i];
		}
		out.Data.push_back(x[i]);
	}
	return out;
}