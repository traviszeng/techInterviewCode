/*
�ʼǲݸ�
ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 65536KB���������� 589824KB
��Ŀ������
��ӳ�д��һƪ�ʼǲݸ壬�����æ���������ݡ�

1.�����ַ�����Ӣ���ַ���"(" , ")" �� "<"��

2.Ӣ���ַ���ʾ�ʼ����ݡ�

3. (  ) ֮���ʾע�����ݣ��κ��ַ�����Ч�� ���ű�֤�ɶԳ��֡�

4. "<" ��ʾ�˸�, ɾȥǰ��һ���ʼ������ַ��� ���Ų��� "<" Ӱ�� ��

����
����һ���ַ��������� <= 10000.

���
���һ���ַ�������ʾ���յıʼ����ݡ�


��������
a<<b((c)<)
�������
b

��ʾ
a�˸�ɾ�����ˣ� ���������c��Ҫ,  ���һ��< ��Ч
*/
#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
int main() {
	string input;
	cin >> input;
	stack<char> charS;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '<') {
			if (!charS.empty()) {
				if (charS.top() == '(') {
					char temp = '(';
					charS.pop();
					if (!charS.empty())
						charS.pop();
					charS.push(temp);
				}
				else
					charS.pop();
			}
		}
		else if (input[i] == ')') {
			while (charS.top() != '(') {
				charS.pop();
			}

			charS.pop();
		}
		else {
			charS.push(input[i]);
		}
	}

	string result = "";
	while (!charS.empty()) {
		result += charS.top();
		charS.pop();
	}
	reverse(result.begin(), result.end());
	cout << result;
}