/*/**[编程|25分] 骰子期望
时间限制：C/C++ 1秒，其他语言 2秒
空间限制：C/C++ 32768K，其他语言 65536K
64bit IO Format: %lld
本题可使用本地IDE编码，不做跳出限制，编码后请点击“保存并调试”按钮进行代码提交。
题目描述
扔n个骰子，第i个骰子有可能投掷出Xi种等概率的不同的结果，数字从1到Xi。所有骰子的结果的最大值将作为最终结果。求最终结果的期望。
输入描述:
第一行一个整数n，表示有n个骰子。（1 <= n <= 50）
第二行n个整数，表示每个骰子的结果数Xi。(2 <= Xi <= 50)
输出描述:
输出最终结果的期望，保留两位小数。
示例1输入输出示例仅供调试，后台判题数据一般不包含示例
输入
复制
2
2 2
输出
复制
1.75*/*/

#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int n;
	cin >> n;
	int *a = new int[n];

	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > max) max = a[i];
	}

	float *proba = new float[max + 1];
	//proba[1] = 1;
	proba[0] = 0;
	float result = 0;
	for (int i = 1; i < max + 1; i++) {
		proba[i] = 1;
		for (int j = 0; j < n; j++){
			if(a[j]>=i)
				proba[i] *= (float)i / a[j];
		}

		for (int k = i-1; k >= 1; k--) {
			proba[i] -= proba[k];
		}
		cout << proba[i] << endl;
		result += i * proba[i];
	}
	cout <<setiosflags(ios::fixed)<<setprecision(2)<< result;


	system("pause");
}