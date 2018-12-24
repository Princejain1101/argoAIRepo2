#include <iostream>
#include <vector>
using namespace std;
void printMat(vector<vector<int>> &mat) {
	for (auto &r : mat) {
		for (auto &c : r) {
			cout << c << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void setZero(vector<vector<int>> &mat, int r, int c) {
	for (int ri = 0; ri < mat.size(); ri++) {
		for (int ci = 0; ci < mat.size(); ci++) {
			if (ri == r || ci == c) {
				mat[ri][ci] = 0;
			}
		}
	}
}
void setZeroR(vector<vector<int>> &mat, int r) {
	for (int ci = 0; ci < mat[0].size(); ci++) {
		mat[r][ci] = 0;
	}
}
void setZeroC(vector<vector<int>> &mat, int c) {
	for (int ri = 0; ri < mat.size(); ri++) {
		mat[ri][c] = 0;
	}
}
// extra space mxn
void setZeroes(vector<vector<int>>& mat) {
	vector<vector<int>> matBuf;
	for (auto &r : mat) {
		vector<int> rowBuf(r.begin(), r.end());
		matBuf.push_back(rowBuf);
	}

	for (int ri = 0; ri < mat.size(); ri++) {
		for (int ci = 0; ci < mat[0].size(); ci++) {
			if (matBuf[ri][ci] == 0) {
				setZeroR(mat, ri);
				setZeroC(mat, ci);
			}
		}
	}
}
// extra space m+n
void setZeroesOpt(vector<vector<int>>& mat) {
	vector<int> matBufR(mat.size(), 1);
	vector<int> matBufC(mat[0].size(), 1);
	for (int ri = 0; ri < mat.size(); ri++) {
		for (int ci = 0; ci < mat[0].size(); ci++) {
			if (mat[ri][ci] == 0) {
				matBufR[ri] = 0;
				matBufC[ci] = 0;
			}
		}
	}

	for (int ri = 0; ri < matBufR.size(); ri++) {
		if (matBufR[ri] == 0) {
			setZeroR(mat, ri);
		}
	}

	for (int ci = 0; ci < matBufC.size(); ci++) {
		if (matBufC[ci] == 0) {
			setZeroC(mat, ci);
		}
	}
}
// no extra space
void setZeroesOpt2(vector<vector<int>>& mat) {
	bool col = 1;
	bool row = 1;
	for (int ri = 0; ri < mat.size(); ri++) {
		if (mat[ri][0] == 0) {
			col = 0;
		}
	}
	for (int ci = 0; ci < mat[0].size(); ci++) {
		if (mat[0][ci] == 0) {
			row = 0;
		}
	}
// store row0 and col0 information in the first row and first column.	
	for (int ri = 1; ri < mat.size(); ri++) {
		for (int ci = 1; ci < mat[0].size(); ci++) {
			if (mat[ri][ci] == 0) {
				mat[ri][0] = 0;
				mat[0][ci] = 0;
			}
		}
	}

// set the correspoding rows and cols to 0s except for the first row and first column
	for (int ri = 1; ri < mat.size(); ri++) {
		if (mat[ri][0] == 0) {
			setZeroR(mat, ri);
		}
	}

	for (int ci = 1; ci < mat[0].size(); ci++) {
		if (mat[0][ci] == 0) {
			setZeroC(mat, ci);
		}
	}

// set the first row and col to 0 if 0,0 index is 0 to set the first row and first column to 0
	if (row == 0) {
		setZeroR(mat, 0);
	}
	if (col == 0) {
		setZeroC(mat, 0);
	}
}

int main() {
	//vector<vector<int>> matrix = { {0,1,2,0},
	//							   {3,4,5,2},
	//							   {1,3,1,5} };
	vector<vector<int>> matrix = { {1,1,1},
									{0,1,2} };
	setZeroesOpt2(matrix);
	printMat(matrix);
	cin.get();
	return 1;
}