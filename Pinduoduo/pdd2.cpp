/**
С����������һ���Լ���ׯ԰������ׯ԰����һ��С�ӣ���ϣ���ںӱ���һ�������� M �á�
С��ɹ��� N ��Ʒ�ֵ�����ÿ��Ʒ�ֵ������� Ai (����������ǡ��Ϊ M)��
������ϣ�������������ڵ�������ͬһƷ�ֵġ�С�������æ���һ������Ҫ�������������

��������:
��һ�а���һ�������� N����ʾ����Ʒ��������
�ڶ��а��� N ������������ i (1 <= i <= N) ������ʾ�� i ��Ʒ�ֵ�����������
���ݷ�Χ��
1 <= N <= 1000
1 <= M <= 2000


�������:
���һ�У����� M �����������ֱ��ʾ�� i ������Ʒ�ֱ�� (Ʒ�ֱ�Ŵ�1�� N)��
�����ڶ��ֿ��з�����������ֵ�����С�ķ����������������������ķ����������"-"��
ʾ��1
����
3
4 2 1
���
1 2 1 2 1 3 1

*/
/**
 ̰���㷨����ǰ�����ҵ�ǰ������������ΪҪ�ֵ���
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct tree {
	int no;
	int num;
	tree(int n, int n1) {
		no = n;
		num = n1;
	}
	bool operator <(const tree& rhs) {
		if (num < rhs.num)
			return true;
		else if (num == rhs.num)
			return no > rhs.no;
		else return false;
	}

};

int main() {
	int n,M=0;
	cin >> n;
	vector<int> T;
	
	int max = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		max = max < temp ? temp : max;
		M += temp;
		T.push_back(temp);
	}
	if (max - (M - max) > 1) {
		cout << '-';
		return 0;
	}

	for (int prev = -1, k = 0; M-- > 0; T[k]--, prev = k) {
		max = *max_element(T.begin(), T.end());
		
		for ( k = 0; k < n; k++) {
			if (k == prev || T[k] == 0) //�����֮ǰ�ֵ���һ��������������Ϊ0
				continue;
			if (max-(M-max) <=1 || max == T[k]) 
				break;
		}

		cout << k + 1;
		if (M == 0) cout << endl;
		else cout << " ";
	}
	
	system("pause");

}