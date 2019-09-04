/**
��������
ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 65536KB���������� 589824KB
��Ŀ������
����һ�����������һ������m����������С�ڵ���m�Ľڵ��Ƶ�����m�Ľڵ�֮ǰ��Ҫ���������еĽڵ���Ա���ԭ�е��Ⱥ�˳��

����
�������ݰ������У�

��һ�У�����m

�ڶ��У��ո�ָ�����������

���
���ŷָ�����������


��������
4
9 6 3 7 6 5
�������
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
	ListNode* smallHead = nullptr; //<=m��ͷ
	ListNode* bigHead = nullptr; //>m��ͷ
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