/*
时间限制：C/C++ 1秒，其他语言 2秒
空间限制：C/C++ 65536K，其他语言 131072K
64bit IO Format: %lld
语言限定：C++11(clang++ 3.9), C++14(g++5.4), Java(javac 1.8), C(clang 3.9)
本题可使用本地IDE编码，不做跳出限制，编码后请点击“保存并调试”按钮进行代码提交。
题目描述
小明作为一个游泳池管理员，以玩弄给水管和排水管为乐，也因此产生了很多数学题考验小朋友。

现在小明想把这个行动升级，考验一下程序员，做了一个自动装置来控制给水管和排水管。在开始时，给水管和排水管都是打开状态的，并且游泳池里没有水。在自动装置的作用下，每经过t1分钟，给水管的状态都会改变，即从打开状态变为关闭状态或从关闭状态变为打开状态，而同时每经过t2分钟，排水管的状态也会改变。当给水管打开时，给水管每分钟会向游泳池里注入m1升水；当排水管打开时，排水管每分钟会把游泳池里水排走m2升；当给水管和排水管同时打开时，游泳池的水量变化为每分钟(m1-m2)升。当然泳池的水量不能变为负数，同时泳池也有个最大容量m，水量不能超过m升。那么经过t分钟后，游泳池里有多少升水？

输入描述:
输入第一行为一个正整数T，表示有T组数据。

每组数据的为一行包含六个整数，分别表示m, t, m1, t1, m2, t2。

数据范围：

对于所有数据，满足1<=T<=10, 1<=m<=100000, 1<=t<=86400, 1<=m1,m2<=100, 1<=t1,t2<=10。
输出描述:
对于每一个数据，输出一行，包括一个整数，为在t分钟后游泳池中的水量。
示例1输入输出示例仅供调试，后台判题数据一般不包含示例
输入

5
10 2 1 5 2 5
10 2 10 5 2 5
10 2 3 5 2 5
100 100 3 4 4 3
10000 1000 10 5 5 3
输出

0
10
2
3
2495
*/

#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int  m, t, vAdd, tAdd, vMinu, tMinu;
		cin >> m >> t >> vAdd >> tAdd >> vMinu >> tMinu;

		bool isAdd = true;
		bool isMinu = true;
		int  curWater = 0;
		for (int ct = 0; ct < t; ct++) {
			if (ct % (2 * tAdd) < tAdd && ct % (2 * tMinu) < tMinu) {
				int temp = 0 < curWater + vAdd - vMinu ? 0 : curWater + vAdd - vMinu;
				curWater = m > temp ? m : temp;
			}
			else if (ct % (2 * tAdd) < tAdd && ct % (2 * tMinu) >= tMinu) {
				curWater = m > curWater + vAdd ? curWater + vAdd : m;
			}
			else if(ct % (2 * tAdd) >= tAdd && ct % (2 * tMinu) < tMinu){
				curWater = 0 > curWater - vMinu ? 0 : curWater - vMinu;
			}
		}
		cout << curWater << endl;
	}
	system("pause");
}