/*
题目描述
伞屉国是一个以太阳能为主要发电手段的国家，因此他们国家中有着非常多的太阳能基站，链接着的基站会组合成一个发电集群。但是不幸的是伞屉国不时会遭遇滔天的洪水，当洪水淹没基站时，基站只能停止发电，同时被迫断开与相邻基站的链接。你作为伞屉国的洪水观察员，有着这样的任务：在洪水到来时，计算出发电集群被洪水淹没后被拆分成了多少个集群。

由于远古的宇宙战争的原因，伞屉文明是一个二维世界里的文明，所以你可以这样理解发电基站的位置与他们的链接关系：给你一个一维数组a，长度为n，表示了n个基站的位置高度信息。数组的第i个元素a[i]表示第i个基站的海拔高度是a[i],而下标相邻的基站才相邻并且建立链接，即x号基站与x-1号基站、x+1号基站相邻。特别的，1号基站仅与2号相邻，而n号基站仅与n-1号基站相邻。当一场海拔高度为y的洪水到来时，海拔高度小于等于y的基站都会被认为需要停止发电，同时断开与相邻基站的链接。

输入描述:
每个输入数据包含一个测试点。

第一行为一个正整数n，表示发电基站的个数 (0 < n <= 200000)

接下来一行有n个空格隔开的数字，表示n个基站的海拔高度，第i个数字a[i]即为第i个基站的海拔高度，对于任意的i(1<=i<=n),有(0 <= a[i] < 2^31-1)

接下来一行有一个正整数q(0 < q <= 200000)，表示接下来有q场洪水

接下来一行有q个整数，第j个整数y[j]表示第j场洪水的海拔为y[j],对于任意的j(1<=j<=n),有(-2^31 < y[j] < 2^31-1)
输出描述:
输出q行，每行一个整数，第j行的整数ans表示在第j场洪水中，发电基站会被分割成ans个集群。标准答案保证最后一个整数后也有换行。
示例1输入输出示例仅供调试，后台判题数据一般不包含示例
输入

10
6 12 20 14 15 15 7 19 18 13
6
15 23 19 1 17 24
输出

2
0
1
1
2
0
*/

#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int numOfFlood;
	cin >> numOfFlood;
	for (int i = 0; i < numOfFlood; i++) {
		int flood;
		cin >> flood;
		int *b = new int[n];
		b[0] = a[0] <= flood ? -1 : a[0];
		int ans = 0;
		if (b[0] != -1) ans += 1;
		for (int j = 1; j < n; j++) {
			if (a[j] > flood && b[j - 1] == -1) {
				ans += 1;
				b[j] = a[j];
			}
			else if (a[j] > flood && b[j - 1] != -1) {
				b[j] = a[j];
			}
			else
				b[j] = -1;
		}

		
			
		cout << ans << endl;
		delete b;
		b = nullptr;

	}
	system("pause");

	
}