#include <iostream>

int mySqrt(int x) {
	if (x == 1 || x==0) {
		return x;
	}
	int i = 1;
	for (i = 1; i < x / 2; i++) {
		if (i*i == x) {
			return i;
		}
		if ((i + 1)*(i + 1) <= i*i) {
			return i;
		}
		if ((i + 1)*(i + 1) > x) {
			return i;
		}
	}
	return i;
}
int main() {
	std::cout << mySqrt(2147483647) << std::endl;
	std::cin.get();
	return 1;
}