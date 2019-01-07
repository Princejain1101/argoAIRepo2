#include <iostream>
#include <vector>

using namespace std;


bool searchMatrixHelp(vector<vector<int>> &matrix, int target, int i, int j) {
	
	while (j>=0) {
		if (matrix[i][j] == target) {
			return true;
		}
		if (matrix[i][j] < target) {
			break;
		}
		j--;
	}
	if (j < 0)
		return false;
	while (i<matrix.size()) {
		if (matrix[i][j] == target) {
			return true;
		}
		if (matrix[i][j] > target) {
			break;
		}
		i++;
	}
	if (i >= matrix.size())
		return false;
	return searchMatrixHelp(matrix, target, i, j);
}

bool searchMatrix(vector<vector<int>> & matrix, int target) {
	if (matrix.size() == 0) {
		return false;
	}
	return searchMatrixHelp(matrix, target, 0, matrix[0].size()-1);
}

int main() {

	vector<vector<int>> matrix({ 
	{1, 4,  7,	11, 15},
	{2, 5,  8,	12, 19},
	{3,	6,	9,	16,	22},
	{10, 13, 14, 17, 24},
	{18, 21, 23, 26, 30}
	});

	cout << searchMatrix(matrix, 20)<<endl;

	cin.get();
	return 1;
}