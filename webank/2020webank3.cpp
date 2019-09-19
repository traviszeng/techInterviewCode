/*
��Զ�����ܵ���ĵط�
ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 65536KB���������� 589824KB
��Ŀ������
һ��������һ�����Ҽ��������������źܶ�ľ��㣬����Щ����֮�䣬���źܶ���·��������������֮�䣬�����кܶ������ظ�����ĳһ����ĵ�·���Ե����һλǿ��֢����ȥ����ĳ�����������������n�����㣬���Ϊ1-n�������s���㣬������t���㣬��������m��·������ĳ�������㣬��ͨ��ĳЩ��·��s����t��������Ϊǿ��֢��Ե�ʣ�����ϣ���ظ�����ĳ�����㣬���ע������Щ�������ǲ����ܵ���ģ����������ľ����ж��ٸ���

����
��һ������������,n,m�ֱ��ʾ����������·������(1<=n<=100,1<=m<=n(n-1)/2)��

��������m�У�ÿ��������������u��v����ʾu�����v����֮�����һ��·����

���һ�������������� s��t����ʾ������ھ���ı�źͳ������ھ���ı�š�(1<=s,t<=n)

���
���������k����������ʾ���ο���Զ�����ܾ����ľ��㣬Ҫ���Ŵ�С����kΪ�����ܾ����ľ�������������Ҫ�����


��������
5 4
1 2
2 3
4 2
5 2
1 3
�������
4 5

��ʾ
�������ͣ�
������ôͨ��4��5��һ�����ظ�����2���㣬��Ȼ�������ο͵�������ˣ�4�ź�5�Ž��һ���޷����
**/

#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

struct node {
	int nodeNum;
	vector<node*> toNode;//��ſ��Դӵ�ǰ�ڵ㵽��Ľڵ��б�
	node(int num) :nodeNum(num) {}
};



//��ȱ���+����
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
		//ȷ���Ǽ�·��
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
	//���ڵ����nodeList
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