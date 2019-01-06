#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& nums, int i, int j) {
	int k = nums[i];
	nums[i] = nums[j];
	nums[j] = k;
}
void sortColors(vector<int>& nums) {
	if (nums.size() < 2) {
		return;
	}
	int i = 0;
	int j = nums.size() - 1;

	int k = i;
	while (nums[i] == 0) {
		i++;
	}
	while (nums[j] == 2) {
		j--;
	}
	k = i;
	while (k <= j) {
		if (nums[k] == 0 && k>i) {
			swap(nums, i, k);
			i++;
			continue;
		}
		if (nums[k] == 2) {
			swap(nums, j, k);
			j--;
			continue;
		}
		k++;
	}
}

int main() {
	vector<int> nums({1,0});
	sortColors(nums);

	for (auto &i : nums) {
		cout << i << "\t";
	}
	cout << endl;
	cin.get();
	return 1;
}