#include <iostream>
#include <vector>

using namespace std;

bool canJumpHelp(vector<int> &nums, int i, vector<bool> &visited) {
	if (i == nums.size() - 1) {
		return true;
	}
	int k = nums[i];
	if (k >= nums.size() - 1 - i)
		return true;
	visited[i] = true;
	bool can = false;
	for (int j = 0; j < k; j++) {

		if (visited[i+j+1] == true) {
			continue;
		}
		can = can || canJumpHelp(nums, i+j+1, visited);
		if (can == true) {
			return true;
		}
	}
	return can;
}

bool canJump(vector<int> &nums) {
	if (nums.size() == 0) {
		return true;
	}
	vector<bool> visited(nums.size(), false);
	return canJumpHelp(nums, 0, visited);
}

int main() {
	vector<int> nums({2,3,1,1,4});
	vector<int> nums2({ 3,2,1,0,4 });

	cout<<canJump(nums2)<<endl;

	cin.get();
	return 1;
}