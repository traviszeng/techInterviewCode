/**
	��LISP������

	��Ŀ����
	LISP����Ψһ���﷨��������Ҫ��ԡ� ���� (OP P1 P2 ��)��������Ԫ���ɵ����ո�ָ ���е�һ��Ԫ��OPΪ������������Ԫ�ؾ�Ϊ���������������ȡ���ڲ��������� ע�⣺���� P1, P2 Ҳ�п���������һ��Ƕ�׵� (OP P1 P2 ��) ��ǰOP����Ϊadd/sub/mul/div(ȫСд)���ֱ���������ļӼ��˳����������������OP��������Ϊ2 ������
	���룺(mul 3 -7)�����-21
	���룺(add 1 2) �����3
	���룺(sub (mul 2 4) (div 9 3)) ��� ��5
	���룺(div 1 0) �����error
	
	��������
	�Ϸ�c�ַ������ַ������Ȳ�����512
	
	�������
	�Ϸ�c�ַ������ַ�����'0'-'9',�Լ����Ż���error
	
	��������
	(add 1 2 3)
	
	�������
	6

*/

#include<iostream>
#include<string>
#include<stack>
#include<cmath>
using namespace std;

int lispCalculator(string s) {
	//����һ�������ڵ�lisp���ʽ
	//�����������

	string op = s.substr(1, 3);
	if (op == "add") {
		int sum = 0;
		int num = 0;
		bool isNeg = false;
		for (int i = 5; i < s.length(); i++) {
			if (s[i] >= '0' &&s[i] <= '9') {
				if (num != 0)
					num *= 10;
				num += s[i] - '0';
			}
			else if (s[i] == '-')
				isNeg = true;
			else {
				if (isNeg)
					num = -num;
				sum += num;
				num = 0;
				isNeg = false;
			}
		}
		return sum;
	}
	else if (op == "mul") {
		int sum = 1;
		int num = 0;
		bool isNeg = false;
		for (int i = 5; i < s.length(); i++) {
			if (s[i] >= '0' &&s[i] <= '9') {
				if (num != 0)
					num *= 10;
				num += s[i] - '0';
			}
			else if (s[i] == '-')
				isNeg = true;
			else if (num == 0)
				continue;
			else {
				if (isNeg)
					sum *= -1;
				sum *= num;
				num = 0;
				isNeg = false;
			}
		}
		return sum;
	}
	else if (op == "div") {
		int num1 = 0;
		int num2 = INT_MIN;
		bool isNeg = false;
		for (int i = 5; i < s.length()-1; i++) {
			if (s[i] >= '0' &&s[i] <= '9') {
				if (num1 != 0)
					num1 *= 10;
				num1 += s[i] - '0';
			}
			else if (s[i] == '-')
				isNeg = true;
			else {
				if (isNeg)
					num1 = -num1;
				if(num2==INT_MIN)
					num2 = num1;
				num1 = 0;
				isNeg = false;
				
			}
		}
		
		if (num1 == 0)//ERROR
			return INT_MAX;
		if (isNeg)
			num1 = -num1;
		return num2 / num1;

	}
	else {
		int num1 = 0;
		int num2 = INT_MIN;
		bool isNeg = false;
		for (int i = 5; i < s.length()-1; i++) {
			if (s[i] >= '0' &&s[i] <= '9') {
				if (num1 != 0)
					num1 *= 10;
				num1 += s[i] - '0';
			}
			else if (s[i] == '-')
				isNeg = true;
			else {
				if (isNeg)
					num1 = -num1;
				if(num2==INT_MIN)
					num2 = num1;
				num1 = 0;
				isNeg = false;
			}
		}
		if (isNeg)
			num1 = -num1;
		
		
		return num2 - num1;
	}
}

string& replace_all(string& str, const string& old_value, const string& new_value)
{
	while (true) {
		string::size_type pos(0);
		if ((pos = str.find(old_value)) != string::npos)
			str.replace(pos, old_value.length(), new_value);
		else break;
	}
	return str;
}

int main() {
	string lisp;
	getline(cin,lisp);

	stack<char> s;
	while (lisp.find('(') != string::npos) {
		for (int i = 0; i < lisp.length(); i++) {
			if (lisp[i] == ')') {
				string l = ")";
				while (s.top() != '(') {
					l.insert(0, 1, s.top());
					s.pop();
				}
				l.insert(0, 1, s.top());
				s.pop();
				int val = lispCalculator(l);
				if (val == INT_MAX) {
					cout << "error";
					return 0;
				}
				lisp = replace_all(lisp, l, to_string(val)); break;
			}
			else {
				s.push(lisp[i]);
			}
		}
	}

	cout << lisp;

	system("pause");
	return 0;
}