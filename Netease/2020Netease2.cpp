#include<bits\stdc++.h>
using namespace std;
//��һ����ά�Ļ�������ڶ�ά�Ĺ㳡 ��һЩ�ϰ��� ������Ϊ����ֵ�Ļ����ܷ����


/*
ö�ٻ�����õ����Ͻǣ�ʣ�µ�ֻ��Ҫ���ĳ������������û���ϰ�� 
���ϰ��￴��1���ո񿴳�0��ά����άǰ׺�ͣ��Ϳ��Կ��ٲ�ѯ���κ͡�������κ���0����Է��á�
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