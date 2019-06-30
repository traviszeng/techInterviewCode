#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

/*

描述：小Q正在攀登一座宝塔，这座塔很特别，塔总共有n曾层，但是没两层之间的净高却不相同，所以造成了小Q爬过每层的时间也不同。如果某一层的高度为x，那么爬过这一层锁需的还是件也是x。小Q孩会使用一种魔法，没用一次可以让他向上跳一层或两层，但是每次跳跃之后小Q豆浆用完魔法力，必须爬过至少一层才能再次跳跃（你可以认为小Q需要跳两次一层才休息，最后也可以跳到塔外即超过塔高，跳是不消耗时间的）。
小Q想用最短的时间爬过塔顶，希望你能告诉他最短时间是多少。

输入描述：
第一行一个数n n<=10000，表示塔的层数。
接下来的n行每行一个数h(1<=h<=100)，表示从下往上每层的高度。

输出描述：
一个数，表示最短时间。

*/

int main() {
	int num;
	cin >> num;
	//记录跳到第i层的最小值
	int *jump = new int[num+1];
	//记录爬到第i层的最小值
	int *climb = new int[num + 1];

	int *a = new int[num];
	for (int i = 0; i < num; i++)
	{
		cin >> a[i];
	}

	

	jump[0] = 0;
	climb[0] = 0;
	for (int i = 1; i < num + 1; i++) {
		//for jump
		if (i == 1)
			jump[i] = 0;
		else
			jump[i] = min(climb[i-2],climb[i-1]);

		climb[i] = min(jump[i - 1], climb[i - 1]) + a[i-1];
	}

	cout << min(climb[num], jump[num]);
	system("pause");
	return 0;
}