/**
链表排序
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
给定一个单向链表和一个整数m，将链表中小于等于m的节点移到大于m的节点之前，要求两部分中的节点各自保持原有的先后顺序

输入
输入数据包含两行，

第一行，整数m

第二行，空格分隔的整数序列

输出
逗号分隔的整数序列


样例输入
4
9 6 3 7 6 5
样例输出
3,9,6,7,6,5
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>


using namespace std;

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	};
};

int par(vector<int> &num, int start, int end) {
	int x = num[start];
	int i = start;
	int j = end;
	while (i < j) {
		while (i < j && num[j] >= x) j--;
		if (i >= j) break;
		num[i++] = num[j];

		while (i < j && num[i] < x) i++;
		if (i >= j) break;
		num[j--] = num[i];
	}
	num[i] = x;
	return i;
}


ListNode *partition(ListNode* head, int m) {
	
	if (head == nullptr) return nullptr;
	ListNode* smallHead = nullptr; //<=m的头
	ListNode* bigHead = nullptr; //>m的头
	ListNode* temp = head;
	ListNode* smallTemp = nullptr;
	ListNode *bigTemp = nullptr;
	while (temp != nullptr) {
		if (temp->val <= m) {
			if (smallHead == nullptr) {
				smallHead = temp;
				smallTemp = temp;
			}
			else {
				smallTemp->next = temp;
				smallTemp = smallTemp->next;
			}
		}
		else {
			if (bigHead == nullptr) {
				bigHead = temp;
				bigTemp = temp;
			}
			else {
				bigTemp->next = temp;
				bigTemp = bigTemp->next;
			}
		}
		temp = temp->next;
	}
	if (smallHead != nullptr) {
		smallTemp->next = bigHead;
		if(bigHead!=nullptr)
			bigTemp->next = nullptr;
	}
	else {
		smallHead = bigHead;
	}
	return smallHead;

}


int main() {
	ListNode* head = NULL;
	ListNode* node = NULL;
	int m;
	cin >> m;
	int v;
	while (cin >> v) {
		if (head == NULL) {
			node = new ListNode(v);
			head = node;
		}
		else {
			node->next = new ListNode(v);
			node = node->next;
		}
	}
	head = partition(head, m);
	if (head != NULL) {
		cout << head->val;
		node = head->next;
		delete head;
		head = node;
		while (head != NULL) {
			cout << "," << head->val;
			node = head->next;
			delete head;
			head = node;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}