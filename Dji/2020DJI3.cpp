/*
应该怎么吃呢
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
小W非常喜欢吃零食，经常都会去零食间里购买半价的零食吃，但是他为了控制自己的体重，因此会限制自己买零食的开销在某个数值以内。

但是小W有一个特别的爱好，他对于某些零食特别的喜欢，并且会对这些零食的喜爱成都进行排序。对于零食A和零食B，如果小W对零食A的喜爱程度大于对零食B的喜爱程度，那么每次拿零食的时候，一定会确保A的数目比B多。

现在零食间里有N种零食，假设每种零食都是取不完的，但小W每次都会刚好花完所有的开销，那么小W去取零食的时候应该有多少种可能的取法呢？

输入
输入包含多组测试数据，每组数组:

第一行：买零食的开销 V (V < 1000) 和 所有的零食种类数目 N (N < 200)。

第二行：第 i 个正整数表示第 i 种零食的价格 c_i (c_i < 1000)。

第三行：特别喜欢的零食的种类数 M (2 <= M <= N)

第四行：按照对 M 种零食的喜爱程度从高到低排序，第 i 种零食的喜爱程度会大于第 i + 1 种，保证不会形成环

输出
对于每组测试数据:

输出一个整数ans，表示在满足小W的特殊偏好的情况下，并且花光所有开销，有多少可能方案。

（由于ans_i可能很大，因此最终结果 ans_i % 10000007）


样例输入
5 2
1 2
2
2 1
样例输出
1

提示
存在一种方案数(1,2)

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	int p;//价格
	int l;//喜欢程度
};
bool cmp(const node &a, const node &b)
{
	return a.l>b.l;
}
void dfs(vector<node>& c, vector<int>& times, int &sum, int v, long long &count, int k)
{
	if (sum>v) return;
	if (sum == v)
	{
		count++;
		return;
	}
	for (int i = k; i<c.size(); i++)
	{
		if (i != 0 && times[i] + 1 >= times[i - 1]) continue;//如果比之前更喜欢的多了
		times[i]++;
		sum += c[i].p;
		dfs(c, times, sum, v, count, i);
		sum -= c[i].p;
		times[i]--;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	int v, n;
	while (cin >> v >> n)
	{
		vector<node> c(n);
		for (int i = 0; i<n; i++)
		{
			cin >> c[i].p;
			c[i].l = 0;
		}
		int m;
		cin >> m;
		int idx;
		vector<int> times(n, 0);//选择次数
		for (int i = 0; i<m; i++)
		{
			cin >> idx;
			c[idx].l = m - i;//喜爱程度
		}
		sort(c.begin(), c.end(), cmp);
		long long count = 0;
		int sum = 0;
		dfs(c, times, sum, v, count, 0);
		count = count % 10000007;
		cout << count << endl;
	}
}