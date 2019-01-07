#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int> &nums, int target, int first, int last) {
	if (first > last) {
		return -1;
	}
	int mid = (first + last) / 2;
	if (nums[mid] == target) {
		return mid;
	}
	else {
		if (nums[mid] > target) {
			return BinarySearch(nums, target, first, mid - 1);
		}
		else {
			return BinarySearch(nums, target, mid + 1, last);
		}
	}
}
int searchHelp(vector<int> &nums, int target, int first, int last) {

	if (first > last) {
		return -1;
	}

	int mid = (first + last) / 2;

	if (nums[mid] == target) {
		return mid;
	}
	if (nums[mid] >= nums[first]) {
		if (nums[first] <= target && target < nums[mid]) {
			return BinarySearch(nums, target, first, mid - 1);
		}
		return searchHelp(nums, target, mid + 1, last);
	}
	else {
		if (nums[mid] < target && target <= nums[last]) {
			return BinarySearch(nums, target, mid + 1, last);
		}
		return searchHelp(nums, target, first, mid-1);
	}
}

int search(vector<int>& nums, int target) {

	return searchHelp(nums, target, 0, nums.size()-1);

}

int main() {

	vector<int> nums({4,5,6,7,0,1,2});
	vector<int> nums2({3,1});
	cout << search(nums2, 1) << endl;
	cin.get();
	return 1;
}