/*
最小值
时间限制：C/C++ 2秒，其他语言 4秒
空间限制：C/C++ 262144K，其他语言 524288K
64bit IO Format: %lld
本题可使用本地IDE编码，不做跳出限制，编码后请点击“保存并调试”按钮进行代码提交。
题目描述
牛牛给度度熊出了一个数学题，牛牛给定数字，希望度度熊能找到一组非负整数满足且尽量小。
度度熊把这个问题交给了你，希望你能帮他解决。
输入描述:
一行三个数字

输出描述:
输出最小的。
示例1输入输出示例仅供调试，后台判题数据一般不包含示例
输入
复制
12 18 100
输出
复制
7
说明
当 a = 7, b = 0时候, (n-a)(m-b) = 90 <= k = 100，此时 a + b = 7是最小的解。
*/
#include<iostream>
#include<limits.h>
using namespace std;
int main() {
	long long  n, m, k;
	cin >> n >> m >> k;
	if (n*m <= k) {
		cout << 0;
		return 0;
	}
	long long  min = INT_MAX;
	if (n > m) {
		long long  a = 0;
		for (long long  b = 0; b <= m; b++) {
			if ((n)*(m - b) <= k && b < min) {
				min = a+b;
				break;
			}
		}
	}
	else {
		long long  b = 0;
		for (long long  a = 0; a <= n; a++) {
			if ((n-a)*(m) <= k && a < min) {
				min = a+b;
				break;
			}
		}
	}
	cout << min;
	system("pause");
}