/**

编程|30分] 搭积木
时间限制：C/C++ 1秒，其他语言 2秒
空间限制：C/C++ 32768K，其他语言 65536K
64bit IO Format: %lld
本题可使用本地IDE编码，不做跳出限制，编码后请点击“保存并调试”按钮进行代码提交。
题目描述
多多鸡宝宝在玩搭积木游戏。有 N 个长方体积木，每个积木的高都是1，长宽都为 Li ，重量为 Wi 。
现在多多鸡宝宝想要用这些积木搭一个高高的金字塔。他打算金字塔的每一层是由且仅由一块积木组成，同时每一层的积木边长都严格比在其下方的积木小。
在多次尝试之后，多多鸡宝宝发现每块积木只能承受自身重量的7倍重量——若超过7倍自重，搭建的金字塔会因此变得不稳定。具体来说即：对于每一块积木，在其上方的积木重量之和必须小于等于其自重的7倍。
多多鸡宝宝想请你帮他计算一下最高可以搭一个多高的金字塔？
数据范围：
1 <= N <= 100
1 <= Li <= 1000
1 <= Wi <= 1000
输入描述:
第一行包含1个正整数 N ，表示积木的数量。
第二行包含 N 个正整数，第 i 个数表示第 i 个积木的长度 Li 。
第三行包含 N 个正整数，第 i 个数表示第 i 个积木的重量 Wi 。
输出描述:
输出占一行，仅包含一个整数，表示可以搭出的金字塔的最高高度。
示例1输入输出示例仅供调试，后台判题数据一般不包含示例
输入

10
1 2 3 4 5 6 7 8 9 10
1 1 1 1 1 1 1 1 1 10
输出

9
*/


#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct jimu {
	int w;
	int l;
	jimu(int ll, int ww) {
		l = ll;
		w = ww;
	}
	friend istream &operator>>(istream &in, jimu &x) {
		in >> x.l >> x.w;
		return in;
	}

	bool operator<(const jimu &s)  const{
		if (l == s.l)
			return w < s.w;
		return l < s.l;
	}
};


int main() {
	int n;
	cin >> n;
	int *l = new int[n];
	int *w = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	vector<jimu> jimuVec;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		jimuVec.push_back(jimu(l[i], w[i]));
	}
	sort(jimuVec.begin(), jimuVec.end());
	int result = 0;
	int sumW = 0;
	for(int i = 0;i<jimuVec.size();i++){
		if (jimuVec[i].w*7 >= sumW ) {
			result += 1;
			sumW += jimuVec[i].w;
		}
	}
	cout << result;
	system("pause");

}