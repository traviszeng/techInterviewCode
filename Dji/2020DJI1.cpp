/*
爱玩游戏的小J
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
有许多程序员都热爱玩游戏游戏，而小J自称为游戏王，曾玩过几百种游戏，几乎所有能玩到的游戏大作都玩遍了。
随着时间的推移，他发觉已经没有游戏可以让他玩了！于是他想改玩一些古老的游戏，以成为真正的“游戏王”。
他希望在接下来的一段时间内将过去出的游戏全部玩一遍，但是毕竟时间有限，因此他感到很苦恼。
于是他给每个游戏标上一个成就值，同时估算了完成这些游戏所需要的时间。

现在他只有X天时间。而每个游戏一旦开始玩，至少需要玩一天才能够停下来。
那么，他所玩完的游戏的成就值之和最大能达到多少呢？（每个游戏必须玩完才能取得成就值。）

输入
第一行输入case数T（0<T<20）。对于每个case，第一行输入游戏的数目N(0<N<11)，
总时间X(0<X<1000)用空格分隔。从第二行到第N+1行每行输入游戏的成就值Ai(0<Ai<10000)，所需要花费时间Bi(0<Bi<10000)。

输出
对每个case输出一行，成就值之和的最大值。


样例输入
2
2 2
10 1
20 2
3 4
10 2
18 3
10 2
样例输出
20
20


*/


#include<iostream>
#include<vector>
using namespace std;
int main() {
	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		int n, x;
		cin >> n >> x;
		int *a = new int[n+1];
		int *b = new int[n+1];
		for (int j = 1; j < n+1; j++) {
			cin >> a[j] >> b[j];
			//cout << a[j] << b[j];
			//cout << endl;
		}
		

		vector<vector<int>> dp;
		for (int k = 0; k < n + 1; k++) {
			vector<int> temp;
			for (int j = 0; j < x + 1; j++) {
				temp.push_back(0);
			}
			dp.push_back(temp);
		}

		for (int k = 1; k <= n; k++) {
			for (int j = x; j >= 0; j--) {
				if (j >= b[k]) {
					dp[k][j] = (dp[k - 1][j - b[k]] + a[k]) > dp[k - 1][j] ? (dp[k - 1][j - b[k]] + a[k]) : dp[k - 1][j];
				}
				else
					dp[k][j] = dp[k - 1][j];
			}
		}
		cout << dp[n][x] << endl;
	}

	system("pause");

}