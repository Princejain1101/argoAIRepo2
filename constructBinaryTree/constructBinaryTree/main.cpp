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
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size()) {
		return nullptr;
	}
	TreeNode *root = new TreeNode(preorder[0]);
	int p, i;
	p = 0;
	i = 0;
	while (preorder[p] != inorder[i]) {
		i++;
	}
	vector<int> leftinorder(inorder.begin(),inorder.begin()+i);
	vector<int> leftpreorder(preorder.begin() + 1, preorder.begin() + i + 1);

	vector<int> rightinorder(inorder.begin() + i + 1, inorder.end());
	vector<int> rightpreorder(preorder.begin() + i + 1, preorder.end());

	root->left = buildTree(leftpreorder, leftinorder);
	root->right = buildTree(rightpreorder, rightinorder);

	return root;
}
int main() {

	//vector<int> nums({ 2,3,NULL,1 });
	//vector<int> nums2({ 3,1,2 });
	//TreeNode *tree = createTree(nums2);
	//printTree(tree);
	
	vector<int> preorder({3,9,20,15,7});
	vector<int> inorder({9,3,15,20,7});
	TreeNode* tree = buildTree(preorder, inorder);
	printTree(tree);

	cin.get();
	return 1;
}