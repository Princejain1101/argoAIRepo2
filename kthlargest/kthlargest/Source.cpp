#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <set>

using namespace std;

void printset(multiset<int> q) {
	for (auto &i : q) {
		cout << i << "\t";
	}
	cout << endl;
}
// using minHeap
int findKthlargest(vector<int>& nums, int k) {
	multiset<int> q;
	int i = 0;
	while (i < k) {
		q.insert(nums[i]);
		i++;
	}
	//printset(q);
	for (i = k; i < nums.size(); i++) {
		if (nums[i] > *(q.begin())) {
			q.erase(q.begin());
			q.insert(nums[i]);
		}
		//printset(q);
		//cout << q.size() << endl;
	}
	return *(q.begin());
}
void swap(vector<int> &nums, int i, int j) {
	int k = nums[i];
	nums[i] = nums[j];
	nums[j] = k;
}
// using quicksort
int findKthlargestQuickSort(vector<int>& nums, int k) {
	int pivot = nums.size() - 1;
	int i = 0;
	int j = nums.size() - 1;
	while(i < j) {
		if (nums[i] > nums[pivot]) {
			i++;
			continue;
		}
		if (nums[j] <= nums[pivot]) {
			j--;
			continue;
		}
		swap(nums, i, j);
	}
	if (i >= k) {
		vector<int> numleft(nums.begin(), nums.begin()+i);
		return findKthlargestQuickSort(numleft, k);
	}
	if (i + 1 == k) {
		return nums[pivot];
	}
	vector<int> numright(nums.begin() + i, nums.end()-1);
	return findKthlargestQuickSort(numright, k - (i+1));
}


// quick sort with no hidden memory
int findKthLargestQuickSort2Help(vector<int>& nums, int k, int first, int last) {
	if (first == last) {
		return nums[first];
	}
	int pivot = last;
	int i = first;
	int j = last;
	while (i < j) {
		if (nums[i] > nums[pivot]) {
			i++;
			continue;
		}
		if (nums[j] <= nums[pivot]) {
			j--;
			continue;
		}
		swap(nums, i, j);
	}
	if (i-first >= k) {
		//vector<int> numleft(nums.begin(), nums.begin() + i);
		return findKthLargestQuickSort2Help(nums, k, first, i-1);
	}
	if (i - first + 1 == k) {
		return nums[pivot];
	}
	//vector<int> numright(nums.begin() + i, nums.end() - 1);
	return findKthLargestQuickSort2Help(nums, k - (i - first + 1), i, last-1);
}

int findKthLargestQuickSort2(vector<int>& nums, int k) {
	return findKthLargestQuickSort2Help(nums, k, 0, nums.size()-1);
}


int main() {
	cout << "result:"<< findKthlargest(vector<int>({3,2,1,5,6,4}), 2) << endl;
	//cout << "result:" << findKthLargestQuickSort2(vector<int>({ 3,2,1,5,6,4 }), 2) << endl;
	//cout << "result:"<< findKthlargest(vector<int>({3,2,3,1,2,4,5,5,6}), 4) << endl;
	cout << "result:" << findKthLargestQuickSort2(vector<int>({ 3,2,3,1,2,4,5,5,6 }), 9) << endl;

	//cout << "result:" << findKthlargest(vector<int>({-1,2,0 }), 2) << endl;
	//cout << "result:" << findKthLargestQuickSort2(vector<int>({ -1,2,0 }), 3) << endl;
	cin.get();
	return 1;
}