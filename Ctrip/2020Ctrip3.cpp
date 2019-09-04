/**
�������
ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 65536KB���������� 589824KB
��Ŀ������
��m���ڵ�ķֲ�ʽ����ϵͳ�У���һ��������Ҫִ�У�ÿ��������Ҫ��ʱ����array[i]��ÿ���ڵ�ͬһʱ��ֻ��ִ��һ������ÿ���ڵ�ֻ��ִ����������������i,i+1,i+2,���ǲ���ִ��i,i+2������������ɵ����ʱ��

����
�������ݰ�������

��һ�У��ո�ָ�����������m��n���ֱ��ʾ�ڵ�������������(m>0,n>=0)

�ڶ��У��ո�ָ������������У���ʾÿ��������Ҫ��ʱ��

���
һ����������ʾ������ʱ��


��������
3 5
1 5 3 4 2
�������
6

��ʾ
��һ���ڵ�ִ�У�����1������2����ʱ=1+5=6
�ڶ����ڵ�ִ�У�����3����ʱ=3
�������ڵ�ִ�У�����4������5����ʱ=4+2=6
���ԣ�����̺�ʱ=6
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*������������������ʵ����ĿҪ��Ĺ���
��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^
******************************��ʼд����******************************/
int ans = 100000;


int schedule(int m, vector<int> array) {
	int sum = 0;
	for (int i = 0; i < array.size(); i++) {
		sum += array[i];
	}

	int average = sum / m;
	int min = average, max = sum;
	while (min < max) {
		int mid = (min + max) / 2;
		if (isSatisfy(array, m, mid)) {
			max = mid;
		}
		else {
			min = mid+1;
		}
	}
	return min;
}

bool isSatisfy(vector<int> array, int m, int t) {
	int c = t;
	for (int i = 0; i < array.size(); i++) {
		if (c >= array[i]) {
			c -= array[i];
		}
		else {
			m--;
			c = t;
			if (c < array[i]) {
				return false;
			}
			else
				c -= array[i];
		
		}
	}
	return m > 0;
}

int main() {
	int res;

	int _array_size = 0;
	int m;
	cin >> m;
	cin >> _array_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	vector<int> _array;
	int _array_item;
	for (int _array_i = 0; _array_i < _array_size; _array_i++) {
		cin >> _array_item;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		_array.push_back(_array_item);
	}



	res = schedule(m, _array);
	cout << res << endl;

	return 0;

}