/**

��f(n) = 1!2!...n!���ĩβ�м���������0

*/

#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int num = 0;
	if (n <0)
		cout << num;
	else {
		for (int i = 1; i <= n; i++) {
			int temp = i;
			while (temp) {
				num += temp / 5;
				temp /= 5;
			}
		}
	}
	cout << num;
	system("pause");
}