//某个集合的子集是否能通过全体元素的或运算求得查询值
#pragma warning(disable : 4996)
/**
对于每一次询问，我们肯定会选择所有y，满足y&x==y，即在二进制表达下，y是x的子集。
那么我们可以维护一个数组p[i]，表示所有为i的子集的数字的Or值是多少。
每次插入一个数字，如果它没有重复出现过，就枚举它的超集更新答案。
询问的时候只需要看p[x]是否等于x就好了。
*/
#include<bits/stdc++.h>
using namespace std;
int p[131072];
int mx = 131071; //11111111111111111 
int q;
int main()
{
	scanf("%d", &q);
	while (q--) {
		int op, x; scanf("%d%d", &op, &x);
		if (op == 1) {
			if (p[x] == x) continue;
 			int s = mx ^ x;
			for (int i = s; i; i = (i - 1) & s) {
				p[i ^ x] |= x;
			}
			p[x] = x;
		}
		else {
			if (p[x] == x) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
