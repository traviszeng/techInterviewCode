/**
����һ����n��������������A��һ������sum,��ѡ������A�в������ֺ�Ϊsum�ķ�������
������ѡȡ������һ�����ֵ��±겻һ��,���Ǿ���Ϊ�ǲ�ͬ����ɷ�����
��������:
����Ϊ����:

��һ��Ϊ����������n(1 �� n �� 1000)��sum(1 �� sum �� 1000)

�ڶ���Ϊn��������A[i](32λ����)���Կո������
�������:
�������ķ�����
ʾ��1
����
5 15
5 5 10 2 3
���
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
