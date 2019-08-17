/**
预处理左边能看到的楼。右边能看到的楼，总的看到的数量是左边可以看到的楼+右边可以看到的楼+1
预处理使用栈，如果发现现在需要入栈的楼比栈顶高了，就将它出栈。直到可以放进去位置，此时可以看到的楼的数量为栈的总大小
*/
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int n;
int w[100005];
int l[100005], r[100005];

stack<int> stk;

int main() {
	cin >> n;
	for (int i = 0; i<n; ++i) {
		cin >> w[i];
	}
	for (int i = 0; i<n; ++i) {
		if (stk.empty()) {
			stk.push(w[i]);
		}
		else {
			while (!stk.empty() && stk.top() <= w[i]) {
				stk.pop();
			}
			stk.push(w[i]);
		}
		l[i] = stk.size();
	}

	while (!stk.empty()) stk.pop();

	for (int i = n - 1; i >= 0; --i) {
		if (stk.empty()) {
			stk.push(w[i]);
		}
		else {
			while (!stk.empty() && stk.top() <= w[i]) {
				stk.pop();
			}
			stk.push(w[i]);
		}
		r[i] = stk.size();
	}

	for (int i = 0; i<n; ++i) {
		cout << l[i] << " ";
	}cout << endl;

	for (int i = 0; i<n; ++i) {
		cout << r[i] << " ";
	}cout << endl;

	for (int i = 0; i<n; ++i) {
		int ans = 1;
		if (i>0) {
			ans += l[i - 1];
		}
		if (i<n - 1) {
			ans += r[i + 1];
		}
		cout << ans << " ";
	}cout << endl;

}