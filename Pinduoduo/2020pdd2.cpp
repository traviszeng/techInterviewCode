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
	vector<string> a;
	string x;
	int *h = new int[26];

	for (int i = 0; i < 26; i++)
		h[i] = 0;

	while (ss >> x) {
		a.push_back(x);
		h[x[0] - 'A'] += 1;
		h[x[x.length() - 1] - 'A'] -= 1;
	}

	for (int i = 0; i < 26; i++)
		if (h[i] != 0) {
			cout << "false";
			return 0;
		}

	cout << "true";
	system("pause");

	

	

}