/**
请编程实现求两个超长非负数之和 （限定使用C/C++或Java，不可使用类似BigDecimal等类库)。
要求
• 不损失精度
• 首尾均不出现无意义的0
• 不出现无意义的小数点 (比如 1.00 应该输出1）
• 不得使用除字符操作外的函数
输入描述:
输入为两个非负数，每个数满足下面要求
•    仅包含0-9的数字，0或1个小数点“.”。
•    长度不大于200
•    不需判错
输出描述:
输出为两数之和
示例1输入输出示例仅供调试，后台判题数据一般不包含示例
输入

1234567890123456789012345678901234567890.1234567890123456789012345678901234567890
1000000000100000000010000000001000000000.1000000000100000000010000000001000000000
输出

2234567890223456789022345678902234567890.223456789022345678902234567890223456789
*/

#include <iostream>
#include <string>

using namespace std;

//整数相加
string sum(string str1Zheng, string str2Zheng, string str1xiao, string str2xiao)
{
	
	if (str2Zheng.size()<str2xiao.size())
	{
		string strTemp = str2Zheng;
		str2Zheng = str2xiao;
		str2xiao = strTemp;
	}

	for (int i = str2xiao.size(); i<str2Zheng.size(); ++i)
		str2xiao += '0';

	reverse(str2Zheng.begin(), str2Zheng.end());
	reverse(str2xiao.begin(), str2xiao.end());
	
	string strRes2(str2Zheng.size(), '0');
	int carry = 0;
	for (int i = 0; i != str2Zheng.size(); ++i)
	{
		int a = str2xiao[i] - '0', b = str2Zheng[i] - '0';
		a = a + b + carry;
		carry = a / 10;
		strRes2[i] = (a % 10) + '0';
	}
	
	reverse(strRes2.begin(), strRes2.end());



	if (str1Zheng.size()<str1xiao.size())
	{
		string strTemp = str1Zheng;
		str1Zheng = str1xiao;
		str1xiao = strTemp;
	}

	reverse(str1Zheng.begin(), str1Zheng.end());
	reverse(str1xiao.begin(), str1xiao.end());


	string strRes1(str1Zheng.size(), '0');
	for (int i = 0; i != str1xiao.size(); ++i)
	{
		int a = str1xiao[i] - '0', b = str1Zheng[i] - '0';
		a = a + b + carry;
		carry = a / 10;
		strRes1[i] = (a % 10) + '0';
	}
	for (int i = str1xiao.size(); i != str1Zheng.size(); ++i)
	{
		int b = str1Zheng[i] - '0';
		b += carry;
		carry = b / 10;
		strRes1[i] = b % 10 + '0';
	}
	if (carry)
	{
		strRes1 += (carry + '0');
	}
	//反转回来
	reverse(strRes1.begin(), strRes1.end());


	//合并整数部分和小数部分
	string strRes = strRes1 + '.' + strRes2;
	return strRes;
}

string add(string &a1, string &a2)
{
	// please write your code here.
	int a1index = a1.find('.');
	int a2index = a2.find('.');
	if (a1index == string::npos && a2index != string::npos){
		string a = a2.substr(0, a2index);
		string b = a2.substr(a2index + 1);
		return sum(a1, "", a, b);

	}
	else if (a2index == string::npos && a1index != string::npos) {
		string a = a1.substr(0, a1index);
		string b = a1.substr(a1index + 1);
		return sum(a2, "", a, b);

	}
	else if (a1index == string::npos && a2index == string::npos) {
		return sum(a1, "", a2, "");
	}
	else {
		string a = a1.substr(0, a1index);
		string b = a1.substr(a1index + 1);
		string c = a2.substr(0, a2index);
		string d = a2.substr(a2index + 1);

		return sum(c, d, a, b);
	}
}


// please don't modify any code below.
int main(void) {
	string a1, a2, a3;
	cin >> a1 >> a2;
	a3 = add(a1, a2);
	cout << a3 << endl;
	system("pause");
	return 0;
}