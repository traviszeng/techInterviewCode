/*
��Сֵ
ʱ�����ƣ�C/C++ 2�룬�������� 4��
�ռ����ƣ�C/C++ 262144K���������� 524288K
64bit IO Format: %lld
�����ʹ�ñ���IDE���룬�����������ƣ���������������沢���ԡ���ť���д����ύ��
��Ŀ����
ţţ���ȶ��ܳ���һ����ѧ�⣬ţţ�������֣�ϣ���ȶ������ҵ�һ��Ǹ����������Ҿ���С��
�ȶ��ܰ�������⽻�����㣬ϣ�����ܰ��������
��������:
һ����������

�������:
�����С�ġ�
ʾ��1�������ʾ���������ԣ���̨��������һ�㲻����ʾ��
����
����
12 18 100
���
����
7
˵��
�� a = 7, b = 0ʱ��, (n-a)(m-b) = 90 <= k = 100����ʱ a + b = 7����С�Ľ⡣
*/
#include<iostream>
#include<limits.h>
using namespace std;
int main() {
	long long  n, m, k;
	cin >> n >> m >> k;
	if (n*m <= k) {
		cout << 0;
		return 0;
	}
	long long  min = INT_MAX;
	if (n > m) {
		long long  a = 0;
		for (long long  b = 0; b <= m; b++) {
			if ((n)*(m - b) <= k && b < min) {
				min = a+b;
				break;
			}
		}
	}
	else {
		long long  b = 0;
		for (long long  a = 0; a <= n; a++) {
			if ((n-a)*(m) <= k && a < min) {
				min = a+b;
				break;
			}
		}
	}
	cout << min;
	system("pause");
}