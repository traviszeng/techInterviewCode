/**
����2020-10000֮�������ĸ�����
ʱ�����ƣ�C/C++ 1�룬�������� 2��
�ռ����ƣ�C/C++ 32768K���������� 65536K
64bit IO Format: %lld
�����޶���C++11(clang++ 3.9), C++14(g++5.4), C(clang 3.9), Python(2.7.3), Python3(3.5.2), pypy2(pypy2.7.13), pypy3(pypy3.6.1), C#(mcs 5.20)
�����ʹ�ñ���IDE���룬�����������ƣ���������������沢���ԡ���ť���д����ύ��
��Ŀ����

һ������1����Ȼ��������1���������⣬���ܱ�������Ȼ�����������������������дPython���룬����2020-10000֮�������ĸ�����

��������:
No input
�������:
����2020-10000֮�������ĸ�����
*/

#include<iostream>
using namespace std;
int main() {
	bool* isSu = new bool[10001];
	for (int i = 0; i <= 10000; i++) isSu[i] = true;
	for (int i = 2; i <= 10000 ; i++) {
		int j = 2; 
		while (i*j <= 10000) {
			isSu[i*j] = false;
			j++;
		}
	}
	int count = 0;
	for (int i = 2020; i < 10001; i++) {
		if (isSu[i]) count++;
	}
	cout << count;
	system("pause");
}