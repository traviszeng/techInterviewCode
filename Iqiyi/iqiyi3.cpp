/*
题目描述：
库特君在吃面条！

他将面条放在了数轴上，每根面条对应数轴上的两个点a和b，
他想知道在任意两根面条不重叠(端点可以重叠）的情况下最多能选出多少根面条。

1 <= n <= 100

-999 <= a<b<=999

输入描述：
第一行一个整数N
接下来，N行每行N个整数a和b

输出描述：
一个数的答案

输入样例：
3
3 6 
1 3 
2 5

输出样例：
2
*/

/**
最多不重合区间问题
贪心策略：按照b1<=b2<=b3…的方式排序，然后从前向后遍历，每当遇到可以加入集合的区间，就把它加入集合。（集合代表解的集合）
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct line{
	int left;
	int right;
	line(int l, int r) {
		left = l;
		right = r;
	}
	//重载小于
	bool operator <(const line& rhs) {
		return right < rhs.right;
	}
};

int main(){
	int n;
	cin >> n;
	vector<line> lineVec;
	vector<line> resultVec;
	
	for (int i = 0; i < n; i++) {
		int ltemp, rtemp;
		cin >> ltemp >> rtemp;
		lineVec.push_back(line(ltemp, rtemp));
	}
	//根据右边大小排序
	sort(lineVec.begin(), lineVec.end());
	//第一根加入
	resultVec.push_back(lineVec[0]);
	for (int i = 1; i < lineVec.size(); i++) {
		bool isOverlapped = false;
		for (int j = 0; j < resultVec.size(); j++) {
			if (resultVec[j].right > lineVec[i].left)
				isOverlapped = true;
		}
		if (!isOverlapped)
			resultVec.push_back(lineVec[i]);
	}
	cout << resultVec.size();
	system("pause");
}