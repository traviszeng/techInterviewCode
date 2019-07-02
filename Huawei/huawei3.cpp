/**
	仿LISP的运算

	题目描述
	LISP语言唯一的语法就是括号要配对。 形如 (OP P1 P2 …)，括号内元素由单个空格分割。 其中第一个元素OP为操作符，后续元素均为其参数，参数个数取决于操作符类型 注意：参数 P1, P2 也有可能是另外一个嵌套的 (OP P1 P2 …) 当前OP类型为add/sub/mul/div(全小写)，分别代表整数的加减乘除法。简单起见，所以OP参数个数为2 举例：
	输入：(mul 3 -7)输出：-21
	输入：(add 1 2) 输出：3
	输入：(sub (mul 2 4) (div 9 3)) 输出 ：5
	输入：(div 1 0) 输出：error
	
	输入描述
	合法c字符串，字符串长度不超过512
	
	输出描述
	合法c字符串，字符包括'0'-'9',以及负号或者error
	
	输入样例
	(add 1 2 3)
	
	输出样例
	6

*/

#include<iostream>
#include<string>
#include<stack>
#include<cmath>
using namespace std;

int lispCalculator(string s) {
	//计算一个括号内的lisp表达式
	//返回其计算结果

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