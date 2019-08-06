/*
Ӧ����ô����
ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 65536KB���������� 589824KB
��Ŀ������
СW�ǳ�ϲ������ʳ����������ȥ��ʳ���ﹺ���۵���ʳ�ԣ�������Ϊ�˿����Լ������أ���˻������Լ�����ʳ�Ŀ�����ĳ����ֵ���ڡ�

����СW��һ���ر�İ��ã�������ĳЩ��ʳ�ر��ϲ�������һ����Щ��ʳ��ϲ���ɶ��������򡣶�����ʳA����ʳB�����СW����ʳA��ϲ���̶ȴ��ڶ���ʳB��ϲ���̶ȣ���ôÿ������ʳ��ʱ��һ����ȷ��A����Ŀ��B�ࡣ

������ʳ������N����ʳ������ÿ����ʳ����ȡ����ģ���СWÿ�ζ���պû������еĿ�������ôСWȥȡ��ʳ��ʱ��Ӧ���ж����ֿ��ܵ�ȡ���أ�

����
�����������������ݣ�ÿ������:

��һ�У�����ʳ�Ŀ��� V (V < 1000) �� ���е���ʳ������Ŀ N (N < 200)��

�ڶ��У��� i ����������ʾ�� i ����ʳ�ļ۸� c_i (c_i < 1000)��

�����У��ر�ϲ������ʳ�������� M (2 <= M <= N)

�����У����ն� M ����ʳ��ϲ���̶ȴӸߵ������򣬵� i ����ʳ��ϲ���̶Ȼ���ڵ� i + 1 �֣���֤�����γɻ�

���
����ÿ���������:

���һ������ans����ʾ������СW������ƫ�õ�����£����һ������п������ж��ٿ��ܷ�����

������ans_i���ܴܺ�������ս�� ans_i % 10000007��


��������
5 2
1 2
2
2 1
�������
1

��ʾ
����һ�ַ�����(1,2)

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	int p;//�۸�
	int l;//ϲ���̶�
};
bool cmp(const node &a, const node &b)
{
	return a.l>b.l;
}
void dfs(vector<node>& c, vector<int>& times, int &sum, int v, long long &count, int k)
{
	if (sum>v) return;
	if (sum == v)
	{
		count++;
		return;
	}
	for (int i = k; i<c.size(); i++)
	{
		if (i != 0 && times[i] + 1 >= times[i - 1]) continue;//�����֮ǰ��ϲ���Ķ���
		times[i]++;
		sum += c[i].p;
		dfs(c, times, sum, v, count, i);
		sum -= c[i].p;
		times[i]--;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	int v, n;
	while (cin >> v >> n)
	{
		vector<node> c(n);
		for (int i = 0; i<n; i++)
		{
			cin >> c[i].p;
			c[i].l = 0;
		}
		int m;
		cin >> m;
		int idx;
		vector<int> times(n, 0);//ѡ�����
		for (int i = 0; i<m; i++)
		{
			cin >> idx;
			c[idx].l = m - i;//ϲ���̶�
		}
		sort(c.begin(), c.end(), cmp);
		long long count = 0;
		int sum = 0;
		dfs(c, times, sum, v, count, 0);
		count = count % 10000007;
		cout << count << endl;
	}
}