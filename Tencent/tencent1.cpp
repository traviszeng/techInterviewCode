#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

/*

������СQ�����ʵ�һ�����������������ر����ܹ���n���㣬����û����֮��ľ���ȴ����ͬ�����������СQ����ÿ���ʱ��Ҳ��ͬ�����ĳһ��ĸ߶�Ϊx����ô������һ������Ļ��Ǽ�Ҳ��x��СQ����ʹ��һ��ħ����û��һ�ο�������������һ������㣬����ÿ����Ծ֮��СQ��������ħ������������������һ������ٴ���Ծ���������ΪСQ��Ҫ������һ�����Ϣ�����Ҳ�����������⼴�������ߣ����ǲ�����ʱ��ģ���
СQ������̵�ʱ������������ϣ�����ܸ��������ʱ���Ƕ��١�

����������
��һ��һ����n n<=10000����ʾ���Ĳ�����
��������n��ÿ��һ����h(1<=h<=100)����ʾ��������ÿ��ĸ߶ȡ�

���������
һ��������ʾ���ʱ�䡣

*/

int main() {
	int num;
	cin >> num;
	//��¼������i�����Сֵ
	int *jump = new int[num+1];
	//��¼������i�����Сֵ
	int *climb = new int[num + 1];

	int *a = new int[num];
	for (int i = 0; i < num; i++)
	{
		cin >> a[i];
	}

	

	jump[0] = 0;
	climb[0] = 0;
	for (int i = 1; i < num + 1; i++) {
		//for jump
		if (i == 1)
			jump[i] = 0;
		else
			jump[i] = min(climb[i-2],climb[i-1]);

		climb[i] = min(jump[i - 1], climb[i - 1]) + a[i-1];
	}

	cout << min(climb[num], jump[num]);
	system("pause");
	return 0;
}