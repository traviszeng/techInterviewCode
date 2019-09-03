/**
棋盘最短路径
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB题目描述：
假设以一个n*m的矩阵作为棋盘，每个棋位对应一个二维坐标 (x, y)。你有一颗棋子位于左上起点(0, 0)，现在需要将其移动到右下底角 (n-1, m-1)，棋子可以向相邻的上下左右位置移动，每个坐标最多只能经过一次。棋盘中散布着若干障碍，障碍物不能跨越，只能绕行，问是否存在到达右下底角的路线？若存在路线，输出所需的最少移动次数；若不存在，输出0。 Input 第一行三个正整数n，m和k，代表棋盘大小与障碍物个数  1< n、m < 100,  k < n*m 第二行至第k+1行，每行为两个整数x和y，代表k个障碍物的坐标。
输入
输入三个正整数n，m和k，代表棋盘大小与障碍物个数  1< n、m < 100,  k < n*m
第二行至第k+1行，每行为两个整数x和y，代表k个障碍物的坐标。
输出
输出从起点到终点的最短路径的长度，如果不存在，即输出0

样例输入
5 10 20
1 4
0 3
2 2
4 4
1 7
1 3
2 3
1 8
3 7
3 5
1 5
3 9
4 8
4 0
4 1
2 1
0 7
2 4
4 5
0 8
样例输出
0
*/
#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int m;
int n;
bool flag = false;
//set<pair<int,int>> vis;
bool getpoint(int row, int col, set<pair<int, int>> vis)
{
	auto p = make_pair(row, col);
	if (vis.count(p))
	{
		return true;
	}
	else
	{
		return false;
	}

}


bool checked(set<pair<int, int>> vis, int rows, int cols, int row, int col, bool *visited)
{
	if (row < rows && col < cols && col >= 0 && row >= 0 && !getpoint(row, col, vis) && !visited[row*cols + col])
	{
		return true;
	}
	return false;
}
int movingCountCore(set<pair<int, int>> vis, int rows, int cols, int row, int col, bool *visited)
{
	int count = 0;
	if (row == n - 1 && col == m - 1)
	{
		flag = true;
	}
	if (checked(vis, rows, cols, row, col, visited))
	{
		visited[row*cols + col] = true;
		count = 1 + movingCountCore(vis, rows, cols, row - 1, col, visited) +
			movingCountCore(vis, rows, cols, row + 1, col, visited) +
			movingCountCore(vis, rows, cols, row, col - 1, visited) +
			movingCountCore(vis, rows, cols, row, col + 1, visited);
	}
	if (flag == true)
	{
		return count;
	}
	else
	{
		return 0;
	}

}
int movingCount(set<pair<int, int>> vis, int rows, int cols)
{
	if (rows <= 0 || cols <= 0)
	{
		return 0;
	}
	bool *visited = new bool[rows*cols];
	for (int i = 0; i < rows*cols; i++)
	{
		visited[i] = false;
	}
	int count = movingCountCore(vis, rows, cols, 0, 0, visited);
	delete[] visited;
	return count;
}
int main()
{
	int k;
	int u, v;
	scanf("%d%d%d", &n, &m, &k);
	set<pair<int, int>> vis;
	for (int i = 0; i < k; i++)
	{
		scanf("%d%d", &u, &v);
		auto p = make_pair(u, v);
		vis.insert(p);
	}
	int aa = movingCount(vis, n, m);
	cout << aa << endl;
}
