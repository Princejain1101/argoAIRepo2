#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getnumber(char c) {
	return c - 'A' + 1;
}
int titleToNumber(string s) {

	int col = 0;
	int mul = 1;
	for (int i = s.length() - 1; i >= 0;  i--) {
		col = col + mul*getnumber(s[i]);
		mul = mul * 26;
	}
	return col;
}

int main() {
	cout << titleToNumber("A") << endl;
	cout << titleToNumber("AB") << endl;
	cout << titleToNumber("ZY") << endl;

	cin.get();
	return 1;
}