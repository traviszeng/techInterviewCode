/**
Shopee��Orange Day
Shopeeÿ���¶������ڴ�ҵĽ��գ�ÿ�����ʱ�򣬴�Ҷ��ᴩ�ų�ɫ��T��������ˮ�����⣬������Ϸ��
�ƣ���������Orange Day�ˣ��Ի�СϺͬѧ����������ֳ���������û��ʲô�Եģ�
�ո��߽�ȥ�ͷ������ǵ�ǰ̨mm��ü�����Ŀ��Ź�������ķ�������ϸ�����֣�
����������֦��Ϊ���ز������������ᡣ��ʱ��չ�������ļ�������СϺͬѧ��
��������ȥ����ǰ̨mm�ѹ�����ķ����ó�����ǰ̨mm�ó�һ���������СϺͬѧ��ʱɵ���ˣ�
�����������뵽��һ��������дһ�������ж�ÿ�ַ����ĳ������Ѳ��ϸ�Ķ��ɵ������ˡ�
�����������ѷ���������Ϊһ������
ֻҪ�������ĴӶ���������Ҷ�ӵĸ���·������������С�����Ĳ�ֵ�ڷ�������Χ�ڣ�
�Ϳ����������ء�

�����һ�б�ʾ����������T����ʾ����������T����ͬ��ʽ����������

ÿ��������������

����ĵ�һ������ n,��2 �� n �� 100000���ڵ�ı��Ϊ0��n-1,0Ϊ���ڵ㣩��ɣ�

�ڶ����� n ��������ʾÿ���ڵ�ҵ���������� w��1<= w<= 1000��
������n-1�У�ÿ����������������һ������ʾ���ڵ�ı�ţ��ڶ�������ʾ�ӽڵ�ı��

�������ֵ��
*/

#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int fa[100005], weight[100005], dp[100005][2];
bool leaf[100005];
int dp_dfs(int x) {
	if (dp[x][0] == 0) {
		dp_dfs(fa[x]);
		dp[x][0] = max(weight[x], dp[fa[x]][0]);
		dp[x][1] = min(weight[x], dp[fa[x]][1]);
	}
	return 0;
}
int main()
{
	int T, n, x, y;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d", &n);
		memset(fa, 0, sizeof(fa));
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i<n; i++) {
			scanf("%d", &weight[i]);
			leaf[i] = true;
		}
		for (int i = 0; i<n - 1; i++) {
			scanf("%d %d", &x, &y);
			fa[y] = x;
			leaf[x] = false;
		}
		dp[0][0] = dp[0][1] = weight[0];
		int max_diff = 0;
		for (int i = 0; i<n; i++) {
			if (leaf[i]) {
				dp_dfs(i);
				max_diff = max(max_diff, dp[i][0] - dp[i][1]);
			}
		}
		printf("%d\n", max_diff);
	}
	return 0;
}

