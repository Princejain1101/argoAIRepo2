#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
	set<vector<int>> triplets;

	for (int m = 0; m < nums.size(); m++) {
		for (int n = m+1; n < nums.size(); n++) {
			for (int p = n+1; p < nums.size(); p++) {
				if (nums[m] + nums[n] + nums[p] == 0) {
					multiset<int> s{ nums[m],nums[n], nums[p] };
					vector<int> sv(s.begin(), s.end());
					triplets.insert(sv);
				}
			}
		}
	}
	vector<vector<int>> vec(triplets.begin(), triplets.end());
	return vec;
}

vector<vector<int>> threeSumopt(vector<int>& nums) {
	set<vector<int>> triplets;
	set<int> comp;
	// sort the vector
	sort(nums.begin(), nums.end());

	for (int m = 0; m < nums.size(); m++) {
		if (comp.find(nums[m]) != comp.end()) {
			continue;
		}
		comp.insert(nums[m]);
		int n = m + 1;
		int p = nums.size() - 1;
		while (n < p) {
			if (nums[n] + nums[p] + nums[m] == 0) {
				multiset<int> s{ nums[m],nums[n], nums[p] };
				vector<int> sv(s.begin(), s.end());
				triplets.insert(sv);
				n++;
			}
			else if (nums[n] + nums[p] + nums[m] > 0) {
				p--;
			}
			else if (nums[n] + nums[p] + nums[m] < 0) {
				n++;
			}
		}
	}
	vector<vector<int>> vec(triplets.begin(), triplets.end());
	return vec;
}

void printVecofVec(vector<vector<int>> &vec) {
	for (auto &m : vec) {
		for (auto &n : m) {
			cout << n << " ";
		}
		cout << endl;
	}
}
int main() {
	//vector<int> nums{-1, 0, 1, 2, -1, -4};
	vector<int> nums(100, 0);
	printVecofVec(threeSum(nums));
	cout << endl;
	printVecofVec(threeSumopt(nums));
	cin.get();
	return 1;
}