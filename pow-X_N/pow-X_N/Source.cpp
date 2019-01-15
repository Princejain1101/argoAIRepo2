#include <iostream>
#include <vector>
using namespace std;

double myPow(double x, int n) {
	if (x == 1) {
		return 1;
	}
	if (x == -1) {
		return 1 - 2*(n % 2);
	}
	double ret = 1;
	if (n >= 0) {
		for (int i = 0; i < n; i++) {
			ret = ret*x;
			if (ret == 0) {
				return 0;
			}
		}
	}
	else {
		for (int i = n; i < 0; i++) {
			ret = ret / x;
			if (ret == 0) {
				return 0;
			}
		}
	}

	return ret;
}

int main() {
	//cout << myPow(2, 10) << endl;
	//cout << myPow(2.1, 3) << endl;
	//cout << myPow(2,-2) << endl;
	//cout << myPow(2, -2147483648) << endl;
	cout << myPow(-1, 2147483647) << endl;
	cin.get();
	return 1;
}