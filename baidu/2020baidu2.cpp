/**
�ȶ��ܵĹ���
ʱ�����ƣ�C/C++ 2�룬�������� 4��
�ռ����ƣ�C/C++ 262144K���������� 524288K
64bit IO Format: %lld
�����ʹ�ñ���IDE���룬�����������ƣ���������������沢���ԡ���ť���д����ύ��
��Ŀ����
�ϰ���ȶ��ܷ����˸��������ڸ�������Ҫ�ķ�a_i��λʱ�䣬ÿ�����������ϰ����������ʱ��b_iǰ��ɡ�
�ȶ��ܴ�ʱ�̿�ʼ��������ͬһʱ��ȶ�������ֻ����һ���������ȶ�����֪�����Ƿ��ܰ����й���������أ�
��������:
��һ��һ������ʾ����������
ÿ�����ݵ�һ��һ������
��������ÿ����������ʾa_i,b_i��
�������:
ÿ���������һ�У�����ȶ�����������Ĺ������"Yes"��Ȼ�����No����
ʾ��1�������ʾ���������ԣ���̨��������һ�㲻����ʾ��
����
����
1
5
2 4
1 9
1 8
4 9
3 12
���
����
Yes
˵��
��ǰ����������ÿ������������ɡ�
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int check(int n) {
	vector<pair<int, int>> task;
	for (int j = 0; j < n; j++) {
		int a, b;
		cin >> a >> b;
		task.push_back(make_pair(a, b));
	}
	sort(task.begin(), task.end(), cmp);
	int curTime = 0;
	for (int j = 0; j < n; j++) {
		curTime = curTime + task[j].first;
		if (curTime > task[j].second) {
			cout << "No"<<endl;
			return 0;
		}
	}
	cout << "Yes"<<endl;
	return 0;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		check(n);
	}
	system("pause");
}