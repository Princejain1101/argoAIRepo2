#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode* next;
	TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr),  next(nullptr) {}
};

TreeLinkNode *createTree(vector<int> &nums) {
	int index = 0;
	int count = nums.size();
	if (count == 0) {
		return nullptr;
	}
	//cout << "count:" << count << endl;
	TreeLinkNode* root = new TreeLinkNode(nums[0]);
	queue<TreeLinkNode*> q;
	q.push(root);

	index++;
	while (index < count) {
		int qsize = q.size();
		while (qsize > 0) {
			TreeLinkNode* node = q.front();
			q.pop();
			int left = nums[index++];
			if (left != NULL) {
				node->left = new TreeLinkNode(left);
				q.push(node->left);
			}
			if (index >= count)
				break;
			int right = nums[index++];
			if (right != NULL) {
				node->right = new TreeLinkNode(right);
				q.push(node->right);
			}
			qsize--;
		}
	}
	return root;
}

// print in BFS fashion. move to next line for every new level.
// queue is filled with nullptr to move to next level.
void printTree(TreeLinkNode* root) {
	queue<TreeLinkNode*> q;
	q.push(root);
	while (!q.empty()) {
		int count = q.size();
		while (count > 0) {
			TreeLinkNode* node = q.front();
			q.pop();

			cout << node->val << "\t";
			if (node->left != nullptr) q.push(node->left);
			if (node->right != nullptr) q.push(node->right);
			count--;
		}
		cout << endl;
	}
	cout << endl;
}

void printTreeLink(TreeLinkNode* root) {
	queue<TreeLinkNode*> q;
	q.push(root);
	while (!q.empty()) {
		int count = q.size();
		while (count > 0) {
			TreeLinkNode* node = q.front();
			q.pop();

			cout << node->val << ":";
			if (node->next != nullptr) cout << node->next->val << "\t";
			if (node->left != nullptr) q.push(node->left);
			if (node->right != nullptr) q.push(node->right);
			count--;
		}
		cout << endl;
	}
	cout << endl;
}

void printVector(vector<int> &nums) {
	for (auto &i : nums) {
		cout << i << "\t";
	}
	cout << endl;
}
// using level order traversal
void connect(TreeLinkNode *root) {
	queue<TreeLinkNode*> q;
	q.push(root);

	while (!q.empty()) {
		int count = q.size();
		TreeLinkNode* nodeNext = nullptr;
		while (count > 0) {
			TreeLinkNode* node = q.front();
			q.pop();
			if (nodeNext != nullptr) {
				nodeNext->next = node;
			}
			if (node != nullptr) {
				nodeNext = node;
				q.push(node->left);
				q.push(node->right);
			}
			count--;
		}
	}
}
// using pre-order traversal
void connectRec(TreeLinkNode* root) {
	if (root == nullptr)
		return;
	TreeLinkNode* left = root->left;
	TreeLinkNode* right = root->right;
	if(left != nullptr) left->next = right;
	if (root->next != nullptr && right != nullptr) {
		right->next = root->next->left;
	}
	connectRec(root->left);
	connectRec(root->right);
}
int main() {

	vector<int> nums({ 2,3,NULL,1 });
	vector<int> nums2({ 3,1,2 });
	vector<int> nums3({ 1,2,3,4,5,6,7 });
	TreeLinkNode *tree = createTree(nums3);
	printTree(tree);

	connect(tree);
	printTreeLink(tree);

	tree = createTree(nums3);
	printTree(tree);

	connectRec(tree);
	printTreeLink(tree);

	cin.get();
	return 1;
}