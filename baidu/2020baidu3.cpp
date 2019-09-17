/**
������Ϸ
ʱ�����ƣ�C/C++ 2�룬�������� 4��
�ռ����ƣ�C/C++ 262144K���������� 524288K
64bit IO Format: %lld
�����ʹ�ñ���IDE���룬�����������ƣ���������������沢���ԡ���ť���д����ύ��
��Ŀ����
ţţ��ţ��������Ϸ����������ǰ����������һ��������ʼ�ŵ��Ǻڵ㣬�ŵ��ǰ׵㣬�������ǿյ㣬��������������ţţ����ѡ��һ���ڵ㲢�Ѹúڵ���Χ��ĳ���յ�Ⱦ�ɺ�ɫ��ţ�ÿ���ѡ��һ���׵㲢�Ѹð׵���Χ��ĳ���յ�Ⱦ�ɰ�ɫ��ֱ����һ������Ϳ�ˣ���һ����ʤ��
��������:
��һ��һ������ʾ��������
ÿ�����ݵ�һ��һ������ʾ���и��ڵ�
��������ÿ�и�������ʾ�͵���һ��������
�������:
ÿ�����ݶ�Ӧһ�У����ţţӮ�������niuniu"�����ţ��Ӯ���"niumei����
ʾ��1�������ʾ���������ԣ���̨��������һ�㲻����ʾ��
����
����
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
���
����
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
	int isBlackOrWhite; //0ΪδͿ 1Ϊ��ɫ -1 Ϊ��ɫ
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