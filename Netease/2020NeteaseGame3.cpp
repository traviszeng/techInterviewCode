/*
ʱ�����ƣ�C/C++ 1�룬�������� 2��
�ռ����ƣ�C/C++ 65536K���������� 131072K
64bit IO Format: %lld
�����޶���C++11(clang++ 3.9), C++14(g++5.4), Java(javac 1.8), C(clang 3.9)
�����ʹ�ñ���IDE���룬�����������ƣ���������������沢���ԡ���ť���д����ύ��
��Ŀ����
СA��ϲ����ĸN������Ϊ������N�����������˴�����һ��СA������һ��ȫ���ɴ�д��ĸ��ɵ��ַ�������������ı����2����д��ĸ��Ҳ�����ı����ֻ�ı�1����д��ĸ����ʹ���ַ����������������������N���ĳ���������ܰ�������

��������:
����ĵ�һ����һ��������T��0 < T <= 20������ʾ��T��������ݡ�����ÿһ���������ݰ���һ�д�д�ַ���S��0 < |S| <= 50000��|S|��ʾ�ַ������ȣ���

���ݷ�Χ��

20%�������У��ַ������Ȳ�����100��

70%�������У��ַ������Ȳ�����1000��

100%�������У��ַ������Ȳ�����50000��
�������:
����ÿһ��������������һ����������ʾ������������������N���ĳ��ȡ�
ʾ��1�������ʾ���������ԣ���̨��������һ�㲻����ʾ��
����

3
NNTN
NNNNGGNNNN
NGNNNNGNNNNNNNNSNNNN
���

4
10
18
*/

#include<iostream>
#include<string>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int ppMax = 0, preMax = 0, cur = 0;
		int numOfChange = 2;
		int maxSize = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'N')
				cur += 1;
			else {
				if (numOfChange > 0)
					numOfChange -= 1;
				ppMax = preMax;
				preMax = cur;
				cur = 0;
					
			}
			int temp = ppMax + preMax + cur + 2 - numOfChange;
			maxSize = maxSize > temp ? maxSize : temp;

		}
		cout << maxSize<<endl;
		
	}
	system("pause");
}