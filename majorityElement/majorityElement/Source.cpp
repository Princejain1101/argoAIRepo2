#include<iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int>& nums) {
	unordered_map<int, int> count;
	int maxCount = 0;
	int maxElement = nums[0];
	for (auto &i : nums) {
		if (count.find(i) == count.end()) {
			count[i] = 1;
		}
		else {
			count[i] = count[i] + 1;
			if (count[i] > maxCount) {
				maxCount = count[i];
				maxElement = i;
			}
		}
	}
	return  maxElement;
}

int main() {
	vector<int> nums({3,2,3});
	cout << majorityElement(nums) << endl;
	vector<int> nums2({ 2,2,1,1,1,2,2 });
	cout << majorityElement(nums2) << endl;
	cin.get();
	return 1;
}