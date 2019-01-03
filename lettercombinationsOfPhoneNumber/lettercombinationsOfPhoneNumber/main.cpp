#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> letterCombinations(string digits) {
	//cout << digits << endl;
	static const unordered_map<int, string> numbermapping({ {2,"abc"},
															{3,"def"},
															{4,"ghi"},
															{5,"jkl"},
															{6,"mno"},
															{7,"pqrs"},
															{8,"tuv"},
															{9,"wxyz"} });
	if (digits.length() == 0) {
		vector<string> comb;
		return comb;
	}
	string restDigits(digits, 1, digits.length() - 1);
	vector<string> restComb = letterCombinations(restDigits);

	int number = digits[0] - '0';
	string chars;
	auto it = numbermapping.find(number);
	if (it != numbermapping.end()) {
		chars = it->second;
	}
	vector<string> comb;
	if (restComb.empty()) {
		restComb.push_back("");
	}
	for (auto &c : chars) {
		for (auto s : restComb) {
			s.insert(s.begin(),c);
			comb.push_back(s);
			//cout << s << "\t";
		}
		//cout << endl;
	}
	
	return comb;
}

int main() {
	vector<string> vec = letterCombinations("");
	for (auto &s : vec) {
		cout << s << "\t";
	}
	cin.get();
	return 1;
}