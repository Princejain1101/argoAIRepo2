#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int getSum(int n) {
	int sum = 0;
	while (n > 0) {
		int sq = n % 10;
		sum += sq*sq;
		n = n / 10;
	}
	return sum;
}


bool isHappy(int n) {
	unordered_set<int> sets;
	sets.insert(n);
	int next = getSum(n);
	while (next != 1)
	{
		//cout << next << endl;
		if (sets.find(next) != sets.end()) {
			return false;
		}
		sets.insert(next);
		next = getSum(next);
	} 
	return true;
}

int main() {

	cout << isHappy(19) << endl;

	cin.get();
	return 1;
}