/**
	�����ظ�����
	
	��Ŀ����
	����һ�������������������ظ������Ժ�����������
	
	��������
	��������ע�⿼�ǳ�����
	
	�������
	�����ظ������Ժ���������
	
	��������
	43223234
	
	�������
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