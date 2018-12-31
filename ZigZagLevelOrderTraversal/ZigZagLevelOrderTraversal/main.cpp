#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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

void printVector(vector<int> &nums) {
	for (auto &i : nums) {
		cout << i << "\t";
	}
	cout << endl;
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> zigzag;
	int level = 0;
	stack<TreeNode*> fifo;
	fifo.push(root);
	while (!fifo.empty()) {
		vector<int> zig;
		int count = fifo.size();
		stack<TreeNode*> buffer;
		while (count > 0) {
			TreeNode* node = fifo.top();
			fifo.pop();
			if (node == nullptr) // taking care of the empty tree;
				return zigzag;
			zig.push_back(node->val);
			if (level % 2 == 0) {
				if (node->left != nullptr) buffer.push(node->left);
				if (node->right != nullptr) buffer.push(node->right);
			}
			else {
				if (node->right != nullptr) buffer.push(node->right);
				if(node->left != nullptr) buffer.push(node->left);
			}
			count--;
		}
		fifo = buffer;
		zigzag.push_back(zig);
		level++;
	}
	return zigzag;
}

int main() {

	vector<int> nums({ 2,3,NULL,1 });
	vector<int> nums2({ 3,1,2 });
	vector<int> nums3({ 3,9,20,NULL,NULL,15,7 });
	TreeNode *tree = createTree(nums3);
	printTree(tree);
	vector<vector<int>> zigzag = zigzagLevelOrder(tree);
	for (auto &zig : zigzag) {
		printVector(zig);
	}
	cin.get();
	return 1;
}