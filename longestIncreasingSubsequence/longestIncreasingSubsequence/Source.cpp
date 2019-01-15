#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
	if (nums.size() <= 0) {
		return 0;
	}
	vector<int> length(nums.size(),1);
	int maximum = 1;
	for (int i = 1; i < nums.size(); i++) {
		int len = 1;
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j] && length[j] >= len) {
				len = length[j];
				length[i] = len + 1;
			}
		}
		maximum = max(maximum, length[i]);
	}
	return maximum;
}

int main() {

	vector<int> nums({10,9,2,5,3,7,101,18});
	vector<int> nums2({ 1,3,6,7,9,4,10,5,6 });
	cout << lengthOfLIS(nums2);
	cin.get();
	return 1;
}