/**
	消除重复数字
	
	题目描述
	给定一个正整数，给出消除重复数字以后最大的整数。
	
	输入描述
	正整数，注意考虑长整形
	
	输出描述
	消除重复数字以后的最大整数
	
	输入样例
	43223234
	
	输出样例
	432

*/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string num;
	cin >> num;
	sort(num.begin(), num.end(), greater<char>());
	
	string result="";
	for (int i = 0; i < num.size(); i++)
		if (result.find(num[i]) == string::npos)
			result += num[i];
	cout << result;
	system("pause");

}