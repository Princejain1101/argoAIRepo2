#include <iostream>
#include <string>
#include <vector>

using namespace std;


int lengthOfLongestSubstring(string s) {
	int len = 0;
	int lenT = 0;
	string subs;
	int iter = 0;
	while (iter < s.length()) {
		size_t found = subs.find(s[iter]);
		if (found == string::npos) {
			subs.append(s,iter,1);
			lenT++;
		}
		else {
			if (lenT > len) {
				len = lenT;
			}
			subs.erase(0,found+1);
			subs.append(s, iter, 1);
			lenT = subs.length();
			//cout << subs << endl;
		}
		iter++;
	}
	if (lenT > len) {
		len = lenT;
	}
	//cout << subs << endl;
	return len;
}

int main() {
	string s("abcabcbb");
	cout<<lengthOfLongestSubstring(s)<<endl;
	cin.get();
	return 1;
}