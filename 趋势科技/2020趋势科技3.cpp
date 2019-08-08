/**
题目描述
请实现一个非标准霍夫曼编码器，与标准霍夫曼编码器相比，该编码器需要使用3进制数进行编码，并且需要保持霍夫曼编码器编码后总长最短的特性。使用该编码器对给定的ASCII字符串输入进行编码，输出字符串经该编码器编码后所使用的3进制数的位数。
参考资料:标准霍夫曼编码的具体方法：先按出现的概率大小排队，把两个最小的概率相加，作为新的概率和剩余的概率重新排队，再把最小的两个概率相加，再重新排队，直到最后变成1。每次相 加时都将“0”和“1”赋与相加的两个概率，读出时由该符号开始一直走到最后的“1”， 将路线上所遇到的“0”和“1”按最低位到最高位的顺序排好，就是该符号的赫夫曼编码。下面是一个示意图。


输入描述:
需要用非标准霍夫曼编码器来编码的ASCII字符串
输出描述:
字符串经该编码器编码后所使用的3进制数的总的位数
示例1输入输出示例仅供调试，后台判题数据一般不包含示例
输入

adsfaerwkeljfasodfjoqweirfaskdh
输出

74
*/

#include <iostream>
#include <string>
#include<map>

using namespace std;

int calEncodeLen(string &str)
{
	int len = 0;
	// please write your code here.
	return len;
}



int main(void) {
	string mystr;
	cin >> mystr;

	int len = calEncodeLen(mystr);

	cout << a3 << endl;
	return 0;
}