/**


小明目前在做一份毕业旅行的规划。打算从北京出发，分别去若干个城市，然后再回到北京，每个城市之间均乘坐高铁，且每个城市只去一次。
由于经费有限，希望能够通过合理的路线安排尽可能的省一些路上的花销。给定一组城市和每对城市之间的火车票的价钱，找到每个城市只访问一次并返回起点的最小车费花销。

输入描述:
城市个数n（1<n≤20，包括北京）

城市间的车票价钱 n行n列的矩阵 m[n][n]


输出描述:
最小车费花销 s
示例1
输入
4
0 2 6 5
2 0 4 4
6 4 0 2
5 4 2 0
输出
13
说明
共 4 个城市，城市 1 和城市 1 的车费为0，城市 1 和城市 2 之间的车费为 2，
城市 1 和城市 3 之间的车费为 6，城市 1 和城市 4 之间的车费为 5，依次类推。
假设任意两个城市之间均有单程票可购买，且票价在1000元以内，无需考虑极端情况。

*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
	int n;
	cin >> n;
	vector<vector<int>> cities;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			temp.push_back(t);
		}
		cities.push_back(temp);
	}
	//将城市进行二进制编码 例如若有4个城市 则1010表示选取第二个和第四个城市
	//dp[i][j]表示经过了i集合中的所有城市且以j结尾的路径最小值
	//状态转移方程为dp[i][j] = min(dp[i][k]+cities[k][j],dp[i][j])   其中k是i集合中的一个城市
	int m = 1 << n; //二进制的状态共有2^n种
	int **dp = new int*[m+2];
	for (int i = 0; i < m; i++)
	{
		dp[i] = new int[n + 2];
		for (int j = 0; j < n; j++) {
			dp[i][j] = INF;
		}
	}

	//从第一个城市到第一个城市代价为0
	dp[1][0] = 0;
	int ans = INF;

	//固定从第一个城市出发
	for (int i = 1; i < m; i++) { //i表示所有可能的城市集合
		for (int j = 1; j < n; j++) { //j为城市列表 第一个城市已经走过
			if (i & (1 << j)) //说明j城已经在集合i中
				continue;

			if (!(i & 1))//如果第一个城市没有在i中
				continue;
			for (int k = 0; k < n; k++) {//在i集合中的每个城市尝试，找到最小的
				if (i & (1 << k)) {//说明k在集合中
					dp[(1 << j) | i][j] = min(dp[(1 << j) | i][j], dp[i][k] + cities[k][j]);
				
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
		ans = min(ans, dp[m - 1][i] + cities[i][0]);  //每次需要回到原点
	
	
	cout << ans << endl;
	
	//cout << m;
	system("pause");
}