/**
计算2020-10000之间素数的个数。
时间限制：C/C++ 1秒，其他语言 2秒
空间限制：C/C++ 32768K，其他语言 65536K
64bit IO Format: %lld
语言限定：C++11(clang++ 3.9), C++14(g++5.4), C(clang 3.9), Python(2.7.3), Python3(3.5.2), pypy2(pypy2.7.13), pypy3(pypy3.6.1), C#(mcs 5.20)
本题可使用本地IDE编码，不做跳出限制，编码后请点击“保存并调试”按钮进行代码提交。
题目描述

一个大于1的自然数，除了1和它自身外，不能被其他自然数整除的数叫做素数。请编写Python代码，计算2020-10000之间素数的个数。

输入描述:
No input
输出描述:
计算2020-10000之间素数的个数。
*/

#include<iostream>
using namespace std;
int main() {
	bool* isSu = new bool[10001];
	for (int i = 0; i <= 10000; i++) isSu[i] = true;
	for (int i = 2; i <= 10000 ; i++) {
		int j = 2; 
		while (i*j <= 10000) {
			isSu[i*j] = false;
			j++;
		}
	}
	int count = 0;
	for (int i = 2020; i < 10001; i++) {
		if (isSu[i]) count++;
	}
	cout << count;
	system("pause");
}