/**
ʱ�����ƣ�1��

�ռ����ƣ�32768K

shopee�İ칫�ҷǳ���СϺͬѧ��λ�����������Ͻǣ�������ȴ�����½ǣ����԰�����λ�ó���Ϊһ�������ſڵ�����Ϊ0��0����СϺͬѧ�ܴ�����ÿ��ֻ���ϣ����������ߣ���Ϊ���������׽ӽ�Ŀ�ĵأ�����СϺͬѧ�������Լ���boss�ǿ����Լ�������������ǰ��û�����߳ٵ������֡��������о�һ���������ͨ��boss�ǵ�λ�ã��������ж������߷���


��������:
��һ�� x,y,n (0<x<=30, 0<y<=30, 0<=n<= 20) ��ʾx,yСϺ����λ����,n ��ʾboss�������� n <= 20��

��������n��, ��ʾboss�ǵ�����(0<xi<= x, 0<yi<=y�������СϺλ���غ�)

x1, y1

x2, y2

����

xn, yn

�������:
���СϺ�ж������߷�

��������1:
3 3 2
1 1
2 2

�������1:
4
*/

/**
	��̬�滮 dp[i][j] = dp[i-1][j]+dp[i][j-1]
	�����boss��dp[i][j]Ϊ0
*/

#include<iostream>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	int bossNum;
	cin >> bossNum;
	long long int dp[31][31] = { 0 };
	for (int i = 0; i < bossNum; i++) {
		int x, y;
		cin >> x >> y;
		dp[x][y] = -1;
	}

	for (int i = 0; i <= x; i++)
		dp[i][0] = 1;
	for (int j = 0; j <= y; j++)
		dp[0][j] = 1;
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			if (dp[i][j] == -1) continue;
			if (dp[i - 1][j] != -1) dp[i][j] += dp[i - 1][j];
			if (dp[i][j - 1] != -1) dp[i][j] += dp[i][j - 1];
		}
	}
	cout << dp[x][y] << endl;
	system("pause");
	return 0;

	


}