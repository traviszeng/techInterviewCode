/**
我们对序列SS不断执行rev操作，得到的一系列序列S1,S2,Sn。
再依次翻转每个序列的每一位，得到一系列序列T1,T2,Tn
例如"110011"可以生成{"110011","1100","11"}与{"001100","0011","00"}

如果TT是优秀的，当且仅当TT是由这两组序列拼接而成，并且第一组序列中最原始的序列SS不能接第二组序列中的序列。

可以使用dp来维护上述过程。令f[i][0/1]表示前i位是否优秀，且拼接的最后一个01串是不是初始序列SS。按定义转移即可。
*/

#include<bits/stdc++.h>
using namespace std;
char s[1005], t[1005];
int h[1005];
const int base = 773117, mod = 1e9 + 7;
int pr[1005];
int s1[1005], s2[1005], len;
int pos[1005];
int n, m;
int ghash(int l, int r)
{
	return ((h[r] - 1LL * h[l - 1] * pr[r - l + 1]) % mod + mod) % mod;
}
int dp[1005][2];
void solve()
{
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	n = strlen(s + 1), m = strlen(t + 1);
	for (int i = 1; i <= m; i++) h[i] = (1LL * h[i - 1] * base + t[i] - '0') % mod;
	int pc = 0; len = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] != s[i - 1]) {
			int h1 = 0, h2 = 0;
			for (int j = i; j <= n; j++) {
				h1 = (1LL * h1 * base + s[j] - '0') % mod;
				h2 = (1LL * h2 * base + 1 + '0' - s[j]) % mod;
			}
			if (!pc) {
				++len; s1[len] = h1; s2[len] = h2;
			}
			else {
				++len; s1[len] = h2; s2[len] = h1;
			}
			pos[len] = (n - i + 1);
			pc ^= 1;
		}
	}
	memset(dp, 0, sizeof(dp)); dp[0][1] = 1;
	for (int i = 1; i <= m; i++) {
		if (i >= pos[1] && ghash(i - pos[1] + 1, i) == s1[1] && (dp[i - pos[1]][0] || dp[i - pos[1]][1])) dp[i][1] = 1;
		for (int j = 2; j <= len; j++) {
			if (i >= pos[j] && ghash(i - pos[j] + 1, i) == s1[j] && (dp[i - pos[j]][0] || dp[i - pos[j]][1])) { dp[i][0] = 1; break; }
		}
		for (int j = 1; j <= len; j++) {
			if (i >= pos[j] && ghash(i - pos[j] + 1, i) == s2[j] && dp[i - pos[j]][0]) { dp[i][0] = 1; break; }
		}
	}
	if (dp[m][0] || dp[m][1]) puts("YES");
	else puts("NO");
	return;
}
int main()
{
	int t; scanf("%d", &t);
	pr[0] = 1;
	for (int i = 1; i <= 1000; i++) pr[i] = 1LL * pr[i - 1] * base % mod;
	while (t--) solve();
	return 0;
}