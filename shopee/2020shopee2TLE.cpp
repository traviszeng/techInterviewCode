/**
����һ����n��������������A��һ������sum,��ѡ������A�в������ֺ�Ϊsum�ķ�������
������ѡȡ������һ�����ֵ��±겻һ��,���Ǿ���Ϊ�ǲ�ͬ����ɷ�����
��������:
����Ϊ����:

��һ��Ϊ����������n(1 �� n �� 1000)��sum(1 �� sum �� 1000)

�ڶ���Ϊn��������A[i](32λ����)���Կո������
�������:
�������ķ�����
ʾ��1
����
5 15
5 5 10 2 3
���
4

*/
#include<iostream>
using namespace std;


//TLE
int getNumUsingINumber(int *a, int i, int start, int sum,int aNum) {
	int num = 0;
	if (i == 0) {
		if (sum == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}

	for (int j = start; j <= aNum - i; j++) {
		if (a[j] <= sum) {
			num += getNumUsingINumber(a, i - 1, j + 1, sum - a[j],aNum);
		}
	}

	return num;
}



int getNum(int *a, int sum,int aNum) {
	int count = 0;
	for (int i = 0; i <= aNum; i++) {
		count += getNumUsingINumber(a, i, 0, sum,aNum);
	}
	return count;
}


int main() {
	int n, sum;
	cin >> n >> sum;
	int *num = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	cout<<getNum(num, sum, n);
	system("pause");

}