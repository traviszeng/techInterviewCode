/**
问题描述
小Q在学习许多排序算法之后灵机一动决定自己发明一种排序算法，小Q希望能将n个不同的数排序为升序。小Q发明的排序算法在每轮允许两种操作：
1、 将当前序列中前n-1个数排为升序
2、 将当前序列中后n-1个数排为升序
小Q可以任意次使用上述两种操作，小Q现在想考考你最少需要几次上述操作可以让序列变为升序。
输入描述
输入包括两行，第一行包括一个正整数n(3≤n≤10^5)，表示数字的个数
第二行包括n个正整数ai，即需要排序的数字，保证数字各不相同。
输出描述
输出一个正整数，表示最少需要的操作次数
输入样例
6
4 3 1 6 2 5
输出样例
2

*/


#include<iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	int * a = new int[num];
	cin >> a[0];
	bool needSort = false;
	int max = a[0];
	int min = max;
	for (int i = 1; i < num; i++)
	{
		cin >> a[i];
		//判断是否已经排好序
		if (a[i] < a[i - 1])
			needSort = true;
		if (a[i] > max) 
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	//如果已经能够排好序，则返回0
	if (!needSort)
		cout<<0;

	//判断最后一个数字大小和最大值的关系
	//如果最后一个为最大值，则只需要排一次
	if (max == a[num - 1])
		cout<<1;

	//如果最后一个数字为最小值则至少需要三次
	if (min == a[num - 1])
		cout<<3;
	else cout<<2;
	
	return 0;
}