//ĳ�����ϵ��Ӽ��Ƿ���ͨ��ȫ��Ԫ�صĻ�������ò�ѯֵ
#pragma warning(disable : 4996)
/**
����ÿһ��ѯ�ʣ����ǿ϶���ѡ������y������y&x==y�����ڶ����Ʊ���£�y��x���Ӽ���
��ô���ǿ���ά��һ������p[i]����ʾ����Ϊi���Ӽ������ֵ�Orֵ�Ƕ��١�
ÿ�β���һ�����֣������û���ظ����ֹ�����ö�����ĳ������´𰸡�
ѯ�ʵ�ʱ��ֻ��Ҫ��p[x]�Ƿ����x�ͺ��ˡ�
*/
#include<bits/stdc++.h>
using namespace std;
int p[131072];
int mx = 131071; //11111111111111111 
int q;
int main()
{
	scanf("%d", &q);
	while (q--) {
		int op, x; scanf("%d%d", &op, &x);
		if (op == 1) {
			if (p[x] == x) continue;
 			int s = mx ^ x;
			for (int i = s; i; i = (i - 1) & s) {
				p[i ^ x] |= x;
			}
			p[x] = x;
		}
		else {
			if (p[x] == x) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
