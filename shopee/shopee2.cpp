/**

shopee的零食柜，有着各式各样的零食，但是因为贪吃，小虾同学体重日益增加，
终于被人叫为小胖了，他终于下定决心减肥了，他决定每天晚上去操场跑两圈，
但是跑步太累人了，他想转移注意力，忘记痛苦，正在听着音乐的他，突然有个想法，
他想跟着音乐的节奏来跑步，音乐有7种音符，对应的是1到7，那么他对应的步长就可以是1-7分米，
这样的话他就可以转移注意力了，但是他想保持自己跑步的速度，在规定时间m分钟跑完。
为了避免被累死，他需要规划他每分钟需要跑过的音符，这些音符的步长总和要尽量小。
下面是小虾同学听的歌曲的音符，以及规定的时间，你能告诉他每分钟他应该跑多少步长？


输入描述:
输入的第一行输入 n（1 ≤ n ≤ 1000000，表示音符数），m（1<=m< 1000000, m <= n）组成，

第二行有 n 个数，表示每个音符（1<= f <= 7）


输出描述:
输出每分钟应该跑的步长
示例1
输入
8 5
6 5 6 7 6 6 3 1
输出
11
说明
6 | 5 6 | 7 | 6 | 6 3 1  为最优解

如果小于11，必然分段大于5
*/

/**
贪心算法+二分查找
*/

#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

/**检查当前的总部长是否满足条件*/
bool check(int l,int n,int m,int *a) {
	int cnt = 0, tmp = 0;
	for (int i = 0; i < n; i++) {
		if (tmp + a[i] <= l) {
			tmp += a[i];
		}
		else {
			tmp = a[i];
			cnt++;
		}
	}
	return m >= cnt + 1;
}


int main() {
	int n, m;
	cin >> n >> m;
	int *yin = new int[n];
	for (int i = 0; i < n; i++)
		cin >> yin[i];

	int max, mi, mid, ans;
	max = n * 7;
	mi = n;
	ans = max;
	while (mi <= max) {
		mid = (max + mi) >> 1;
		if (check(mid,n,m,yin)) {
			ans = min(mid, ans);
			max = mid - 1;
		}else
		{
			mi = mid + 1;
		}

	}

	cout << ans;
	system("pause");


}
