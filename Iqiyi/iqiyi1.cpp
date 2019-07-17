/**
局长一共有N种食物，每种有i份，他每天只吃一份食物，或只买一份食物（一天中要么吃要么买，不会同时进行）求第M天P食物的份数在总食物份数中的排名。

输入：

第一行，三个数N、M、P，分别表示食物的种类，天数和要求的食物。

第二行，N个数，表示每种食物的份数。

接下来M行，每一行有两个数，第一个数表示吃或买（A表示买，B表示吃），第二个数表示对哪种食物进行操作。

输出：

P食物的排名

样例输入：

3 4 2

5 3 1

B 1

A 2

A 2

A 3

样例输出：

1

*/
#include<iostream>
using namespace std;
int main() {
	int N, M, P;
	cin >> N >> M >> P;
	
	int *A = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < M; i++) {
		char temp;
		cin >> temp;
		if (temp == 'A') {
			int tempI;
			cin >> tempI;
			A[tempI - 1] += 1;
		}
		else {
			int tempI;
			cin >> tempI;
			A[tempI - 1] -= 1;
		}
	}
	int left = A[P - 1];
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] > left)
			count += 1;
	}
	cout << count + 1;
	system("pause");
}