/*
�������Ļ�����
ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 65536KB���������� 589824KB
��Ŀ������
СBƽʱϲ������һЩС�����������׼�����Լ�����С�����˼���һ���������ƵĹ��ܣ�ÿ��ָ���Ӧһ��������

��������ת�����кܶ��ֳɵķ���������СB����ֱ�Ӹ�����Щ��������������ת��������֮�󣬻���Ҫ�����ָ�����Ķ�����Ӧ������

���СB��Ҫʵ��һ��������������ת�����������֣���ת������Ӧ�Ķ�����

Ϊ�˼�ʵ�֣�СB������ֱ��ת����ƴ����Ȼ��Ѷ�Ӧ�Ķ���Ҳ���������֣����ֻҪԤ����������ߵ�ӳ���ϵ��Ȼ����������ָ��������Ӧ�Ķ�����

Ȼ����ΪСB�ĺ�����bug�������˲����������Ļ�...

���ܰ�СB������������

����
�����������������ݣ�����ÿ��������ݣ�

��һ�������������������ո��������Ҫ�� ��ӳ����������ĿN �ͽ��е���ʱ���͵�����ָ������ M (1 < N < 1000, 1 < M < 1000)

������N�У�ÿ�����������ַ�����ʾ����ָ��Ͷ�Ӧ�Ķ���cmd��action���Կո������ÿ���ַ����ĳ���С��1000����ֻ�д�Сд��ĸ

���M�У�ÿ������һ���ַ�����ʾ��Ҫ���е��Ե�����ָ��

���
����ÿ��������ݣ�

���M�У����ݵ��Ե�����ָ�������Ӧ�Ķ���ָ��action


��������
4 4
ZuoZhuan TurnLeft
YouZhuan TurnRight
QianJin Forward
HouTui Backward
ZuoZhuan
QianJin
QianJin
HouTui
1 1
SDFlkjdf LNCIls
SDFlkjdf
�������
TurnLeft
Forward
Forward
Backward
LNCIls
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;
int main() {
	int n, m;
	while (cin >> n >> m) {
		map<string, string> cmdMap;
		for (int i = 0; i < n; i++) {
			string pinyin, command;
			cin >> pinyin >> command;
			cmdMap[pinyin] = command;
		}

		for (int i = 0; i < m; i++) {
			string p;
			cin >> p;
			cout << cmdMap[p];
		}
	}
	//system("pause");

}
