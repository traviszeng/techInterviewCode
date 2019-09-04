/**
���ʽ����
ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 65536KB���������� 589824KB
��Ŀ������
�೧�����е����ݿ������һ�ײ�ѯ���ʽ����������ʽ�����ű�ʾ��������ַ�����ת���������ʵ����һ�߼�

����
һ���ַ���

���
һ���ַ���

������ʽ���Ų�ƥ�䣬������ַ���


��������
((ur)oi)
�������
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
				sChar.pop();//��(pop����

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