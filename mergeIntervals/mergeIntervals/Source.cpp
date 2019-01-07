#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) :start(s), end(e) {}
};

void inRange(vector<Interval> &ret, Interval inter) {
	int N = ret.size();
	int it = 0;
	while(it < ret.size()){
		Interval i = ret[it];
		if (inter.start > i.end || inter.end < i.start) {
			it++;
			continue;
		}
		else {
			inter.start = min(i.start, inter.start);
			inter.end = max(i.end, inter.end);
			ret.erase(ret.begin()+it);
		}
	}
	ret.push_back(Interval(inter.start, inter.end));
}
vector<Interval> merge(vector<Interval> & intervals) {
	vector<Interval> ret;
	for (auto &inter : intervals) {
		inRange(ret, inter);
	}
	return ret;
}

int main() {

	vector<Interval> intervals({Interval(1,3), Interval(2,6), Interval(8,10), Interval(15,18)});
	//vector<Interval> intervals({ Interval(1,4), Interval(4,5)});

	vector<Interval> ret = merge(intervals);

	for(auto &i : ret) {
		cout << i.start << " " << i.end << endl;
	}
	cin.get();
	return 1;
}