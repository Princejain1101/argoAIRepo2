#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;
int ifOperation(string s) {
	if (s == "+") {
		return 1;
	}
	if (s == "-") {
		return 2;
	}
	if (s == "*") {
		return 3;
	}
	if (s == "/") {
		return 4;
	}
	return 0;
}
int doOperation(int op, int a, int b) {
	switch (op) {
	case 1:
		return a + b;
	case 2:
		return a - b;
	case 3:
		return a*b;
	case 4:
		return a / b;
	default:
		exit(-1);
	}
}
int evalRPN(vector<string>& tokens) {
	stack<int> eval;
	for (auto &i : tokens) {
		int op = ifOperation(i);
		if (op == 0) {
			int x = stoi(i);
			eval.push(x);
		}
		else {
			int b = eval.top();
			eval.pop();
			int a = eval.top();
			eval.pop();
			int res = doOperation(op, a, b);
			eval.push(res);
		}
	}
	return eval.top();
}

int main() {

	vector<string> tokens({ "2", "1", "+", "3", "*" });
	cout << evalRPN(tokens) << endl;
	vector<string> tokens2({ "4", "13", "5", "/", "+" });
	cout << evalRPN(tokens2) << endl;
	vector<string> tokens3({ "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" });
	cout << evalRPN(tokens3) << endl;
	cin.get();
	return 1;
}