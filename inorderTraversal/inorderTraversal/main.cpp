#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

TreeNode *createTree(vector<int> &nums) {
	int index = 0;
	int count = nums.size();
	if (count == 0) {
		return nullptr;
	}
	//cout << "count:" << count << endl;
	TreeNode* root = new TreeNode(nums[0]);
	queue<TreeNode*> q;
	q.push(root);

	index++;
	while (index < count) {
		int qsize = q.size();
		while (qsize > 0) {
			TreeNode* node = q.front();
			q.pop();
			int left = nums[index++];
			if (left != NULL) {
				node->left = new TreeNode(left);
				q.push(node->left);
			}
			if (index >= count)
				break;
			int right = nums[index++];
			if (right != NULL) {
				node->right = new TreeNode(right);
				q.push(node->right);
			}
			qsize--;
		}
	}
	return root;
}

// print in BFS fashion. move to next line for every new level.
// queue is filled with nullptr to move to next level.
void printTree(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		int count = q.size();
		while (count > 0) {
			TreeNode* node = q.front();
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

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> inorder;
	stack<TreeNode*> fifo;
	TreeNode *node = root;
	if (root == nullptr) {
		return inorder;
	}
	fifo.push(root);
	while (!fifo.empty()) {
		while (node->left != nullptr) {
			fifo.push(node->left);
			node = node->left;
		}
		TreeNode *top = fifo.top();
		inorder.push_back(top->val);
		fifo.pop();
		if (top->right != nullptr) {
			node = top->right;
			fifo.push(node);
		}
	}
	return inorder;
}
void printVector(vector<int> &nums) {
	for (auto &i : nums) {
		cout << i << "\t";
	}
	cout << endl;
}
int main() {

	vector<int> nums({2,3,NULL,1});
	vector<int> nums2({ 3,1,2 });
	TreeNode *tree = createTree(nums2);
	printTree(tree);
	vector<int> inorder = inorderTraversal(tree);
	printVector(inorder);
	cin.get();
	return 1;
}