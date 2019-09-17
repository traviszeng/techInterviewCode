/**
度度熊的工作
时间限制：C/C++ 2秒，其他语言 4秒
空间限制：C/C++ 262144K，其他语言 524288K
64bit IO Format: %lld
本题可使用本地IDE编码，不做跳出限制，编码后请点击“保存并调试”按钮进行代码提交。
题目描述
老板给度度熊分配了个工作，第个工作需要耗费a_i单位时间，每个工作必须老板给定的限制时间b_i前完成。
度度熊从时刻开始工作，在同一时间度度熊手上只能做一件工作，度度熊想知道他是否能把所有工作都完成呢？
输入描述:
第一行一个数表示数据组数。
每组数据第一行一个数。
接下来行每行两个数表示a_i,b_i。
输出描述:
每组数据输出一行，如果度度熊能完成他的工作输出"Yes"不然输出“No”。
示例1输入输出示例仅供调试，后台判题数据一般不包含示例
输入
复制
1
5
2 4
1 9
1 8
4 9
3 12
输出
复制
Yes
说明
从前往后依次做每个工作即可完成。
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int check(int n) {
	vector<pair<int, int>> task;
	for (int j = 0; j < n; j++) {
		int a, b;
		cin >> a >> b;
		task.push_back(make_pair(a, b));
	}
	sort(task.begin(), task.end(), cmp);
	int curTime = 0;
	for (int j = 0; j < n; j++) {
		curTime = curTime + task[j].first;
		if (curTime > task[j].second) {
			cout << "No"<<endl;
			return 0;
		}
	}
	cout << "Yes"<<endl;
	return 0;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		check(n);
	}
	system("pause");
}