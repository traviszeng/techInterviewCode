/**
小多想在美化一下自己的庄园。他的庄园毗邻一条小河，他希望在河边种一排树，共 M 棵。
小多采购了 N 个品种的树，每个品种的数量是 Ai (树的总数量恰好为 M)。
但是他希望任意两棵相邻的树不是同一品种的。小多请你帮忙设计一种满足要求的种树方案。

输入描述:
第一行包含一个正整数 N，表示树的品种数量。
第二行包含 N 个正整数，第 i (1 <= i <= N) 个数表示第 i 个品种的树的数量。
数据范围：
1 <= N <= 1000
1 <= M <= 2000


输出描述:
输出一行，包含 M 个正整数，分别表示第 i 棵树的品种编号 (品种编号从1到 N)。
若存在多种可行方案，则输出字典序最小的方案。若不存在满足条件的方案，则输出"-"。
示例1
输入
3
4 2 1
输出
1 2 1 2 1 3 1

*/
/**
 贪心算法：从前往后找当前数量最多的树作为要种的树
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct tree {
	int no;
	int num;
	tree(int n, int n1) {
		no = n;
		num = n1;
	}
	bool operator <(const tree& rhs) {
		if (num < rhs.num)
			return true;
		else if (num == rhs.num)
			return no > rhs.no;
		else return false;
	}

};

int main() {
	int n,M=0;
	cin >> n;
	vector<int> T;
	
	int max = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		max = max < temp ? temp : max;
		M += temp;
		T.push_back(temp);
	}
	if (max - (M - max) > 1) {
		cout << '-';
		return 0;
	}

	for (int prev = -1, k = 0; M-- > 0; T[k]--, prev = k) {
		max = *max_element(T.begin(), T.end());
		
		for ( k = 0; k < n; k++) {
			if (k == prev || T[k] == 0) //如果和之前种的树一样或者树的数量为0
				continue;
			if (max-(M-max) <=1 || max == T[k]) 
				break;
		}

		cout << k + 1;
		if (M == 0) cout << endl;
		else cout << " ";
	}
	
	system("pause");

}