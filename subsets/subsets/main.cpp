#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
	
	vector<vector<int>> sets;
	if(nums.size() <=0){
		vector<int> null;
		sets.push_back(null);
		return sets;
	}
	int number = nums[0];
	vector<int> numsSub(nums.begin() + 1, nums.end());

	vector<vector<int>> setsSub = subsets(numsSub);

	vector<vector<int>> setsNew(setsSub.begin(), setsSub.end());
	for(auto s : setsSub) {
		s.push_back(number);
		setsNew.push_back(s);
	}
	return setsNew;
}

int main() {
	vector<int> nums({1,2,3});
	vector<vector<int>> numsVec = subsets(nums);

	for (auto &row : numsVec) {
		for (auto &c : row) {
			cout << c << "\t";
		}
		cout << endl;
	}
	cin.get();
	return 1;
}