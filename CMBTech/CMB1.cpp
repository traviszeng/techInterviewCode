#include<iostream>
#include<vector>
#include<time.h>
#include<sstream>
using namespace std;
string substring(string s, int length) {
	if (s.empty()) {
		return "";
	}
	const char *byte = s.c_str();
	
	int byteArr = s.length();
	int n = 0, i = 0; //nΪ��ǰ���ֽ�����iΪҪ��ȡ���ֽ������ӵ������ֽڿ�ʼ
	bool isFirst = false;
	for (; i < byteArr && n < length; i++) {
		//����λ�ã���3��5��7��ΪUCS2�����������ֽڵĵڶ����ֽ�
		if (i % 2 != 0) {
			n++;//��UCS2��1���ֽ�ʱn+1
		}
		else {
			//��UCS2����ĵ�1���ֽڲ�������ʱ����UCS2�ַ�Ϊ���֣�һ�������������ֽ�
			if (byte[i] != 0) {
				n++;
				if (!isFirst) {
					n += 2; //����ǵ�һ������ ���ȼ�2
				}
				isFirst = true;

			}
			else {
				isFirst = false;
			}
		}
	}

	//unicode��˫�ֽ� ����iΪ���� ȫ�� ���1 ��� ��1
	if (i % 2 != 0) {
		if (byte[i - 1] != 0) {
			i -= 1;
		}
		else {
			i += 1;
		}
	}
	return string(byte, 0, i);
}