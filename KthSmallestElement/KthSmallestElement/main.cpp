#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define null -100000

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
			if (index >= count)
				break;
			int left = nums[index++];
			if (left != null) {
				node->left = new TreeNode(left);
				q.push(node->left);
			}
			if (index >= count)
				break;
			int right = nums[index++];
			if (right != null) {
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

struct TrueValue {
	bool truth;
	int value;
};
TrueValue kthSmallestHelp(TreeNode* root, int k, int &m) {
	if (root == nullptr || k < 1) {
		m = 0;
		TrueValue t;
		t.truth = false;
		return t;
	}
	int mleft;
	TrueValue kleft = kthSmallestHelp(root->left, k, mleft);
	if (kleft.truth == true) {
		return kleft;
	}
	else {
		m = mleft;
	}
	if (k == mleft + 1) {
		TrueValue t;
		t.truth = true;
		t.value = root->val;
		return t;
	}
	else {
		m += 1;
	}
	int mright;
	TrueValue kright = kthSmallestHelp(root->right, k - m, mright);
	if (kright.truth == true) {
		return kright;
	}
	else {
		m += mright;
	}
	TrueValue t;
	t.truth = false;
	return t;
}

int kthSmallest(TreeNode* root, int k) {
	int m = 0;
	TrueValue t = kthSmallestHelp(root, k, m);
	return t.value;
}


int main() {

	vector<int> nums({ 3,1,4,null,2 });
	vector<int> nums2({ 5,3,6,2,4,null,null,1 });
	vector<int> nums3 ({31, 30, 48, 3, null, 38, 49, 0, 16, 35,
						47, null, null, null, 2, 15, 27, 33, 37, 
						39, null, 1, null, 5, null, 22, 28, 32, 34, 
						36, null, null, 43, null, null, 4, 11, 19, 23, 
						null, 29, null, null, null, null, null, null, 40, 46, 
						null, null, 7, 14, 17, 21, null, 26, null, null, 
						null, 41, 44, null, 6, 10, 13, null, null, 18, 20, 
						null, 25, null, null, 42, null, 45, null, null, 8, 
						null, 12, null, null, null, null, null, 24, null, 
						null, null, null, null, null, 9});
	vector<int> nums4({1,null,2});

	TreeNode *tree = createTree(nums4);
	printTree(tree);
	int kthsmallest = kthSmallest(tree, 2);
	cout << kthsmallest << endl;
	cin.get();
	return 1;
}