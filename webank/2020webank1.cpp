/**
ĩβ����
ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 65536KB���������� 589824KB
��Ŀ������
С����֪�� n! �����һλ��Ϊ 0 �����֣����ܸ������� n! = n*(n-1)*(n-2)*....*3*2*1
����
һ��������n��n<=5000��

���
һλ���𰸣���ʾ���һλ��Ϊ0������


��������
7
�������
4

��ʾ
7��=5040 �����һλ��Ϊ0������Ϊ4
*/
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int *num = new int[n + 1];
	int res = 1, count = 0;
	for (int i = 1; i < n + 1; i++) {
		num[i] = i;
		while (num[i] % 5 == 0) {
			count++;
			num[i] /= 5;
		}

		while (num[i] % 2 == 0 && count>0) {
			count--;
			num[i] /= 2;
		}
	}
	for (int i = 2; i < n + 1; i++) {
		res *= num[i];
		while (res % 10 == 0)
			res /= 10;
		res = res % 10;
	}
	cout << res;

}