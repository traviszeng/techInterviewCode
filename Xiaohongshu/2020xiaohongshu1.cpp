/*
笔记草稿
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
薯队长写了一篇笔记草稿，请你帮忙输出最后内容。

1.输入字符包括英文字符，"(" , ")" 和 "<"。

2.英文字符表示笔记内容。

3. (  ) 之间表示注释内容，任何字符都无效。 括号保证成对出现。

4. "<" 表示退格, 删去前面一个笔记内容字符。 括号不受 "<" 影响 。

输入
输入一行字符串。长度 <= 10000.

输出
输出一行字符串，表示最终的笔记内容。


样例输入
a<<b((c)<)
样例输出
b

提示
a退格删除掉了， 括号里面的c不要,  最后一个< 无效
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