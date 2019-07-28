/**

���|30��] ���ľ
ʱ�����ƣ�C/C++ 1�룬�������� 2��
�ռ����ƣ�C/C++ 32768K���������� 65536K
64bit IO Format: %lld
�����ʹ�ñ���IDE���룬�����������ƣ���������������沢���ԡ���ť���д����ύ��
��Ŀ����
��༦����������ľ��Ϸ���� N ���������ľ��ÿ����ľ�ĸ߶���1������Ϊ Li ������Ϊ Wi ��
���ڶ�༦������Ҫ����Щ��ľ��һ���߸ߵĽ��������������������ÿһ�������ҽ���һ���ľ��ɣ�ͬʱÿһ��Ļ�ľ�߳����ϸ�������·��Ļ�ľС��
�ڶ�γ���֮�󣬶�༦��������ÿ���ľֻ�ܳ�������������7����������������7�����أ���Ľ���������˱�ò��ȶ���������˵��������ÿһ���ľ�������Ϸ��Ļ�ľ����֮�ͱ���С�ڵ��������ص�7����
��༦�����������������һ����߿��Դ�һ����ߵĽ�������
���ݷ�Χ��
1 <= N <= 100
1 <= Li <= 1000
1 <= Wi <= 1000
��������:
��һ�а���1�������� N ����ʾ��ľ��������
�ڶ��а��� N ������������ i ������ʾ�� i ����ľ�ĳ��� Li ��
�����а��� N ������������ i ������ʾ�� i ����ľ������ Wi ��
�������:
���ռһ�У�������һ����������ʾ���Դ���Ľ���������߸߶ȡ�
ʾ��1�������ʾ���������ԣ���̨��������һ�㲻����ʾ��
����

10
1 2 3 4 5 6 7 8 9 10
1 1 1 1 1 1 1 1 1 10
���

9
*/


#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct jimu {
	int w;
	int l;
	jimu(int ll, int ww) {
		l = ll;
		w = ww;
	}
	friend istream &operator>>(istream &in, jimu &x) {
		in >> x.l >> x.w;
		return in;
	}

	bool operator<(const jimu &s)  const{
		if (l == s.l)
			return w < s.w;
		return l < s.l;
	}
};


int main() {
	int n;
	cin >> n;
	int *l = new int[n];
	int *w = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	vector<jimu> jimuVec;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		jimuVec.push_back(jimu(l[i], w[i]));
	}
	sort(jimuVec.begin(), jimuVec.end());
	int result = 0;
	int sumW = 0;
	for(int i = 0;i<jimuVec.size();i++){
		if (jimuVec[i].w*7 >= sumW ) {
			result += 1;
			sumW += jimuVec[i].w;
		}
	}
	cout << result;
	system("pause");

}