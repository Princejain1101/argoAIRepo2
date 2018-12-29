#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};
ListNode* createList(unsigned int num) {

	ListNode* head = new ListNode(num%10);
	num = num / 10;
	ListNode* Node = head;
	while (num > 0) {
		int i = num % 10;
		ListNode* next = new ListNode(i);
		Node->next = next;
		Node = next;
		num = num / 10;
	}
	return head;
}
void printList(ListNode * node) {
	if (node != nullptr) {
		while (node->next != nullptr) {
			cout << node->val << " -> ";
			node = node->next;
		}
		cout << node->val << endl;
	}
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int carry = 0;

	int retNum = 0;
	int i = 0;
	while (l1 != nullptr && l2 != nullptr) {
		//cout << retNum << "\t"<< (l1->val + l2->val + carry) % 10<< "\t"<< (10^i) <<endl;
		retNum = retNum + (pow(10,i))*((l1->val + l2->val + carry)%10);
		//cout << retNum << endl;
		carry = (l1->val + l2->val + carry) / 10;
		i++;
		l1 = l1->next;
		l2 = l2->next;
	}
	while (l1 != nullptr) {
		retNum = retNum + (pow(10,i))*((l1->val + carry) % 10);
		carry = (l1->val + carry) / 10;
		i++;
		l1 = l1->next;
	}
	while (l2 != nullptr) {
		retNum = retNum + (pow(10,i))*((l2->val + carry) % 10);
		carry = (l2->val + carry) / 10;
		i++;
		l2 = l2->next;
	}
	if (carry > 0) {
		retNum = retNum + (pow(10, i))*carry;
	}
	return createList(retNum);
}
ListNode* addTwoNumbersMod(ListNode* l1, ListNode* l2) {
	int carry = 0;
	int i = 0;
	ListNode *Node = new ListNode(-1);
	ListNode *head = Node;
	while (l1 != nullptr && l2 != nullptr) {
		//cout << retNum << "\t"<< (l1->val + l2->val + carry) % 10<< "\t"<< (10^i) <<endl;
		ListNode* next = new ListNode((l1->val + l2->val + carry) % 10);
		Node->next = next;
		Node = next;
		//cout << retNum << endl;
		carry = (l1->val + l2->val + carry) / 10;
		l1 = l1->next;
		l2 = l2->next;
	}
	while (l1 != nullptr) {
		ListNode *next = new ListNode((l1->val + carry) % 10);
		Node->next = next;
		Node = next;
		carry = (l1->val + carry) / 10;
		l1 = l1->next;
	}
	while (l2 != nullptr) {
		ListNode *next = new ListNode((l2->val + carry) % 10);
		Node->next = next;
		Node = next;
		carry = (l2->val + carry) / 10;
		i++;
		l2 = l2->next;
	}
	if (carry > 0) {
		ListNode *next = new ListNode(carry);
		Node->next = next;
		Node = next;
	}
	return head->next;
}
int main() {

	ListNode* A = createList(342);
	ListNode* B = createList(465);
	printList(A);
	printList(B);
	printList(addTwoNumbersMod(A, B));
	cin.get();
	return 1;
}