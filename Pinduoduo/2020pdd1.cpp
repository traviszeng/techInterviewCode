#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	string line;
	getline(cin, line);
	stringstream ss(line);
	vector<int> a;
	int x;
	while (ss >> x) {
		a.push_back(x);
	}

	getline(cin, line);
	stringstream sb(line);
	vector<int> b;
	while (sb >> x) {
		b.push_back(x);
	}

	if (a.size() == 2) {
		if (*max_element(b.begin(), b.end()) < a[0]) {
			int max = 0;
			for (int i = 0; i < b.size(); i++) {
				if (b[i]<a[1] && b[i]>max)
					max = b[i];
			}

			if (max == 0) {
				cout << "NO";
				return 0;
			}
			a[0] = max;

		}
		else {
			a[1] = *max_element(b.begin(), b.end());
		}

		for (int i = 0; i < a.size(); i++) {
			cout << a[i] << " ";
		}

		return 0;


	}

	int index = 0;
	for (int i = 1; i < a.size(); i++) {
		if (a[i] <= a[i - 1])
			index = i;
	}

	if (index == a.size() - 1) { //在最末尾
		

		if (*max_element(b.begin(), b.end()) < a[a.size() - 2]) {
			cout << "NO";
			return 0;
		}
		else {
			a[a.size() - 1] = *max_element(b.begin(), b.end());
		}
	}
	else if (index==1) {
		if (a[0] >= a[2]) {
			int max = 0;
			for (int i = 0; i < b.size(); i++) {
				if (b[i]<a[1] && b[i]>max)
					max = b[i];
			}
			if (max == 0) {
				cout << "NO";
				return 0;
			}
			a[0] = max;
		}//说明要改第一个元素
		else { //第二个元素不符合
			int max = 0;
			for (int i = 0; i < b.size(); i++) {
				if (b[i]<a[2] && b[i]>max && b[i]>a[0])
					max = b[i];
			}
			if (max == 0) {
				cout << "NO";
				return 0;
			}
			a[1] = max;
		}
	}
	else {
		int max = 0;
		for (int i = 0; i < b.size(); i++) {
			if (b[i]<a[index+1] && b[i]>max && b[i]>a[index-1])
				max = b[i];
		}
		if (max == 0) {
			cout << "NO";
			return 0;
		}
		a[index] = max;
	}


	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	system("pause");
}