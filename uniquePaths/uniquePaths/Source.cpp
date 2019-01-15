#include <iostream>
#include <vector>

using namespace std;

int uniquePathsHelp(int m, int n, int i, int j, vector<vector<int>> &count) {
	if (i == m - 1 && j == n - 1) {
		return 1;
	}
	if (i >= m || j >= n)
		return 0;
	if (count[i][j] == 0) {
		count[i][j] = uniquePathsHelp(m, n, i + 1, j, count) + uniquePathsHelp(m, n, i, j + 1, count);
	}
	
	return count[i][j];
}

int uniquePaths(int m, int n) {
	vector<vector<int>> count;
	for (int i = 0; i < m; i++) {
		vector<int> row(n,0);
		count.push_back(row);
	}
	return uniquePathsHelp(m, n, 0, 0, count);
}

int main() {

	cout << uniquePaths(23,12) << endl;

	cin.get();
	return 1;
}