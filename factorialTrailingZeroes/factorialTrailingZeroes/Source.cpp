#include <iostream>
#include <vector>

using namespace std;
int trailingZeroes(int n) {
	int count = 0;
	// i%5 is checked to save i from overflowing.
	for (int i = 5;  i <= n && i%5==0; i = i * 5) {
		cout << count << "n:" << n << ",i:" << i << "n/i:" << n / i << endl;
		count += n / i;
	}
	return count;
}
int main() {
	cout << trailingZeroes(1808548329) << endl;
	cin.get();
	return 1;
}