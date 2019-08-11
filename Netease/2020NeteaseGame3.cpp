/*
时间限制：C/C++ 1秒，其他语言 2秒
空间限制：C/C++ 65536K，其他语言 131072K
64bit IO Format: %lld
语言限定：C++11(clang++ 3.9), C++14(g++5.4), Java(javac 1.8), C(clang 3.9)
本题可使用本地IDE编码，不做跳出限制，编码后请点击“保存并调试”按钮进行代码提交。
题目描述
小A很喜欢字母N，他认为连续的N串是他的幸运串。有一天小A看到了一个全部由大写字母组成的字符串，他被允许改变最多2个大写字母（也允许不改变或者只改变1个大写字母），使得字符串中所包含的最长的连续的N串的长度最长。你能帮助他吗？

输入描述:
输入的第一行是一个正整数T（0 < T <= 20），表示有T组测试数据。对于每一个测试数据包含一行大写字符串S（0 < |S| <= 50000，|S|表示字符串长度）。

数据范围：

20%的数据中，字符串长度不超过100；

70%的数据中，字符串长度不超过1000；

100%的数据中，字符串长度不超过50000。
输出描述:
对于每一组测试样例，输出一个整数，表示操作后包含的最长的连续N串的长度。
示例1输入输出示例仅供调试，后台判题数据一般不包含示例
输入

3
NNTN
NNNNGGNNNN
NGNNNNGNNNNNNNNSNNNN
输出

4
10
18
*/

#include<iostream>
#include<string>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int ppMax = 0, preMax = 0, cur = 0;
		int numOfChange = 2;
		int maxSize = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'N')
				cur += 1;
			else {
				if (numOfChange > 0)
					numOfChange -= 1;
				ppMax = preMax;
				preMax = cur;
				cur = 0;
					
			}
			int temp = ppMax + preMax + cur + 2 - numOfChange;
			maxSize = maxSize > temp ? maxSize : temp;

		}
		cout << maxSize<<endl;
		
	}
	system("pause");
}