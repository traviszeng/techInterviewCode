/**
给两个ip 和子网掩码的位数
判断两个ip是否在同一个子网

*/

#include<iostream>
#include<vector>
#include<string>
#include<math.h>

using namespace std;
int main() {
	string ip1, ip2;
	int netmask;
	cin >> ip1 >> ip2;
	cin >> netmask;
	vector<int> ip1Num;
	vector<int> ip2Num;
	int cur = 0;
	for (int i = 0; i < ip1.length(); i++) {
		if (ip1[i] == '.') {
			ip1Num.push_back(cur);
			cur = 0;
		}
		else {
			cur *= 10;
			cur += ip1[i] - '0';
		}
	}
	ip1Num.push_back(cur);
	cur = 0;
	for (int i = 0; i < ip2.length(); i++) {
		if (ip2[i] == '.') {
			ip2Num.push_back(cur);
			cur = 0;
		}
		else {
			cur *= 10;
			cur += ip2[i] - '0';
		}
	}
	ip2Num.push_back(cur);
	vector<int> netmaskNum;
	int tempNetmaskNum = netmask;
	while (tempNetmaskNum > 0) {
		if (tempNetmaskNum >= 8) {
			tempNetmaskNum -= 8;
			netmaskNum.push_back(255);
		}
		else if (tempNetmaskNum > 0 && netmaskNum.size() < 4) {
			netmaskNum.push_back(255 - pow(2, 8 - tempNetmaskNum) + 1);
			tempNetmaskNum = 0;
		}
	}
	while (netmaskNum.size() < 4) {
		netmaskNum.push_back(0);
	}

	for (int i = 0; i < 4; i++) {
		ip1Num[i] = ip1Num[i] & netmaskNum[i];
		ip2Num[i] = ip2Num[i] & netmaskNum[i];
		if (ip1Num[i] != ip2Num[i]) {
			cout << "false" << endl;
			return 0;
		}
	}
	cout << "true" << endl;
	return 0;

}