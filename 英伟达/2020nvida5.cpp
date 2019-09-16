/**
矩阵乘法
时间限制：C/C++ 1秒，其他语言 2秒
空间限制：C/C++ 32768K，其他语言 65536K
64bit IO Format: %lld
本题可使用本地IDE编码，不做跳出限制，编码后请点击“保存并调试”按钮进行代码提交。
题目描述
如果A是个x行y列的矩阵，B是个y行z列的矩阵，把A和B相乘，其结果将是另一个x行z列的矩阵C。这个矩阵的每个元素是由下面的公式决定的



输入描述:
输入包含多组数据，每组数据包含：

第一行包含一个正整数x，代表第一个矩阵的行数

第二行包含一个正整数y，代表第一个矩阵的列数和第二个矩阵的行数

第三行包含一个正整数z，代表第二个矩阵的列数

之后x行，每行y个整数，代表第一个矩阵的值

之后y行，每行z个整数，代表第二个矩阵的值



输出描述:
对于每组输入数据，输出x行，每行z个整数，代表两个矩阵相乘的结果
示例1输入输出示例仅供调试，后台判题数据一般不包含示例
输入
复制
2
2
2
3 8
8 0
9 0
18 9
输出
复制
171 72
72 0
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int x, y, z;
	cin >> x >> y >> z;
	vector<vector<int>> a;
	vector<vector<int>> b;
	for (int i = 0; i < x; i++) {
		vector<int> temp;
		for (int j = 0; j < y; j++) {
			int tem;
			cin >> tem;
			temp.push_back(tem);
		}
		a.push_back(temp);
	}

	for (int i = 0; i < y; i++) {
		vector<int> temp;
		for (int j = 0; j < z; j++) {
			int tem;
			cin >> tem;
			temp.push_back(tem);
		}
		b.push_back(temp);
	}

	vector<vector<int>> c;
	for (int i = 0; i < x; i++) {
		
		
		vector<int> temp;
		for (int j = 0; j < z; j++) {
			int tem=0;
			for (int k = 0; k < y; k++) {
				tem += a[i][k] * b[k][j];
			}
			temp.push_back(tem);
		}
		c.push_back(temp);
	}

	for (int i = 0; i < x; i++) {
		//vector<int> temp;
		for (int j = 0; j < z; j++) {
			cout << c[i][j]<<" ";
		}
		cout << endl;
	}
}