/**
定义一个str能整除str1，即str1=str+str+...+str
求两个string的最长能整除的子字符串

*/

#include<iostream>
#include<string>
using namespace std;


int main() {
	string str1, str2;
	cin >> str1 >> str2;
	string basic = str1.length() > str2.length() ? str2 : str1;
	if (str1.length() % basic.length() == 0 && str2.length() % basic.length() == 0)
	{
		cout << basic;
		return 0;
	}

	int maxYue = 1;
	int i = 1;
	while (maxYue < basic.length()) {

		if (str1.length() % maxYue == 0 && str2.length() % maxYue == 0) {
			i = maxYue;
		}
		maxYue++;
	}
	maxYue = i;

	string substr = basic[0]+"";
	substr += basic[0];
	int index = 1;
	while (str1.find(substr + basic[index]) != string::npos && 
		str2.find(substr + basic[index]) != string::npos && substr.length()<maxYue) {
		substr += basic[index];
		index++;		
	}
	cout << substr << endl;
	system("pause");
}