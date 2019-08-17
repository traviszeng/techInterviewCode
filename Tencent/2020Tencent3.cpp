/**
先按照左值排序，然后右值倒叙
*/

#include<iostream>
#include<algorithm>
using namespace std;

struct p {
	int l;
	int r;
	bool operator<(const p & a)const {
		if (l == a.l) return r>a.r;
		return l<a.l;
	}
} arg[100005];

int main() {
	int n, l;
	cin >> n >> l;
	for (int i = 0; i<n; ++i) {
		cin >> arg[i].l >> arg[i].r;
	}
	sort(arg, arg + n);
	if (arg[0].l>0) {
		cout << -1 << endl;
		return 0;
	}
	int right = 0, pos = 0, max_len = 0;
	int ans = 0;
	while (true) {
		if (right >= l) {
			break;
		}
		for (int i = pos; i<n; ++i) {
			if (arg[i].l <= right && arg[i].r > max_len) {
				pos = i;
				max_len = arg[i].r;
			}
			if (arg[i].l>right) {
				break;
			}
		}
		if (max_len == right) {
			cout << -1 << endl;
			return 0;
		}
		right = max_len;
		++ans;
	}

	cout << ans << endl;

}