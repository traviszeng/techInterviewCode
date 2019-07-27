/*
单向链表去重 元素先后位置保持不变
**/


#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

struct linkNode {
	int val;
	linkNode* next;
	linkNode(int v) :val(v), next(nullptr) {}
};

int main() {
	int temp;
	map<int,int> numMap;
	vector<int> num;
	while (cin >> temp) {
		if (numMap.find(temp) == numMap.end()) {
			num.push_back(temp);
			numMap[temp] = 1;
		}
	}

	for (int i = 0; i < num.size()-1; i++) {
		cout << num[i] << " ";
	}
	cout << num[num.size() - 1];
	system("pause");
		
}