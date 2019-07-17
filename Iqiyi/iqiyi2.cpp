/**

有N种食物，排成一排，选择里面的若干食物，但不能选择相邻的食物。一个也不选也是一种选择的方法。
问有多少种选择的方法？
输入：
一个整数n
输出：
一个正整数表示答案
样例输入：
3
样例输出：
5

*/


/**
	dp[i]表示1-i种食物共有多少种选法,
	若第i种食物被选，则i-1不可选即为dp[i-1]
	若第i种不被选，则为dp[i-2]
	所以dp[i] = dp[i-1]+dp[i-2]
*/
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int *dp = new int[n + 1];
	dp[0] = 1;
	dp[1] = 2;
	for (int i = 2; i < n + 1; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];
	system("pause");


}