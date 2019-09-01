/**
[编程|25分] 优先偶数的有序TopN
时间限制：C/C++ 1秒，其他语言 2秒
空间限制：C/C++ 32768K，其他语言 65536K
64bit IO Format: %lld
本题可使用本地IDE编码，不做跳出限制，编码后请点击“保存并调试”按钮进行代码提交。
题目描述

读入一个数列和N值，返回按优先级排序的N个数，满足:
（1）所有偶数优先级大于奇数

（2）同为偶数或同为奇数时，数值大的优先级高

输入描述:
每个测试输入的测试用例，包含一个用半角逗号（,）分开的自然数数列和1个参数N，数列和参数N用半角分号（;）隔开。

这里保证N小于数列的元素个数（不超过100）。
输出描述:
在一行内输出N个满足题目条件的自然数，用逗号隔开
示例1输入输出示例仅供调试，后台判题数据一般不包含示例
输入
复制
555503,772867,756893,339138,399447,40662,859037,628085,855723,974471,599631,636153,581541,174761,948135,411485,554033,858627,402833,546467,574367,360461,566480,755523,222921,164287,420256,40043,977167,543295,944841,917125,331763,188173,353275,175757,950417,284578,617621,546561,913416,258741,260569,630583,252845;10
输出
复制
913416,566480,420256,339138,284578,40662,977167,974471,950417,948135
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//返回true a>b
bool cmp(int a, int b) {
	if (a % 2 == 0 && b % 2 == 1)
		return true;
	else if (a % 2 == 1 && b % 2 == 0)
		return false;
	else
		return a > b;
}

int main() {
	string input;
	cin >> input;
	vector<int> num;
	string temp = "";
	int i;
	for (i = 0; i < input.length(); i++) {
		if (input[i] == ',' || input[i] == ';') {
			int tempNum = atoi(temp.c_str());
			num.push_back(tempNum);
			temp = "";
		}

		else {
			temp += input[i];
		}
	}

	int k = 0;
	k = atoi(temp.c_str());
	sort(num.begin(), num.end(), cmp);
	for (int i = 0; i < k; i++) {
		cout << num[i];
		if (i != k - 1) cout << ",";
	}
	system("pause");
}