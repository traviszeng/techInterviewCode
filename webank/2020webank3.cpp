/*
永远不可能到达的地方
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
一般来讲，一个国家级景区，都包含着很多的景点，在这些景点之间，有着很多条路，任意两个景点之间，可能有很多条不重复经过某一景点的道路可以到达。有一位强迫症患者去游览某景区，这个景区中有n个景点，编号为1-n，入口在s景点，出口在t景点，景区中有m条路径连接某两个景点，他通过某些道路从s走向t，但是因为强迫症的缘故，他不希望重复经过某个景点，这就注定了有些景点他是不可能到达的，请问这样的景点有多少个？

输入
第一行有两个整数,n,m分别表示景点数量，路的数量(1<=n<=100,1<=m<=n(n-1)/2)。

接下来有m行，每行有两个正整数u和v，表示u景点和v景点之间存在一条路径。

最后一行是两个正整数 s，t，表示入口所在景点的编号和出口所在景点的编号。(1<=s,t<=n)

输出
输出仅包含k个整数，表示该游客永远不可能经过的景点，要求编号从小到大，k为不可能经过的景点数量，不需要输出。


样例输入
5 4
1 2
2 3
4 2
5 2
1 3
样例输出
4 5

提示
样例解释：
无论怎么通过4，5都一定会重复经过2景点，显然不满足游客的需求，因此，4号和5号结点一定无法到达。
**/

#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

struct node {
	int nodeNum;
	vector<node*> toNode;//存放可以从当前节点到达的节点列表
	node(int num) :nodeNum(num) {}
};



//深度遍历+回溯
bool dfs(vector<int> &path,node* cur,int endNode,vector<int> &resNodeList) {
	if (cur->nodeNum == endNode) {
		for (int i = 0; i < path.size(); i++) {
			auto it = find(resNodeList.begin(), resNodeList.end(), path[i]);
			if ( it!= resNodeList.end()) {
				resNodeList.erase(it);
			}
		}
		path.pop_back();
		return true;
	}

	bool isFind = false;
	for (int i = 0;i < cur->toNode.size(); i++) {
		//确保是简单路径
		if (find(path.begin(), path.end(), cur->toNode[i]->nodeNum) != path.end())
			continue;
		path.push_back(cur->toNode[i]->nodeNum);
		isFind = dfs(path, cur->toNode[i],endNode,resNodeList);
		//path.pop_back();
	}

	if (!isFind) {
		path.pop_back();
	}
	return false;
}



int main() {
	int n, m;
	cin >> n >> m;
	vector<node*> nodeList;
	int startNode, endNode;
	vector<int> resNodeList;
	//将节点放入nodeList
	for (int i = 0; i < n; i++) {
		nodeList.push_back(new node(i + 1));
		resNodeList.push_back(i + 1);
	}
	for (int i = 0; i < m; i++) {
		int in, out;
		cin >> in >> out;
		nodeList[in - 1]->toNode.push_back(nodeList[out - 1]);
	}

	
	cin >> startNode >> endNode;
	vector<int> path;
	path.push_back(startNode);
	dfs(path, nodeList[startNode - 1],endNode,resNodeList);
	for (int i = 0; i < resNodeList.size(); i++) {
		cout << resNodeList[i];
		if (i != resNodeList.size() - 1) {
			cout << " ";
		}
	}
	system("pause");
}