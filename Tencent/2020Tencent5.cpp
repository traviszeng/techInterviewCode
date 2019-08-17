#include<iostream>
#include<algorithm>
using namespace std;
int dp[100005][3];
int seq[100005][2];
int n;
// 0 work 1 sport 2 rest

int main() {
	cin >> n;
	for (int t = 0; t<2; ++t) {
		for (int i = 0; i < n; ++i) {
			cin >> seq[i][t];
		}
	}
	dp[0][0] = (seq[0][0] == 1) ? 0 : -1;
	dp[0][1] = (seq[0][1] == 1) ? 0 : -1;
	dp[0][2] = 1;
	for (int i = 1; i<n; ++i) {
		if (seq[i][0]) {// want work
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]);
			if (dp[i][0] == -1) {
				dp[i][0] = dp[i - 1][2];
			}
		}
		else {
			dp[i][0] = -1;
		}
		if (seq[i][1]) {// want work
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
			if (dp[i][1] == -1) {
				dp[i][1] = dp[i - 1][2];
			}
		}
		else {
			dp[i][1] = -1;
		}
		int m = 99999999;
		if (seq[i - 1][0]) {
			m = min(m, dp[i - 1][0]);
		}
		if (seq[i - 1][1]) {
			m = min(m, dp[i - 1][1]);
		}
		m = min(dp[i - 1][2] + 1, m + 1);
		dp[i][2] = m;

	}

	// 最后在dp[n-1][0],dp[n-1][1],dp[n-1][2]之中选出最小的不为-1【合法】的结果

}
