#include <iostream>
#include <vector>
#include <string>


using namespace std;

void generateParenthesisHelp(int n, int p, int k, vector<string> &parenthesis, string s) {
	if (p < 0) {
		return;
	}
	if (p == k && k == n) {
		//cout << s << endl;
		if (s.length() > 0) {
			parenthesis.push_back(s);
		}
		return;
	}
	if (p < n) {
		string sf = s;
		sf.append("(");
		generateParenthesisHelp(n, p + 1, k, parenthesis, sf);
	}
	if (k < p ) {
		string sb = s;
		sb.append(")");
		generateParenthesisHelp(n, p, k+1, parenthesis, sb);
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> parenthesis;
	string s;
	generateParenthesisHelp(n, 0, 0, parenthesis, s);
	return parenthesis;
}


int main() {
	vector<string> vec = generateParenthesis(3);
	for (auto &s: vec) {
		cout << s << endl;
	}

	cin.get();
	return 1;
}