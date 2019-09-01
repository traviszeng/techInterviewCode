

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n, m,k;
	cin >> n >> m >> k;
	int *num = new int[n*m];
	//memset(num, 0, n*m);
	for (int i = 0; i < n*m; i++)
		num[i] = 0;
	for (int i = 0; i < n; i++)
	{
		num[i*n] = i + 1;
	}

	for (int i = 1; i < m; i++)
	{
		num[i] = i + 1;
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			num[i*n+j] = num[i*n] * num[j];
		}
	}
	sort(num,num+n*m);
	reverse(num,num+n*m);
	cout << num[k - 1];
	system("pause");
}