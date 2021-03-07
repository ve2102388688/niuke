#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *head) : val(x), next(head) {}
};

ListNode* creatList(vector<int>& nums) {
	ListNode *dummy = new ListNode(-1, nullptr);
	ListNode *p = dummy;
	
	for(const auto& e: nums) {
		p->next = new ListNode(e);
		p = p->next;
	}
	
	ListNode *temp = dummy->next;
	delete dummy;
	return temp;
}

void printList(ListNode* head) {
	for (ListNode* p = head; p != nullptr; p=p->next)
		cout << p->val << ",";
}

void freeList(ListNode* head) {
	if (head == nullptr)
		return ;
	freeList(head->next);
	delete head;
}


ListNode* oddEvenList(ListNode *head) {
	/**<边界条件 */
	if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
		return head;
	
	ListNode *evenHead = head->next;
	/**<奇偶链表工作指针 */
	ListNode *pa = head;
	ListNode *pb = head->next;
	while (pa->next != nullptr && pa->next->next != nullptr) {
		pa->next = pa->next->next;
		pa = pa->next;
		
		pb->next = pb->next->next;
		pb = pb->next;
	}
	pa->next = evenHead;
	return head;
}


int main(int argc, char* argv[]) {
	
	vector<int> nums = {1,2,3,4,5};
	ListNode *list = creatList(nums);
	
	list = oddEvenList(list);
	printList(list);
	freeList(list);
	return 0;
}