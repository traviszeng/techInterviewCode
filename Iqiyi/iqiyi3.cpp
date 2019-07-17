/*
��Ŀ������
���ؾ��ڳ�������

�������������������ϣ�ÿ��������Ӧ�����ϵ�������a��b��
����֪�������������������ص�(�˵�����ص���������������ѡ�����ٸ�������

1 <= n <= 100

-999 <= a<b<=999

����������
��һ��һ������N
��������N��ÿ��N������a��b

���������
һ�����Ĵ�

����������
3
3 6 
1 3 
2 5

���������
2
*/

/**
��಻�غ���������
̰�Ĳ��ԣ�����b1<=b2<=b3���ķ�ʽ����Ȼ���ǰ��������ÿ���������Լ��뼯�ϵ����䣬�Ͱ������뼯�ϡ������ϴ����ļ��ϣ�
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct line{
	int left;
	int right;
	line(int l, int r) {
		left = l;
		right = r;
	}
	//����С��
	bool operator <(const line& rhs) {
		return right < rhs.right;
	}
};

int main(){
	int n;
	cin >> n;
	vector<line> lineVec;
	vector<line> resultVec;
	
	for (int i = 0; i < n; i++) {
		int ltemp, rtemp;
		cin >> ltemp >> rtemp;
		lineVec.push_back(line(ltemp, rtemp));
	}
	//�����ұߴ�С����
	sort(lineVec.begin(), lineVec.end());
	//��һ������
	resultVec.push_back(lineVec[0]);
	for (int i = 1; i < lineVec.size(); i++) {
		bool isOverlapped = false;
		for (int j = 0; j < resultVec.size(); j++) {
			if (resultVec[j].right > lineVec[i].left)
				isOverlapped = true;
		}
		if (!isOverlapped)
			resultVec.push_back(lineVec[i]);
	}
	cout << resultVec.size();
	system("pause");
}