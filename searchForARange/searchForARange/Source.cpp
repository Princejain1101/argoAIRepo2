#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
	int first = 0;
	int last = nums.size() - 1;
	int mid = (first + last) / 2;
	int low = -1;
	int high = -1;

	if (nums.size() == 0) {
		return vector<int>({ low, high });
	}
	while (first <= last) {
		mid = (first + last) / 2;
		if (nums[mid] == target) {
			break;
		}
		if (nums[mid] > target) {
			last = mid - 1;
		}
		if (nums[mid] < target) {
			first = mid + 1;
		}
	}

	if (nums[mid] != target) {
		return vector<int>({low, high});
	}
	int lowfirst = first;
	int lowlast = mid;
	int lowmid;
	while (lowfirst < lowlast) {
		lowmid = (lowfirst + lowlast) / 2;
		if (nums[lowmid] == target) {
			if (lowmid == 0) {
				lowlast = 0;
				break;
			}
			else {
				if (nums[lowmid - 1] == target) {
					lowlast = lowmid - 1;
				}
				else {
					lowlast = lowmid;
					break;
				}
			}
		}
		else {
			lowfirst = lowmid + 1;
		}
	}
	low = lowlast;

	int highfirst = mid;
	int highlast = last;
	int highmid;
	while (highfirst < highlast) {
		highmid = (highfirst + highlast) / 2;
		if (nums[highmid] == target) {
			if (highmid == nums.size() - 1) {
				highfirst = highmid;
				break;
			}
			else {
				if (nums[highmid + 1] == target) {
					highfirst = highmid + 1;
				}
				else {
					highfirst = highmid;
					break;
				}
			}
		}
		else {
			highlast = highmid - 1;
		}
	}
	high = highfirst;

	return vector<int>({low, high});
}

int main() {

	vector<int> nums({5,7,7,8,8,10});
	vector<int> nums2({});
	vector<int> nums3({1,4});

	vector<int> range = searchRange(nums3, 4);
	for (auto &i : range) {
		cout << i << "\t";
	}
	cout << endl;
	cin.get();
	return 1;
}