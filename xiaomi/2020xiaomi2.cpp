/**
�����ƶ�
ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 65536KB���������� 589824KB
��Ŀ������
����һ�����У�ÿһ���ƶ����Խ�����ĳ�����ƶ���ĳ��λ���ϣ��ƶ���κ��γ��µ����С�������������������֮��Ĳ�ľ���ֵΪ���ƶ����롱�����������ƶ�������ܺ�Ϊ�����ƶ����롱��ϣ����������ٵ��ƶ�������ʹ�������еġ����ƶ����롱��С�� ����ԭ����Ϊ[4,2,7,6]�����ƶ�����Ϊ2+5+1=8����6�ƶ���7֮ǰ������[4,2,6,7]�����ƶ�������2+4+1=7��

��Ҫ��дһ������������Ϊһ��int�����ʾ�������ݣ����Ϊһ��int���֣���ʾ��С�ƶ�����

����
��һ������Ϊ�����С��Ȼ��������������Ԫ�أ�������[4, 2, 7, 6]

���
���ƶ�������С������֮һΪ[2,4,6,7]

�����ƶ�������2


��������
4
4
2
7
6
�������
2
*/

#include <iostream>
#include <vector>
#include <numeric>
#include<algorithm>
#include <limits>

using namespace std;


/*������������������ʵ����ĿҪ��Ĺ���
��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^
******************************��ʼд����******************************/
int solution(vector < int > arr) {
	vector<int> temp;

	for (int i = 0; i < arr.size(); i++) temp.push_back(arr[i]);
	sort(temp.begin(), temp.end());
	int count = 0; int j = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == temp[j]) {
			++count;
			++j;
		}
	}
	return arr.size() - count;

}
/******************************����д����******************************/


int main() {
	int res;

	int _arr_size = 0;
	cin >> _arr_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	vector<int> _arr;
	int _arr_item;
	for (int _arr_i = 0; _arr_i<_arr_size; _arr_i++) {
		cin >> _arr_item;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		_arr.push_back(_arr_item);
	}



	res = solution(_arr);
	cout << res << endl;

	return 0;

}
