/**

��N��ʳ��ų�һ�ţ�ѡ�����������ʳ�������ѡ�����ڵ�ʳ�һ��Ҳ��ѡҲ��һ��ѡ��ķ�����
���ж�����ѡ��ķ�����
���룺
һ������n
�����
һ����������ʾ��
�������룺
3
���������
5

*/


/**
	dp[i]��ʾ1-i��ʳ�ﹲ�ж�����ѡ��,
	����i��ʳ�ﱻѡ����i-1����ѡ��Ϊdp[i-1]
	����i�ֲ���ѡ����Ϊdp[i-2]
	����dp[i] = dp[i-1]+dp[i-2]
*/
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int *dp = new int[n + 1];
	dp[0] = 1;
	dp[1] = 2;
	for (int i = 2; i < n + 1; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];
	system("pause");


}