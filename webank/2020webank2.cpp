/**
/**
��ѯ�ʴ���
ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 65536KB���������� 589824KB
��Ŀ������
Alice������һ����x���ڷ�Χ[0,2n)�ڡ�����Ҫѯ��AliceһЩ���⡣ÿ��ѯ����һ����t��Alice��ش��� t&x �Ƿ����t���㲻�ܸ������еĻش�ı��������ѯ�ʣ���ѯ����Ҫ��ǰ��ã�������Ҫ����ѯ�ʶ��ٴ�����֤����ȷ��x��ֵ�������mod106+3

&����˼��λ������

���ҽ������ַ�������һ��ѯ�ʲ�ͬ�����Ǿ���Ϊ���ַ����ǲ�ͬ�ġ�����ѯ��[1,2]��[1,3]�ǲ�ͬ�ģ�[1,2][2,1]Ҳ�ǲ�ͬ�ģ��������ǵõ�����ͬ�Ľ����

����
һ��������n ( n��10^9 )

���
һ��������mod106+3


��������
3
�������
6

��ʾ
ѯ�ʵ�tΪ1,2,4����������6�����з�ʽ��[1,2,4][1,4,2][2,1,4][2,4,1][4,1,2][4,2,1]��
*/


#include<iostream>
#include<vector>
using namespace std;
#define MOD 1000003
int main() {
	long long n;
	cin >> n;
	long long res = 1;
	while (n) {
		res *= n;
		res %= MOD;
		n--;
	}
	cout << res;
	system("pause");
}