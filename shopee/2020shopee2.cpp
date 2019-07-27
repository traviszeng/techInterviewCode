/**
给定一个有n个正整数的数组A和一个整数sum,求选择数组A中部分数字和为sum的方案数。
当两种选取方案有一个数字的下标不一样,我们就认为是不同的组成方案。
输入描述:
输入为两行:

第一行为两个正整数n(1 ≤ n ≤ 1000)，sum(1 ≤ sum ≤ 1000)

第二行为n个正整数A[i](32位整数)，以空格隔开。
输出描述:
输出所求的方案数
示例1
输入
5 15
5 5 10 2 3
输出
4

*/


#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, sum;
	cin >> n >> sum;
	int *num = new int[n];
	int numSum = 0;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		numSum += num[i];
	}
	if (numSum < sum) {
		cout << 0;
		return 0;
	}
	if (numSum == sum) {
		cout << 1;
		return 0;
	}

	vector<int> temp(sum + 1, 0);
	temp[0] = 1;
	vector<vector<int>> dp(n + 1, temp);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j >= num[i - 1]) {
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - num[i - 1]];
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[n][sum];
	system("pause");


}
