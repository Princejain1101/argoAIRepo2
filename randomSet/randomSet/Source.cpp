#include <iostream>
#include <vector>
#include <unordered_map>
#include <time.h>

using namespace std;
struct LinkListNode {
	int val;
	LinkListNode* next;
	LinkListNode* prev;
	LinkListNode(int x) :val(x), next(nullptr), prev(nullptr) {}
};

LinkListNode* insertNode(LinkListNode* node, int val) {
	LinkListNode* newNode = new LinkListNode(val);
	node->next = newNode;
	newNode->prev = node;
	return newNode;
}
LinkListNode* removeNode(LinkListNode* node) {
	LinkListNode* ret;
	if (node->next == nullptr) {
		ret = node->prev;
		if (ret != nullptr) {
			node->prev = nullptr;
			delete node;
		}
		else {
			delete node;
		}
		return ret;
	}
	else {
		if (node->prev != nullptr) {
			node->prev->next = node->next;
			node->next->prev = node->prev;
			delete node;
		}
		else {
			node->next->prev = nullptr;
			delete node;
		}
		return nullptr;
	}
}

class RandomizedSet {
	unordered_map<int,LinkListNode*> randomSet;
	LinkListNode *linkList, *currentNode;
	int size;
public:
	RandomizedSet() {
		linkList = new LinkListNode(NULL);
		currentNode = linkList;
		size = 0;
	}
	bool insert(int val) {
		if (randomSet.find(val) != randomSet.end()) {
			return false;
		}
		currentNode = insertNode(currentNode, val);
		size++;
		std::pair<int, LinkListNode*> p(val, currentNode);
		randomSet.insert(p);
		return true;
	}
	bool remove(int val) {
		auto it = randomSet.find(val);
		if (it == randomSet.end()) {
			return false;
		}
		LinkListNode* node = removeNode(it->second);
		if (node != nullptr) {
			currentNode = node;
		}
		size--;
		randomSet.erase(val);
		return true;
	}
	int getRandom() {
		int N = rand() % size;
		LinkListNode* node = linkList->next;
		while (N > 0 && node!=nullptr) {
			node = node->next;
			N--;
		}
		return node->val;
	}
};

int main() {
	srand(time(NULL));
	RandomizedSet obj;
	cout<< "insert:"<<obj.insert(3);
	cout << "insert:" << obj.insert(-2);
	cout << "remove:" << obj.remove(2);
	cout << "insert:" << obj.insert(1);
	cout << "insert:" << obj.insert(-3);
	cout << "insert:" << obj.insert(-2);
	cout << "remove:" << obj.remove(-2);
	cout << "remove:" << obj.remove(3);
	cout << "insert:" << obj.insert(-1);
	cout << "remove:" << obj.remove(-3);
	cout << "insert:" << obj.insert(1);
	cout << "insert:" << obj.insert(-2);
	cout << "insert:" << obj.insert(-2);
	cout << "insert:" << obj.insert(-2);
	cout << "insert:" << obj.insert(1);
	cout<< "remove:" << obj.getRandom();
	cout << "insert:" << obj.insert(-2);
	cout << "remove:" << obj.remove(0);
	cout << "insert:" << obj.insert(-3);
	cout << "insert:" << obj.insert(1);

	cin.get();
	return 1;
}