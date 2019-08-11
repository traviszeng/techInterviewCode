/*
时间限制：C/C++ 1秒，其他语言 2秒
空间限制：C/C++ 65536K，其他语言 131072K
64bit IO Format: %lld
语言限定：C++11(clang++ 3.9), C++14(g++5.4), Java(javac 1.8), C(clang 3.9)
本题可使用本地IDE编码，不做跳出限制，编码后请点击“保存并调试”按钮进行代码提交。
题目描述
小A刚学了二进制，他十分激动。为了确定他的确掌握了二进制，你给他出了这样一道题目：给定N个非负整数，将这N个数字按照二进制下1的个数分类，二进制下1的个数相同的数字属于同一类。求最后一共有几类数字？

输入描述:
输入的第一行是一个正整数T（0<T<=10），表示样例个数。对于每一个样例，第一行是一个正整数N（0<N<=100），表示有多少个数字。接下来一行是N个由空格分隔的非负整数，大小不超过2^31 – 1。，
输出描述:
对于每一组样例，输出一个正整数，表示输入的数字一共有几类。
示例1输入输出示例仅供调试，后台判题数据一般不包含示例
输入

1
5
8 3 5 7 2
输出

3
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		
		map<int, int> ones;
		int types = 0;
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			int numOfOne = 0;
			while (temp != 0) {
				numOfOne += temp % 2;
				temp /= 2;
			}
			if (ones.find(numOfOne) != ones.end()) {
				ones[numOfOne] += 1;
			}
			else {
				ones[numOfOne] = 1;
				types += 1;
			}
		}
		cout << types << endl;


	}
}