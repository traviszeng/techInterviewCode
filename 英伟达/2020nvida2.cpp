/**

学英语
时间限制：C/C++ 1秒，其他语言 2秒
空间限制：C/C++ 32768K，其他语言 65536K
64bit IO Format: %lld
本题可使用本地IDE编码，不做跳出限制，编码后请点击“保存并调试”按钮进行代码提交。
题目描述
Jessi初学英语，为了快速读出一串数字，编写程序将数字转换成英文：

如22：twenty two，123：one hundred and twenty three。



说明：

数字为正整数，长度不超过九位，不考虑小数，转化结果为英文小写；

输出格式为twenty two；

非法数据请返回“error”；

关键字提示：and，billion，million，thousand，hundred

方法原型：public static String parse(long num)


输入描述:
输入一个long型整数

输出描述:
输出相应的英文写法

示例1输入输出示例仅供调试，后台判题数据一般不包含示例
输入
复制
2356
输出
复制
two thousand three hundred and fifty six
*/
#include<iostream>
#include<string>
using namespace std;


const string dictO[] = {
	"zero","one","two","three","four","five","six","seven","eight","nine","ten",
	"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"
};

const string dictT[] = {
	"zero","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"
};

const string dictH[] = {
	"","thousand","million","billion","trillion","thousand trillion","million trillion","billion trillion"
};

string parse(long num) {
	string s = "";
	int v = num % 100;
	if (v <= 19)
		s = dictO[v];
	else if (v > 19 && v % 10 == 0) {
		s = dictT[v / 10];
	}

	else{
		if (v / 10) {
			s = dictT[v / 10] + " ";
		}
		else {
			s = "";
		}
		s = s + dictO[v % 10];
	}
	s = ((num / 100) ? dictO[num / 100] + " hundred and " : "") + s;
	return s;
}


int main() {
	string res = "";
	
	long long num = 0;
	while (cin >> num) {
		int i = 0;
		do {
			if (i != 0) {
				res = dictH[i] + " " + res;
			}
			res = parse(num % 1000) + " " + res;
			num = num / 1000;
			++i;
		} while (num != 0);
		cout << res;
	}
	system("pause");
}