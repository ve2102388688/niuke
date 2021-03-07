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


ListNode* partition(ListNode* head, int x) {
	/**<这里需要两个额外的结点，因为那个是小于那个是大于，提前不知道 */
	ListNode *dummy1  = new ListNode(0);
	ListNode *dummy2  = new ListNode(0);

	ListNode *p = head;
	ListNode *pa = dummy1;		/**<less */
	ListNode *pb = dummy2;		/**<greater */

	while (p != nullptr) {
		if (p->val < x) {
			pa->next = p;
			pa = pa->next;
		} else {
			pb->next = p;
			pb = pb->next;
		}
		p = p->next;
	}
	ListNode *temp2 = dummy2->next;
	pa->next = temp2;
	pb->next = nullptr;
	delete dummy2;
	
	ListNode *temp1 = dummy1->next;			/**<释放内存 */
	delete dummy1;
	return temp1;
}

int main(int argc, char* argv[]) {
	
	vector<int> nums = {1,4,3,2,5,2};
	ListNode *list = creatList(nums);
	
	ListNode *output = partition(list, 3);
	printList(output);
	freeList(list);
	return 0;
}