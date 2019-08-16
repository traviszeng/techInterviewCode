#include<iostream>
using namespace std;
int binarySearch(long *a, long  target, int start, int end) {
	if (a[start] > target || a[end] < target || start < end)
		return -1;

	int mid = (start + end) >>1;
	if (a[mid] == target)
		return mid;
	else if (a[mid] > target) {
		if (start <= mid - 1)
			return binarySearch(a, target, start, mid - 1);
		else
			return -1;
	}
	else {
		if (end >= mid + 1)
			return binarySearch(a, target, mid + 1, end);
		else
			return -1;
	}
}


int main() {
	int n;
	cin >> n;
	if (n <= 0) {
		cout << -1;
		return 0;
	}
	long *a = new long[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	long  target;
	cin >> target;
	cout << binarySearch(a, target,0,n-1);
}