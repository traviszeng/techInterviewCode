/**
树上游戏
时间限制：C/C++ 2秒，其他语言 4秒
空间限制：C/C++ 262144K，其他语言 524288K
64bit IO Format: %lld
本题可使用本地IDE编码，不做跳出限制，编码后请点击“保存并调试”按钮进行代码提交。
题目描述
牛牛和牛妹在做游戏，在他们面前的桌子上有一棵树，初始号点是黑点，号点是白点，其他都是空点，两人轮流操作，牛牛可以选择一个黑点并把该黑点周围的某个空点染成黑色，牛妹可以选择一个白点并把该白点周围的某个空点染成白色，直到有一方不能涂了，另一方获胜。
输入描述:
第一行一个数表示数据组数
每组数据第一行一个数表示树有个节点
接下来行每行个数，表示和点有一条边相连
输出描述:
每组数据对应一行，如果牛牛赢则输出”niuniu"，如果牛妹赢输出"niumei“。
示例1输入输出示例仅供调试，后台判题数据一般不包含示例
输入
复制
2
7
3 6
1 2
3 1
7 4
5 7
1 4
4
1 4
4 2
2 3
输出
复制
niuniu
niumei
*/
/*
#include<iostream>
#include<vector>
using namespace std;

struct node {
	vector<node*> neighbor;
	int val;
	int isBlackOrWhite; //0为未涂 1为黑色 -1 为白色
	node(int val) {
		val = val;
		isBlackOrWhite = 0;
		if (val == 1) isBlackOrWhite = 1;
	}
};


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		vector<node*> nodeList;
		for (int i = 0; i < num; i++) {
			nodeList.push_back(new node(i + 1));
		}
		nodeList[num - 1]->isBlackOrWhite = -1;
		for (int i = 0; i < num - 1; i++) {
			int a, b;
			cin >> a >> b;
			nodeList[a - 1]->neighbor.push_back(nodeList[b - 1]);
			nodeList[b - 1]->neighbor.push_back(nodeList[a - 1]);
		}
		cout << "niuniu" << endl;
	}
}*/

#include<bits/stdc++.h>
using namespace std;
int t, n, a, b;
vector<int> v[100005];
bool vis1[100005], vis2[100005];
void dfs1(int index) {
	if (index == n)return;
	vis1[index] = true;
	for (int i = 0; i < v[index].size(); i++) {
		if (vis1[v[index][i]] == false)dfs1(v[index][i]);
	}
}
void dfs2(int index) {
	if (index == 1)return;
	vis2[index] = true;
	for (int i = 0; i < v[index].size(); i++) {
		if (vis2[v[index][i]] == false) dfs2(v[index][i]);
	}
}

int main() {

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < 100005; i++) {
			v[i].clear();
		}
		fill(vis1, vis1 + 100005, 0);
		fill(vis2, vis2 + 100005, 0);
		for (int i = 0; i < n - 1; i++) {
			scanf("%d%d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int res1 = 0, res2 = 0;
		dfs1(1);
		dfs2(n);
		for (int i = 2; i < n; i++) {
			if (vis1[i]) {
				if (vis2[i]) {
					res1++;
					res2++;
				}
				else {
					res1 += 2;
				}
			}
			else {
				if (vis1[2]) {
					res2 += 2;
				}

			}
		}
		res1 = res1 / 2 + res1 % 2);
		res2 = res2 / 2;
		if (res1 > res2)printf("niuniu\n");
		else printf("niumei\n");

	}
	return 0;
}