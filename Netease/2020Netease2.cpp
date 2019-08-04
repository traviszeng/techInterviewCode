#include<bits\stdc++.h>
using namespace std;
//将一个二维的货物放置在二维的广场 有一些障碍物 看长宽为输入值的货物能否放入


/*
枚举货物放置的左上角，剩下的只需要检查某个矩形里面有没有障碍物。 
把障碍物看成1，空格看成0，维护二维前缀和，就可以快速查询矩形和。如果矩形和是0则可以放置。
*/
#pragma warning(disable : 4996)
int n, m, k;
int a[1005][1005];
int c, d;
void solve() {
	scanf("%d%d%d", &n, &m, &k);
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= k; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
	}

	scanf("%d%d", &c, &d);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= n - c + 1; i++) {
		for (int j = 1; j <= m - d + 1; j++) {
			int s = a[i + c - 1][j + d - 1] - a[i - 1][j + d - 1] - a[i + c - 1][j - 1] + a[i - 1][j - 1];
			if (!s) {
				puts("YES"); return;
			}
		}
	}
	puts("NO"); return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}