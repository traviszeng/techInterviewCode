/**
Shopee的Orange Day
Shopee每个月都有属于大家的节日，每到这个时候，大家都会穿着橙色的T恤，吃着水果蛋糕，做着游戏。
瞧，今天又是Orange Day了，吃货小虾同学早早的来到现场，看看有没有什么吃的，
刚刚走进去就发现我们的前台mm愁眉苦脸的看着挂满礼物的发财树，细看发现，
发财树的树枝因为承重不均，东倒西歪。是时候展现真正的技术啦，小虾同学，
马上走上去，让前台mm把挂礼物的方案拿出来，前台mm拿出一大叠方案，小虾同学顿时傻眼了，
但是他马上想到了一个方法，写一个程序判断每种方案的承重误差，把不合格的都干掉就行了。
经过分析，把发财树抽象为一颗树。
只要发财树的从顶部到各个叶子的各个路径上面的最大最小重量的差值在方案的误差范围内，
就可以正常承重。

输入第一行表示数据样例数T，表示接下来会有T个相同格式的样例输入

每个样例输入如下

输入的第一行输入 n,（2 ≤ n ≤ 100000，节点的编号为0到n-1,0为根节点）组成，

第二行有 n 个数，表示每个节点挂的礼物的重量 w（1<= w<= 1000）
下面是n-1行，每行有两个整数，第一个数表示父节点的编号，第二个数表示子节点的编号

输出最大差值。
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

