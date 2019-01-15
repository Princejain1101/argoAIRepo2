#include <iostream>

using namespace std;

int divide(int divident, int divisor) {
	if (divisor == divident) {
		return 1;
	}
	if (divisor == 1) {
		return divident;
	}
	if (divisor == -1) {
		if (divident == INT_MIN) {
			return INT_MAX;
		}
		else {
			return -divident;
		}
	}
	if (divident == 0) {
		return 0;
	}
	int mul = 1;
	if (divident < 0 && divisor >0) {
		mul = -1;
	}
	if (divident > 0 && divisor < 0) {
		mul = -1;
	}

	int count = 0;

	if (divident > 0) {
		if (divisor > 0) {
			divident -= divisor;
		}
		else {
			divident += divisor;
		}
		while (divident >= 0) {
			count++;
			if (count == INT_MAX) {
				break;
			}
			if (divisor > 0) {
				divident -= divisor;
			}
			else {
				divident += divisor;
			}
		}
	}
	else {
		if (divisor > 0) {
			divident += divisor;
		}
		else {
			divident -= divisor;
		}
		while (divident <= 0) {
			count++;
			if (count == INT_MAX) {
				break;
			}
			if (divisor > 0) {
				divident += divisor;
			}
			else {
				divident -= divisor;
			}
		}
	}
	return mul*count;
}
int main() {
	cout << divide(10,3) << endl;
	//cout << divide(7, -3) << endl;
	//cout << divide(-2147483647, 2) << endl;
	cin.get();
	return 1;
}