#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
	int pre = -INFINITY;
	int post = -INFINITY;
	int i = 0;
	for (i = 0; i < nums.size(); i++) {
		if (i > 0) {
			pre = nums[i - 1];
		}
		else {
			pre = -INFINITY;
		}
		if (i < nums.size() - 1) {
			post = nums[i + 1];
		}
		else {
			post = -INFINITY;
		}
		if (pre < nums[i] && nums[i] > post) {
			return i;
		}
	}
	return 0;
}

// in O(log(n))
// using binary search
int findPeakElementLogN(vector<int> &nums) {
	int n = nums.size();
	if (n == 1) {
		return 0;
	}
	int first = 0;
	int last = n - 1;
	int mid;
	int pre = -INFINITY;
	int post = -INFINITY;

	while (first < last) {
		mid = (last + first )/ 2;
		if (mid == 0) {
			pre = -INFINITY;
		}
		else {
			pre = nums[mid - 1];
		}
		if (mid == n - 1) {
			post = -INFINITY;
		}
		else {
			post = nums[mid + 1];
		}
		if (pre < nums[mid] && nums[mid] > post) {
			return mid;
		}
		if (pre > nums[mid]) {
			last = mid -1;
		}
		else {
			first = mid + 1;
		}
	}
	return first;
}

int findPeakElementLogNRecHelp(vector<int> &nums, int first, int last) {
	if (first == last) {
		return first;
	}

	int mid = (last + first) / 2;
	
	int pre = -INFINITY;
	int post = -INFINITY;

	if (mid == 0) {
		pre = -INFINITY;
	}
	else {
		pre = nums[mid-1];
	}
	if (mid == nums.size() - 1) {
		post = -INFINITY;
	}
	else {
		post = nums[mid + 1];
	}
	if (pre < nums[mid] && nums[mid] > post) {
		return mid;
	}
	if (pre > nums[mid]) {
		return findPeakElementLogNRecHelp(nums, first, mid-1);
	}
	return findPeakElementLogNRecHelp(nums, mid + 1, last);
}

int findPeakElementLogNRec(vector<int> &nums) {
	return findPeakElementLogNRecHelp(nums, 0, nums.size() - 1);
}



int main() {

	vector<int> nums({1,2,3,1});
	vector<int> nums2({ 1,2,1,3,5,6,4 });
	vector<int> nums3({1,2});
	//cout << findPeakElement(nums)<<endl;
	//cout << findPeakElement(nums2)<<endl;
	//cout << findPeakElementLogN(nums3) << endl;
	//cout << findPeakElementLogN(nums2) << endl;

	//cout << findPeakElementLogNRec(nums3) << endl;
	cout << findPeakElementLogNRec(nums2) << endl;

	cin.get();
	return 1;
}