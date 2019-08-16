#include<iostream>
using namespace std;
int getMax(int len) {
	if (len < 1) return 0;
	if (len == 1) return 1;
	else if (len == 2) return 2;
	else if (len == 3) return 3;
	else if (len == 4) return 4;
	else {
		return 3 * getMax(len - 3);
	}
}

int  main() {
	int len;
	cin >> len;
	cout << getMax(len);
	system("pause");
}