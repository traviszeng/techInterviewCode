#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int n;
	cin >> n;
	int *grade = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> grade[i];
	}
	int q;
	cin >> q;
	int *search = new int[q];
	for (int i = 0; i < q; i++) {
		cin >> search[i];
	}
	for (int i = 0; i < q; i++) {
		int g = grade[search[i]-1];
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (grade[j] <= g)
				count++;
		}

		double percent = double(count - 1) / double(n) * 100;
		cout << setiosflags(ios::fixed) << setprecision(6) << percent;
		cout << endl;
	}
	system("pause");
	//return 0;
}