/**
�ֳ�һ����N��ʳ�ÿ����i�ݣ���ÿ��ֻ��һ��ʳ���ֻ��һ��ʳ�һ����Ҫô��Ҫô�򣬲���ͬʱ���У����M��Pʳ��ķ�������ʳ������е�������

���룺

��һ�У�������N��M��P���ֱ��ʾʳ������࣬������Ҫ���ʳ�

�ڶ��У�N��������ʾÿ��ʳ��ķ�����

������M�У�ÿһ��������������һ������ʾ�Ի���A��ʾ��B��ʾ�ԣ����ڶ�������ʾ������ʳ����в�����

�����

Pʳ�������

�������룺

3 4 2

5 3 1

B 1

A 2

A 2

A 3

���������

1

*/
#include<iostream>
using namespace std;
int main() {
	int N, M, P;
	cin >> N >> M >> P;
	
	int *A = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < M; i++) {
		char temp;
		cin >> temp;
		if (temp == 'A') {
			int tempI;
			cin >> tempI;
			A[tempI - 1] += 1;
		}
		else {
			int tempI;
			cin >> tempI;
			A[tempI - 1] -= 1;
		}
	}
	int left = A[P - 1];
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] > left)
			count += 1;
	}
	cout << count + 1;
	system("pause");
}