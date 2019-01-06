#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <set>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> countMap;
	for (auto &i : nums) {
		if (countMap.find(i) == countMap.end()) {
			countMap[i] = 1;
		}
		else {
			countMap[i]++;
		}
	}
	//cout << "countMap" << endl;
	//for (auto &i : countMap) {
	//	cout << i.first << " " << i.second << endl;
	//}
	typedef function<bool(pair<int, int>, pair<int, int>)> comparator;
	comparator compFunc = [](pair<int, int> p1, pair<int, int> p2) {return p1.second > p2.second; };
	multiset<pair<int, int>, comparator> vec(countMap.begin(), countMap.end(), compFunc);

	//cout << "set" << endl;
	//for (auto &i : vec) {
	//	cout << i.first << " " << i.second << endl;
	//}
	vector<int> ret;
	int i = 0;
	for(auto &t: vec) {
		ret.push_back(t.first);
		k--;
		i++;
		if (k == 0) {
			break;
		}
	}
	return ret;
}

int main() {

	vector<int> nums({1,2});
	vector<int> topK = topKFrequent(nums, 2);
	for (auto &i : topK) {
		cout << i << "\t";
	}
	cout << endl;
	cin.get();
	return 1;
}