/**


С��Ŀǰ����һ�ݱ�ҵ���еĹ滮������ӱ����������ֱ�ȥ���ɸ����У�Ȼ���ٻص�������ÿ������֮���������������ÿ������ֻȥһ�Ρ�
���ھ������ޣ�ϣ���ܹ�ͨ��������·�߰��ž����ܵ�ʡһЩ·�ϵĻ���������һ����к�ÿ�Գ���֮��Ļ�Ʊ�ļ�Ǯ���ҵ�ÿ������ֻ����һ�β�����������С���ѻ�����

��������:
���и���n��1<n��20������������

���м�ĳ�Ʊ��Ǯ n��n�еľ��� m[n][n]


�������:
��С���ѻ��� s
ʾ��1
����
4
0 2 6 5
2 0 4 4
6 4 0 2
5 4 2 0
���
13
˵��
�� 4 �����У����� 1 �ͳ��� 1 �ĳ���Ϊ0������ 1 �ͳ��� 2 ֮��ĳ���Ϊ 2��
���� 1 �ͳ��� 3 ֮��ĳ���Ϊ 6������ 1 �ͳ��� 4 ֮��ĳ���Ϊ 5���������ơ�
����������������֮����е���Ʊ�ɹ�����Ʊ����1000Ԫ���ڣ����迼�Ǽ��������

*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
	int n;
	cin >> n;
	vector<vector<int>> cities;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			temp.push_back(t);
		}
		cities.push_back(temp);
	}
	//�����н��ж����Ʊ��� ��������4������ ��1010��ʾѡȡ�ڶ����͵��ĸ�����
	//dp[i][j]��ʾ������i�����е����г�������j��β��·����Сֵ
	//״̬ת�Ʒ���Ϊdp[i][j] = min(dp[i][k]+cities[k][j],dp[i][j])   ����k��i�����е�һ������
	int m = 1 << n; //�����Ƶ�״̬����2^n��
	int **dp = new int*[m+2];
	for (int i = 0; i < m; i++)
	{
		dp[i] = new int[n + 2];
		for (int j = 0; j < n; j++) {
			dp[i][j] = INF;
		}
	}

	//�ӵ�һ�����е���һ�����д���Ϊ0
	dp[1][0] = 0;
	int ans = INF;

	//�̶��ӵ�һ�����г���
	for (int i = 1; i < m; i++) { //i��ʾ���п��ܵĳ��м���
		for (int j = 1; j < n; j++) { //jΪ�����б� ��һ�������Ѿ��߹�
			if (i & (1 << j)) //˵��j���Ѿ��ڼ���i��
				continue;

			if (!(i & 1))//�����һ������û����i��
				continue;
			for (int k = 0; k < n; k++) {//��i�����е�ÿ�����г��ԣ��ҵ���С��
				if (i & (1 << k)) {//˵��k�ڼ�����
					dp[(1 << j) | i][j] = min(dp[(1 << j) | i][j], dp[i][k] + cities[k][j]);
				
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
		ans = min(ans, dp[m - 1][i] + cities[i][0]);  //ÿ����Ҫ�ص�ԭ��
	
	
	cout << ans << endl;
	
	//cout << m;
	system("pause");
}