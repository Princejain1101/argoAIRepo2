#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coinChangeHelp(vector<int>& coins, int amount, int total) {
	if (amount == 0) {
		return total;
	}
	if (amount < 0) {
		return -1;
	}
	int count = 100000;
	for (int index = 0; index < coins.size(); index++) {
		int countL = coinChangeHelp(coins, amount - coins[index], total + 1);
		if (countL >= 0) {
			count = min(count, countL);
		}
	}
	if (count == 100000)
		return -1;
	return count;
}

int coinChange(vector<int> &coins, int amount) {
	return coinChangeHelp(coins, amount, 0);
}

void coinChangeDPHelp(vector<int>&coins, int amount, vector<int> &counts) {
	int count = 100000;
	for (int i = 0; i < coins.size(); i++) {
		int amountL = amount - coins[i];
		if (amountL < 0) {
			continue;
		}
		int countL = -1;
		if (counts[amountL] < 0) {
			coinChangeDPHelp(coins, amount - coins[i], counts);
		}
		countL = counts[amountL];

		if (countL >= 0) {
			count = min(countL, count);
		}
	}
	if (count != 100000) {
		counts[amount] = count + 1;
	}
}
int coinChangeDP(vector<int> &coins, int amount) {
	vector<int> counts(amount+1,-1);
	//vector<bool> visited(amount + 1, false);
	//visited[0] = true;
	counts[0] = 0;
	coinChangeDPHelp(coins, amount, counts);// , visited);
	return counts[amount];
}

int coinChangeDP2(vector<int> &coins, int amount) {
	vector<int> counts(amount + 1, -1);
	counts[0] = 0;
	for (int a = 0; a < amount + 1; a++) {
		int minCount = 100000;
		for (int c = 0; c < coins.size(); c++) {
			int amountL = a - coins[c];
			if (amountL < 0) {
				continue;
			}
			if (counts[amountL] < 0) {
				continue;
			}
			minCount = min(minCount, counts[amountL]);
		}
		if(minCount != 100000)
			counts[a] = minCount + 1;
	}
	return counts[amount];
}
int main() {

	vector<int> coins({186,419,83,408});
	vector<int> coins2({ 1,2,5 });
	cout << coinChangeDP2(coins2, 11)<<endl;
	cout << coinChangeDP2(coins, 6249) << endl;
	cin.get();
	return 1;
}