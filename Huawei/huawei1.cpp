/**
	整数反转求和

	题目描述
	编写一个reverseadd函数，实现两个数倒置后再求和的功能， 比如输入123，456就是求321+654，输出975。
	注意：输入100,200输出3,（自动去除开头的0）,超过范围输出-1

	输入描述
	函数原型：int reverseAdd(int a, int b)
	输入：
	输入的a、b参数均在有效取值范围[1,70000]区间的正整数

	输出描述
	通过函数返回值输出结果
	若输入的a或b参数超出了取值范围，则应输出-1
	否则应该按照要求输出数字反转后的和

	输入样例
	123 456

	输出样例
	975
*/

#include<climits>
#include<iostream>
using namespace std;
//反转数字
int reverseNum(int a) {
	int sum = 0;
	while (a != 0) {
		sum *= 10;
		sum += (a % 10);
		a /= 10;
	}
	return sum;
}


int reverseAdd(int a,int b) {
	if (a > 70000 || b > 70000 || a < 1 || b < 1)
		return -1;
	return reverseNum(a) + reverseNum(b);
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << reverseAdd(a, b);
	system("pause");
	return 0;
}
