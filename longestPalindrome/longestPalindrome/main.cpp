#include <iostream>
#include <string>
#include <vector>

using namespace std;
template <class T>
void printMat(vector<vector<T>> &mat) {
	for (auto &r : mat) {
		for (auto &c : r) {
			cout << c << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
string longestPalindromeBin(string s) {
	int len = s.length();
	if (len == 0 || len == 1) {
		return s;
	}
	vector<vector<bool>> costMat;
	for (int i = 0; i < len; i++) {
		vector<bool> row(len, 0);
		costMat.push_back(row);
	}


	// initialize diagnals for single character palindrome
	for (int i = 0; i < len; i++) {
		costMat[i][i] = 1;
	}
	int startI = 0;
	int endI = 0;
	// filling rest of the columns
	for (int j = 1; j < len; j++) {
		// filling only lower half of the matrix. 
		// starting frm j-1, since i=j
		// is already filled above.
		for (int i = j - 1; i >= 0; i--) {
			if (s[i] == s[j] && (costMat[i + 1][j - 1] == 1 || j-i == 1)) {
				costMat[i][j] = 1;
				if (j - i > endI - startI) {
					startI = i;
					endI = j;
				}
			}
			else {
				costMat[i][j] = 0;
			}
		}
	}
	//printMat<bool>(costMat);

	// back-tracking
	string retS;

	//cout << retS << endl;
	retS.append(s, startI, endI - startI + 1);
	//cout << retS << endl;
	return retS;
}
string longestPalindrome(string s) {
	int len = s.length();
	if (len == 0 || len == 1) {
		return s;
	}
	vector<vector<int>> costMat;
	for (int i = 0; i < len; i++) {
		vector<int> row(len, 0);
		costMat.push_back(row);
	}

	vector<vector<int>> riMat;
	for (int i = 0; i < len; i++) {
		vector<int> row(len, -1);
		riMat.push_back(row);
	}
	vector<vector<int>> ciMat;
	for (int i = 0; i < len; i++) {
		vector<int> row(len, -1);
		ciMat.push_back(row);
	}
	// initialize diagnals for single character palindrome
	for (int i = 0; i < len; i++) {
		costMat[i][i] = 1;
		riMat[i][i] = i;
		ciMat[i][i] = i;
		}

	// filling rest of the columns
	for (int j = 1; j < len; j++) {
		// filling only lower half of the matrix. 
		// starting frm j-1, since i=j
		// is already filled above.
		for (int i = j-1; i >= 0; i--) {
			if (s[i] == s[j] && (costMat[i+1][j-1] == 0   || (costMat[i+1][j-1] == ( (j-1) - (i+1) ) + 1) ) ) {
				costMat[i][j] = costMat[i + 1][j - 1] + 2;
				ciMat[i][j] = j - 1;
				riMat[i][j] = i + 1;
			}
			else {
				costMat[i][j] = costMat[i + 1][j - 1];
				ciMat[i][j] = j - 1;
				riMat[i][j] = i + 1;
			}

			if (costMat[i][j] < costMat[i + 1][j]) {
				costMat[i][j] = costMat[i + 1][j];
				riMat[i][j] = i + 1;
				ciMat[i][j] = j;
			}
			if (costMat[i][j] < costMat[i][j - 1]) {
				costMat[i][j] = costMat[i][j - 1];
				riMat[i][j] = i;
				ciMat[i][j] = j - 1;
			}
		}
	}
	//printMat<int>(costMat);
	//printMat<int>(riMat);
	//printMat<int>(ciMat);
	// back-tracking
	string retS;

	int r = 0;
	int c = len - 1;
	int rp = riMat[r][c];
	int cp = ciMat[r][c];
	while (!((costMat[r][c] == 1) || (costMat[rp][cp] == 0))) {

		if (rp == r + 1 && cp == c - 1 && costMat[r][c] - costMat[rp][cp] == 2) {
			//cout << "rp:" << rp << " r:" << r << " cp:" << cp << " c:" << c << endl;
			//cout<< "cost " << costMat[r][c] << " " << costMat[rp][cp] << endl;
			retS.append(s,r,1);
		}
		r = rp;
		c = cp;
		rp = riMat[r][c];
		cp = ciMat[r][c];
	}
	//cout << retS << endl;
	retS.append(s, r, 1);
	//cout << retS << endl;
	int oddEven = 0;
	if (costMat[r][c] == 1) {
		oddEven = 1;
	}
	// copying over left half to right half.
	int retLen = retS.length();
	for (int i = oddEven; i < retLen; i++) {
		retS.append(retS, retLen - 1 - i, 1);
	}
	return retS;
}


// recursive solution with dynamic progamming.
bool checkPalindrome(string &s, int start, int end) {
	int len = s.length();
	int i = start;
	int j = end;
	while (i <= j) {
		if (s[i] == s[j]) {
			i++;
			j--;
		}
		else {
			return false;
		}
	}
	return true;
}
struct se {
	int start, end;
};
se longestPalindromeHelp(string &s, int start, int end, vector<vector<int>> &DP) {
	DP[start][end] = 1;
	//cout<<s.substr(start, end-start+1)<<endl;
	bool check = checkPalindrome(s, start, end);
	if (check) {
		//cout<<"found palindrome"<<endl;
		se sse;
		sse.start = start;
		sse.end = end;
		return sse;
	}
	se r, l;
	r.start = -1;
	r.end = -1;
	l.start = -1;
	l.end = -1;
	if (DP[start + 1][end] == -1)
		r = longestPalindromeHelp(s, start + 1, end, DP);
	if (DP[start][end - 1] == -1)
		l = longestPalindromeHelp(s, start, end - 1, DP);
	if ((r.end - r.start) >= (l.end - l.start)) {
		//cout<<s.substr(r.start, r.end-r.start+1)<<endl;
		return r;//s.substr(start+1,end-start);
	}
	else {
		//cout<<s.substr(l.start, l.end-l.start+1)<<endl;
		return l;//s.substr(start,end-start);

	}
}

string longestPalindromeRec(string s) {
	if (s.length() <= 1) {
		return s;
	}
	vector<int> DPR(s.length(), -1);
	vector<vector<int>> DP(s.length(), DPR);
	se sse = longestPalindromeHelp(s, 0, s.length() - 1, DP);
	return s.substr(sse.start, sse.end - sse.start + 1);
}
int main() {

	string s("aacdefcaa");
	string s1("geeksskeeg");
	string s2("babad");
	string s3("ababa");
	string s4("ab");
	string s5("babadada");
	string s6("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	cout << longestPalindrome(s)  << endl;
	cout << longestPalindrome(s1) << endl;
	cout << longestPalindrome(s2) << endl;
	cout << longestPalindrome(s3) << endl;
	cout << longestPalindrome(s4) << endl;
	cout << longestPalindrome(s5) << endl;
	cout << longestPalindrome(s6) << endl;

	cout << longestPalindromeBin(s) << endl;
	cout << longestPalindromeBin(s1) << endl;
	cout << longestPalindromeBin(s2) << endl;
	cout << longestPalindromeBin(s3) << endl;
	cout << longestPalindromeBin(s4) << endl;
	cout << longestPalindromeBin(s5) << endl;
	cout << longestPalindromeBin(s6) << endl;
	cin.get();
	return 1;
}