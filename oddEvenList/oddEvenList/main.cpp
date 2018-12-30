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
		cout << node->val<<" -> NULL" << endl;
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
ListNode* oddEvenList(ListNode* head) {

	ListNode* odd = head;
	ListNode* even = nullptr;
	if (head != nullptr) {
		even = head->next;
	}
	else {
		return head;
	}
	ListNode* oddNode = odd;
	ListNode* evenNode = even;
	bool oddEven = true;
	while (evenNode != nullptr && evenNode->next != nullptr) {
		if (oddEven) {
			//cout << "odd:" << oddNode->val<<endl;
			oddNode->next = evenNode->next;
			oddNode = oddNode->next;
		}
		else {
			//cout << "even:" << evenNode->val << endl;
			evenNode->next = oddNode->next;
			evenNode = evenNode->next;
		}
		oddEven = !oddEven;
	}
	oddNode->next = even;

	return odd;
}

int main() {
	vector<int> nums({1,2,3,4,5});
	vector<int> nums1({ 2,1,3,5,6,4,7});
	ListNode* list = createList(nums1);
	printList(list);
	ListNode* oddEven = oddEvenList(list);
	printList(oddEven);
	cin.get();
	return 1;
}