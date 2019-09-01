/*/**[���|25��] ��������
ʱ�����ƣ�C/C++ 1�룬�������� 2��
�ռ����ƣ�C/C++ 32768K���������� 65536K
64bit IO Format: %lld
�����ʹ�ñ���IDE���룬�����������ƣ���������������沢���ԡ���ť���д����ύ��
��Ŀ����
��n�����ӣ���i�������п���Ͷ����Xi�ֵȸ��ʵĲ�ͬ�Ľ�������ִ�1��Xi���������ӵĽ�������ֵ����Ϊ���ս���������ս����������
��������:
��һ��һ������n����ʾ��n�����ӡ���1 <= n <= 50��
�ڶ���n����������ʾÿ�����ӵĽ����Xi��(2 <= Xi <= 50)
�������:
������ս����������������λС����
ʾ��1�������ʾ���������ԣ���̨��������һ�㲻����ʾ��
����
����
2
2 2
���
����
1.75*/*/

#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int n;
	cin >> n;
	int *a = new int[n];

	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > max) max = a[i];
	}

	float *proba = new float[max + 1];
	//proba[1] = 1;
	proba[0] = 0;
	float result = 0;
	for (int i = 1; i < max + 1; i++) {
		proba[i] = 1;
		for (int j = 0; j < n; j++){
			if(a[j]>=i)
				proba[i] *= (float)i / a[j];
		}

		for (int k = i-1; k >= 1; k--) {
			proba[i] -= proba[k];
		}
		cout << proba[i] << endl;
		result += i * proba[i];
	}
	cout <<setiosflags(ios::fixed)<<setprecision(2)<< result;


	system("pause");
}