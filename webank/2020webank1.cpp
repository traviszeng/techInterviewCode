/**
末尾的数
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
小明想知道 n! ，最后一位不为 0 的数字，你能告诉他吗？ n! = n*(n-1)*(n-2)*....*3*2*1
输入
一个正整数n（n<=5000）

输出
一位数答案，表示最后一位不为0的数字


样例输入
7
样例输出
4

提示
7！=5040 ，最后一位不为0的数字为4
*/
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int *num = new int[n + 1];
	int res = 1, count = 0;
	for (int i = 1; i < n + 1; i++) {
		num[i] = i;
		while (num[i] % 5 == 0) {
			count++;
			num[i] /= 5;
		}

		while (num[i] % 2 == 0 && count>0) {
			count--;
			num[i] /= 2;
		}
	}
	for (int i = 2; i < n + 1; i++) {
		res *= num[i];
		while (res % 10 == 0)
			res /= 10;
		res = res % 10;
	}
	cout << res;

}