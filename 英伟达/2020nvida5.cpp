/**
����˷�
ʱ�����ƣ�C/C++ 1�룬�������� 2��
�ռ����ƣ�C/C++ 32768K���������� 65536K
64bit IO Format: %lld
�����ʹ�ñ���IDE���룬�����������ƣ���������������沢���ԡ���ť���д����ύ��
��Ŀ����
���A�Ǹ�x��y�еľ���B�Ǹ�y��z�еľ��󣬰�A��B��ˣ�����������һ��x��z�еľ���C����������ÿ��Ԫ����������Ĺ�ʽ������



��������:
��������������ݣ�ÿ�����ݰ�����

��һ�а���һ��������x�������һ�����������

�ڶ��а���һ��������y�������һ������������͵ڶ������������

�����а���һ��������z������ڶ������������

֮��x�У�ÿ��y�������������һ�������ֵ

֮��y�У�ÿ��z������������ڶ��������ֵ



�������:
����ÿ���������ݣ����x�У�ÿ��z����������������������˵Ľ��
ʾ��1�������ʾ���������ԣ���̨��������һ�㲻����ʾ��
����
����
2
2
2
3 8
8 0
9 0
18 9
���
����
171 72
72 0
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int x, y, z;
	cin >> x >> y >> z;
	vector<vector<int>> a;
	vector<vector<int>> b;
	for (int i = 0; i < x; i++) {
		vector<int> temp;
		for (int j = 0; j < y; j++) {
			int tem;
			cin >> tem;
			temp.push_back(tem);
		}
		a.push_back(temp);
	}

	for (int i = 0; i < y; i++) {
		vector<int> temp;
		for (int j = 0; j < z; j++) {
			int tem;
			cin >> tem;
			temp.push_back(tem);
		}
		b.push_back(temp);
	}

	vector<vector<int>> c;
	for (int i = 0; i < x; i++) {
		
		
		vector<int> temp;
		for (int j = 0; j < z; j++) {
			int tem=0;
			for (int k = 0; k < y; k++) {
				tem += a[i][k] * b[k][j];
			}
			temp.push_back(tem);
		}
		c.push_back(temp);
	}

	for (int i = 0; i < x; i++) {
		//vector<int> temp;
		for (int j = 0; j < z; j++) {
			cout << c[i][j]<<" ";
		}
		cout << endl;
	}
}