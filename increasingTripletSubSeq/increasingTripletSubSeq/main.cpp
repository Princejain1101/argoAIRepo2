#include <iostream>
#include <vector>

using namespace std;

bool increasingTriplet(vector<int>& nums) {
	int i, j, k;
	int s = nums.size();
	for (i = 0; i < s-2; i++) {
		for (j = i + 1; j < s - 1; j++) {
			for (k = j + 1; k < s; k++) {
				if (nums[i] < nums[j] < nums[k]) {
					return true;
				}
			}
		}
	}
	return false;
}
bool increasingTripletOpt(vector<int>& nums) {
	int i = - ( (-1 << (sizeof(int) * 8 -1)) + 1);
	int j = - ( (-1 << (sizeof(int) * 8 -1)) + 1);

	//cout << i << endl;
	//cout << j << endl;

	//cout << sizeof(int) << endl;
	int k;
	int s = nums.size();
	if (s < 3) {
		return false;
	}
	for (k = 0; k < s; k++) {
		if (nums[k] <= i) {
			i = nums[k];
		}
		else if (nums[k] <= j) {
			j = nums[k];
		}
		else {
			return true;
		}
	}
	return false;
}

int main() {
	
	vector<int> nums({1,2,3,4,5});
	cout << increasingTripletOpt(nums);
	cin.get();
	return 1;
}