#include <iostream>
#include <vector>

using namespace std;

int getSum(int a, int b) {
	int size = sizeof(int) * 8;
	unsigned int mask = 0;
	int c = 0;
	int carry = 0;
	for (int i = 0; i < size; i++) {
		if (a >> i == 0 && b >> i == 0 && carry == 0) {
			break;
		}
		mask = 1 << i;
		int aMasked = a & mask;
		int bMasked = b & mask;
		int cMasked = aMasked ^ bMasked ^ carry;
		carry = aMasked & bMasked | aMasked & carry | bMasked & carry;
		carry = carry << 1;
		c = c | cMasked;
	}
	return c;
}

int main() {
	cout << getSum(1,2) << endl;
	cout << getSum(-2, 3) << endl;
	cin.get();
	return 1;
}