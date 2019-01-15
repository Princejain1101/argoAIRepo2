#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

class codec {
public:
	TreeNode* createTreeHelp(vector<int> &nums, int i) {
		if (i >= nums.size()) {
			return nullptr;
		}
		if (nums[i] == NULL) {
			return nullptr;
		}
		TreeNode* root = new TreeNode(nums[i]);
		root->left = createTreeHelp(nums, 2 * i + 1);
		root->right = createTreeHelp(nums, 2 * i + 2);
		return root;
	}
	TreeNode* createTree(vector<int> &nums) {
		return createTreeHelp(nums, 0);
	}
	void inorder(TreeNode* root) {
		if (root == nullptr) {
			//cout << "NULL" << endl;
			return;
		}
		inorder(root->left);
		cout << root->val << endl;
		inorder(root->right);
	}
	string serialize(TreeNode *root) {
		string data;
		data.append("[");
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int s = q.size();
			while (s > 0) {
				TreeNode* node = q.front();
				q.pop();
				if (node == nullptr) {
					data.append("NULL,");
				}
				else {
					data.append(to_string(node->val));
					data.append(",");
					q.push(node->left);
					q.push(node->right);
				}
				s--;
			}
		}
		if (data[data.size() - 1] == ',') {
			data.erase(data.end() - 1);
		}
		while (data.size() > 5 && data.substr(data.size() - 5, 5) == ",NULL") {
			data.erase(data.end() - 5, data.end());
		}
		data.append("]");
		return data;
	}
	TreeNode* deserialize(string data) {
		size_t found = data.find(',', 0);
		string val;
		if (found == string::npos) {
			val = data.substr(1, data.size()-2);
		}
		else {
			val = data.substr(1, found-1);
		}
		if (val == "NULL" || val == "") {
			return nullptr;
		}
		TreeNode* root = new TreeNode(stoi(val));
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int s = q.size();
			while (s > 0) {
				TreeNode* node = q.front();
				q.pop();
				// assign left
				if (found == string::npos) {
					return root;
				}
				int start = found+1;
				found = data.find(',', start);
				if (found == string::npos) {
					val = data.substr(start, data.size() - 1 - start);
				}
				else {
					val = data.substr(start, found - start);
				}
				if (val != "NULL") {
					TreeNode* left = new TreeNode(stoi(val));
					node->left = left;
					q.push(left);
				}
				// assign right
				if (found == string::npos) {
					return root;
				}
				start = found + 1;
				found = data.find(',', start);
				if (found == string::npos) {
					val = data.substr(start, data.size() - 1 - start);
				}
				else {
					val = data.substr(start, found - start);
				}
				if (val != "NULL") {
					TreeNode* right = new TreeNode(stoi(val));
					node->right = right;
					q.push(right);
				}
				s--;
			}
		}
		return root;
	}
};

int main() {

	codec c;
	vector<int> nums({1,2,3,NULL,NULL,4,5});
	TreeNode* tree = c.createTree(nums);
	string data = c.serialize(tree);
	cout << data << endl;
	tree = c.deserialize(data);
	c.inorder(tree);
	cout << c.serialize(tree) << endl;
	cin.get();
	return 1;
}