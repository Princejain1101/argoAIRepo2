#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool boundary(vector<vector<char>> &board, int i, int j) {
	if (i < 0 || j < 0) {
		return false;
	}
	if (i >= board.size()) {
		return false;
	}
	if (j >= board[0].size()) {
		return false;
	}
	return true;
}

bool existHelp(vector<vector<char>> &board, int i, int j, string word, vector<vector<bool>> &visited) {
	if (word.length() == 0) {
		return true;
	}
	if (!boundary(board, i, j)) {
		return false;
	}
	if (visited[i][j] == true)
		return false;

	//cout<<word<<endl;
	if (board[i][j] != word[0])
		return false;
	visited[i][j] = true;
	string wordSub(word.begin() + 1, word.end());
	bool up = existHelp(board, i + 1, j, wordSub, visited);
	bool down = existHelp(board, i - 1, j, wordSub, visited);
	bool right = existHelp(board, i, j + 1, wordSub, visited);
	bool left = existHelp(board, i, j - 1, wordSub, visited);
	if (up || down || left || right) {
		return true;
	}
	else {
		visited[i][j] = false;
		return false;
	}
	
}
bool exist(vector<vector<char>>& board, string word) {
	if (board.size() <= 0)
		return false;
	vector<vector<bool>> visited;
	for(int i = 0; i < board.size(); i++) {
		vector<bool> r(board[0].size(), false);
		visited.push_back(r);
	}
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			bool ret = existHelp(board, i, j, word, visited);
			if (ret == true) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	//vector<vector<char>> board({{'A','B','C','E'},
	//							{'S','F','C','S'},
	//							{'A','D','E','E'}});
	//string word("ABCCED");
	//cout << exist(board, word) << endl;
	//string word2("SEE");
	//cout << exist(board, word2) <<endl;
	//string word3("ABCB");
	//cout << exist(board, word3) <<endl;
	vector<vector<char>> board4({{ 'a','b'}});
	string word4("ba");
	cout << exist(board4, word4) << endl;

	cin.get();
	return 1;
}