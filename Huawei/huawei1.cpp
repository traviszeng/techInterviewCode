/**
	������ת���

	��Ŀ����
	��дһ��reverseadd������ʵ�����������ú�����͵Ĺ��ܣ� ��������123��456������321+654�����975��
	ע�⣺����100,200���3,���Զ�ȥ����ͷ��0��,������Χ���-1

	��������
	����ԭ�ͣ�int reverseAdd(int a, int b)
	���룺
	�����a��b����������Чȡֵ��Χ[1,70000]�����������

	�������
	ͨ����������ֵ������
	�������a��b����������ȡֵ��Χ����Ӧ���-1
	����Ӧ�ð���Ҫ��������ַ�ת��ĺ�

	��������
	123 456

	�������
	975
*/

#include<climits>
#include<iostream>
using namespace std;
//��ת����
int reverseNum(int a) {
	int sum = 0;
	while (a != 0) {
		sum *= 10;
		sum += (a % 10);
		a /= 10;
	}
	return sum;
}


int reverseAdd(int a,int b) {
	if (a > 70000 || b > 70000 || a < 1 || b < 1)
		return -1;
	return reverseNum(a) + reverseNum(b);
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << reverseAdd(a, b);
	system("pause");
	return 0;
}
