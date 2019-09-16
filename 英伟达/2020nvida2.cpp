/**

ѧӢ��
ʱ�����ƣ�C/C++ 1�룬�������� 2��
�ռ����ƣ�C/C++ 32768K���������� 65536K
64bit IO Format: %lld
�����ʹ�ñ���IDE���룬�����������ƣ���������������沢���ԡ���ť���д����ύ��
��Ŀ����
Jessi��ѧӢ�Ϊ�˿��ٶ���һ�����֣���д��������ת����Ӣ�ģ�

��22��twenty two��123��one hundred and twenty three��



˵����

����Ϊ�����������Ȳ�������λ��������С����ת�����ΪӢ��Сд��

�����ʽΪtwenty two��

�Ƿ������뷵�ء�error����

�ؼ�����ʾ��and��billion��million��thousand��hundred

����ԭ�ͣ�public static String parse(long num)


��������:
����һ��long������

�������:
�����Ӧ��Ӣ��д��

ʾ��1�������ʾ���������ԣ���̨��������һ�㲻����ʾ��
����
����
2356
���
����
two thousand three hundred and fifty six
*/
#include<iostream>
#include<string>
using namespace std;


const string dictO[] = {
	"zero","one","two","three","four","five","six","seven","eight","nine","ten",
	"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"
};

const string dictT[] = {
	"zero","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"
};

const string dictH[] = {
	"","thousand","million","billion","trillion","thousand trillion","million trillion","billion trillion"
};

string parse(long num) {
	string s = "";
	int v = num % 100;
	if (v <= 19)
		s = dictO[v];
	else if (v > 19 && v % 10 == 0) {
		s = dictT[v / 10];
	}

	else{
		if (v / 10) {
			s = dictT[v / 10] + " ";
		}
		else {
			s = "";
		}
		s = s + dictO[v % 10];
	}
	s = ((num / 100) ? dictO[num / 100] + " hundred and " : "") + s;
	return s;
}


int main() {
	string res = "";
	
	long long num = 0;
	while (cin >> num) {
		int i = 0;
		do {
			if (i != 0) {
				res = dictH[i] + " " + res;
			}
			res = parse(num % 1000) + " " + res;
			num = num / 1000;
			++i;
		} while (num != 0);
		cout << res;
	}
	system("pause");
}