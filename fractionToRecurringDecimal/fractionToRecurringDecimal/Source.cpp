#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
string getChars(unsigned int n) {
	if (n == 0) {
		return "0";
	}
	string s;
	while (n > 0) {
		int c = n % 10;
		s.push_back('0' + c);
		n = n / 10;
	}
	return s;
}
string fractionToDecimal(int numerator, int denominator) {
	string s;
	unsigned int numeratorU;
	unsigned int denominatorU;

	if (numerator < 0 && denominator >= 0) {
		if (denominator != 0)
			s.append("-");
		denominatorU = denominator;
		if (numerator == INT_MIN) {
			numeratorU = (-(INT_MIN + 1)) + 1;
		}
		else {
			numerator = -numerator;
			numeratorU = numerator;
		}
	}
	if (numerator >= 0 && denominator < 0) {
		if (numerator != 0)
			s.append("-");
		numeratorU = numerator;
		if (denominator == INT_MIN) {
			denominatorU = (-(denominator + 1)) + 1;
		}
		else {
			denominator = -denominator;
			denominatorU = denominator;
		}
	}
	if (numerator < 0 && denominator < 0) {
		if (denominator == INT_MIN) {
			denominatorU = (-(denominator + 1)) + 1;
		}
		else {
			denominator = -denominator;
			denominatorU = denominator;
		}
		if (numerator == INT_MIN) {
			numeratorU = (-(INT_MIN + 1)) + 1;
		}
		else {
			numerator = -numerator;
			numeratorU = numerator;
		}
	}
	if (numerator >= 0 && denominator >= 0) {
		numeratorU = numerator;
		denominatorU = denominator;
	}
	if (denominatorU == 1) {
		string sub = getChars(numeratorU);
		s.append(sub.rbegin(), sub.rend());
		return s;
	}

	unsigned int n = numeratorU / denominatorU;
	string sub = getChars(n);
	s.append(sub.rbegin(), sub.rend());
	unsigned int remainder = numeratorU%denominatorU;
	if (remainder != 0) {
		s.append(".");
	}
	unsigned int i = 0;
	unordered_map<unsigned int, int> repeat;
	repeat[remainder] = i;
	while (remainder != 0 && i <1000) {
		if ((remainder * 10) / 10 != remainder) {
			n = 10 * (remainder / (double)denominatorU);
			remainder = (int)(((10 * (remainder / (double)denominatorU)) - n)*denominatorU);
		}
		else {
			remainder = remainder * 10;
			n = remainder / denominatorU;
			remainder = remainder%denominatorU;
		}

		string sub = getChars(n);
		s.append(sub.rbegin(), sub.rend());

		if (repeat.find(remainder) != repeat.end()) {
			int j = repeat.find(remainder)->second;
			auto it = s.find('.');
			while (j >= 0) {
				it++;
				j--;
			}
			s.insert(it, "(");
			s.append(")");
			break;
		}
		i++;
		repeat[remainder] = i;
	}
	return s;
}
int main() {

	cout << fractionToDecimal(41, 4) << endl;
	cout << fractionToDecimal(1, 2) << endl;
	cout << fractionToDecimal(2, 1) << endl;
	cout << fractionToDecimal(2, 3) << endl;
	cout << fractionToDecimal(1, 17) << endl;
	cout << fractionToDecimal(1, 2147483647) << endl;

	cin.get();
	return 1;
}