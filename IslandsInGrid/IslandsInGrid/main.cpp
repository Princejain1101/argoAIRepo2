#include <iostream>
#include <vector>

using namespace std;

void printVecVector(vector<vector<char>> &grid) {
	for (auto &i : grid) {
		for (auto &j : i) {
			cout << j << "\t";
		}
		cout<<endl;
	}
	cout << endl;
}

void numIslandsHelp(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &visited) {
	if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
		return;
	}
	if (visited[i][j] == true || grid[i][j] == '0') {
		return;
	}
	visited[i][j] = true;
	numIslandsHelp(grid, i, j + 1, visited);
	numIslandsHelp(grid, i + 1, j, visited);
	numIslandsHelp(grid, i, j - 1, visited);
	numIslandsHelp(grid, i - 1, j, visited);
	return;
}

int numIslands(vector<vector<char>>& grid) {
	vector<vector<bool>> visited;
	for (int i = 0; i < grid.size(); i++) {
		vector<bool> row(grid[0].size(), false);
		visited.push_back(row);
	}
	int count = 0;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (visited[i][j] == false && grid[i][j] == '1') {
				numIslandsHelp(grid, i, j, visited);
				count++;
			}
		}
	}
	return count;
}

int main() {
	vector<vector<char>> grid({ {'1','1','0','0','0'},
								{'1','1','0','0','0'},
								{'0','0','1','0','0'},
								{'0','0','0','1','1'}});
	cout << numIslands(grid);
	cin.get();
	return 1;
}