#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> a;
vector<vector<int>> b;
int doConvolution(int x, int y) {
	int sum = 0;
	for (int i = 0; i <  3; i++) {
		for (int j = 0; j <  3; j++) {
			sum += a[x + i][y + j] * b[i][j];
		}
	}
	return sum;
}


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < m; j++) {
			int tem=0;
			cin >> tem;
			temp.push_back(tem);
		}
		a.push_back(temp);
	}
	
	for (int i = 0; i < 3; i++) {
		vector<int> temp;
		for (int j = 0; j < 3; j++) {
			int tem = 0;
			cin >> tem;
			temp.push_back(tem);
		}
		b.push_back(temp);
	}


	for (int start = 0; start+3 <= n ; start++) {
		for (int startj = 0; startj <= m - 3; startj++) {
			cout<<doConvolution(start,startj)<<" ";
		}
		cout << endl;
	}
	system("pause");
}