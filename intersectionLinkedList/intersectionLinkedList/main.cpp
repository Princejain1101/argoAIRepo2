#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};
void printList(ListNode* node) {
	if (node != nullptr) {
		while (node->next != nullptr) {
			cout << node->val << " -> ";
			node = node->next;
		}
		cout << node->val << " -> NULL" << endl;
	}
}
ListNode* createList(vector<int> &nums) {
	ListNode* Node = new ListNode(-1);
	ListNode* head = Node;
	for (auto &i : nums) {
		ListNode* next = new ListNode(i);
		Node->next = next;
		Node = next;
	}
	return head->next;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	int lenA = 0;
	int lenB = 0;
	ListNode* nodeA = headA;
	ListNode* nodeB = headB;

	while (nodeA != nullptr) {
		lenA++;
		nodeA = nodeA->next;
	}
	while (nodeB != nullptr) {
		lenB++;
		nodeB = nodeB->next;
	}
	//cout << "lenA:" << lenA << endl;
	//cout << "lenB:" << lenB << endl;
	nodeA = headA;
	nodeB = headB;

	int diff = abs(lenA - lenB);

	//cout << "diff:" << diff << endl;
	if (lenA > lenB) {
		while (diff > 0) {
			nodeA = nodeA->next;
			diff--;
		}
	}
	else {
		while (diff > 0) {
			nodeB = nodeB->next;
			diff--;
		}
	}
	//cout << "diff:" << diff << endl;
	//cout << "nodeA->val: " << nodeA->val << endl;
	//cout << "nodeB->val: " << nodeB->val << endl;

	while (nodeA != nodeB) {
		nodeA = nodeA->next;
		nodeB = nodeB->next;
	}
	return nodeA;
}

int main() {
	vector<int> numsA({0,9,1,2,4});
	vector<int> numsB({3});

	ListNode* listA = createList(numsA);
	ListNode* listB = createList(numsB);

	ListNode* nodeA = listA;
	int a = 3;
	while (a > 0) {
		nodeA = nodeA->next;
		a--;
	}
	listB->next = nodeA;
	printList(listA);
	printList(listB);

	ListNode *inter = getIntersectionNode(listA, listB);

	if(inter != nullptr)
		cout << inter->val << endl;
	cin.get();
	return 1;
}