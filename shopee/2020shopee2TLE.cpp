/**
给定一个有n个正整数的数组A和一个整数sum,求选择数组A中部分数字和为sum的方案数。
当两种选取方案有一个数字的下标不一样,我们就认为是不同的组成方案。
输入描述:
输入为两行:

第一行为两个正整数n(1 ≤ n ≤ 1000)，sum(1 ≤ sum ≤ 1000)

第二行为n个正整数A[i](32位整数)，以空格隔开。
输出描述:
输出所求的方案数
示例1
输入
5 15
5 5 10 2 3
输出
4

*/
#include<iostream>
using namespace std;


//TLE
int getNumUsingINumber(int *a, int i, int start, int sum,int aNum) {
	int num = 0;
	if (i == 0) {
		if (sum == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}

	for (int j = start; j <= aNum - i; j++) {
		if (a[j] <= sum) {
			num += getNumUsingINumber(a, i - 1, j + 1, sum - a[j],aNum);
		}
	}

	return num;
}



int getNum(int *a, int sum,int aNum) {
	int count = 0;
	for (int i = 0; i <= aNum; i++) {
		count += getNumUsingINumber(a, i, 0, sum,aNum);
	}
	return count;
}


int main() {
	int n, sum;
	cin >> n >> sum;
	int *num = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	cout<<getNum(num, sum, n);
	system("pause");

}