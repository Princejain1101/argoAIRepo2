#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> perm;
	if (nums.size() <= 1) {
		perm.push_back(nums);
		return perm;
	}
	int number = nums[0];
	vector<int> numsSub(nums.begin()+1,nums.end());
	
	vector<vector<int>> permSub = permute(numsSub);

	for (auto p : permSub) {
		for (int it = 0; it < p.size(); it++) {
			vector<int> pp(p.begin(), p.end());
			pp.insert(pp.begin()+it, number);
			perm.push_back(pp);
		}
		vector<int> pp(p.begin(), p.end());
		pp.push_back(number);
		perm.push_back(pp);
	}
	return perm;
}

int main() {

	vector<int> nums({});

	vector<vector<int>> perm = permute(nums);
	for (auto row : perm) {
		for (auto c : row) {
			cout << c << "\t";
		}
		cout << endl;
	}

	cin.get();
	return 1;
}