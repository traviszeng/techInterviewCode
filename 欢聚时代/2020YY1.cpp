/**
类01背包问题
*/

#include<iostream>
using namespace std;
int main() {
	int n, m;
	cin >> m >> n;
	int *file_size = new int[n+1];
	int *pref = new int[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> file_size[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> pref[i];
	}
	long long *dp = new long long[m + 1];
	for (long long i = 0; i < m + 1; i++)
		dp[i] = 0;
	for (long long i = 1; i <= n; i++) {
		for (long long j = m; j >= 1; j--) {
			if (dp[j] <= dp[j - file_size[i]] + pref[i] && j - file_size[i] >= 0) {
				dp[j] = dp[j - file_size[i]] + pref[i];
			}
		}
	}
	cout << dp[m];
}