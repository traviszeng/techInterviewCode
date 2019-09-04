/**
表达式解析
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
豚厂给自研的数据库设计了一套查询表达式，在这个表达式中括号表示将里面的字符串翻转。请你帮助实现这一逻辑

输入
一行字符串

输出
一行字符串

如果表达式括号不匹配，输出空字符串


样例输入
((ur)oi)
样例输出
iour
*/
#include<string>
#include<iostream>
#include<stack>
using namespace std;

string resolve(string expr) {
	stack<char> sChar;
	//stack<char> help;
	for (int i = 0; i < expr.length(); i++) {
		if (expr[i] == ')') {
			if (sChar.empty()) {
				return "";
			}
			string temp = "";
			while (!sChar.empty() &&  sChar.top() != '(') {
				temp += sChar.top();
				sChar.pop();
			}
			if (sChar.empty()) return "";
			else
				sChar.pop();//将(pop出来

			for (int j = 0; j < temp.length(); j++) {
				sChar.push(temp[j]);
			}
		}
		else {
			sChar.push(expr[i]);
		}
	}
	string result = "";
	while (!sChar.empty()) {
		if (sChar.top() == '(') return "";
		result += sChar.top();
		sChar.pop();
	}
	reverse(result.begin(), result.end());
	return result;
}

int main() {
	string res;

	string _expr;
	getline(cin, _expr);

	res = resolve(_expr);
	cout << res << endl;
	system("pause");
	return 0;

}