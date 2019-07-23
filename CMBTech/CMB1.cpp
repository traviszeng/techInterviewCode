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
	int n = 0, i = 0; //n为当前的字节数，i为要截取的字节数，从第三个字节开始
	bool isFirst = false;
	for (; i < byteArr && n < length; i++) {
		//奇数位置，如3、5、7等为UCS2编码中两个字节的第二个字节
		if (i % 2 != 0) {
			n++;//在UCS2第1个字节时n+1
		}
		else {
			//当UCS2编码的第1个字节不等于零时，该UCS2字符为汉字，一个汉字算两个字节
			if (byte[i] != 0) {
				n++;
				if (!isFirst) {
					n += 2; //如果是第一个汉字 长度加2
				}
				isFirst = true;

			}
			else {
				isFirst = false;
			}
		}
	}

	//unicode是双字节 对于i为奇数 全角 则减1 半角 加1
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