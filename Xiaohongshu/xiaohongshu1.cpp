/**

给定一个链表，每k个节点进行翻转，对于末尾不足k个节点的部分要保持原状。要求空间复杂度O(1)。
比如对于链表1->2->3->4->5，当k=2的时候，返回2->1->4->3->5，k=3的时候返回3->2->1->4->5。

*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode *pHead = head;
	ListNode *pNewHead = head;
	ListNode *pCur = new ListNode(-1);
	int n = 0;
	while (1) {
		ListNode *pStart = pHead;
		ListNode *pEnd = pHead;
		if (pStart == nullptr || pStart->next == nullptr) break;
		ListNode *pNext = pStart->next;

		int kk = k;
		while (kk--)
		{
			if (pEnd != nullptr)
				pEnd = pEnd->next;
			else {
				pEnd = pStart;
				break;
			}
		}
		if (pEnd == pStart)
			break;
		kk = k;
		while (--kk) {
			pNext = pStart->next;
			pStart->next = pNext->next;
			pNext->next = pHead;
			pHead = pNext;

		}
		if (n == 0) {
			pNewHead = pHead;
			//pCur->next = pNewHead;
		}
		pCur->next = pHead;
		for (int i = 0; i < k; i++)
			pCur = pCur->next;

		n++;
		pHead = pEnd;
	}
	return pNewHead;

}