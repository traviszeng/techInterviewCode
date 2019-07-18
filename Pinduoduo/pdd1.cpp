/*
������һ���غ��ƽ�ɫ���ݵ���Ϸ����������׼��һ�����ԣ��Ա�����̵Ļغ��ڻ��ܵз���ɫ����ս����ʼʱ������ӵ��HP��Ѫ������Ѫ��С�ڵ���0ʱ��������ȥ��һ��ȱ���������ҿ��ܼ򵥵س���ÿ���غ϶�������������֪���������ܵ���Ҫ�ԡ�
�����ÿ���غϿ�ʼʱ�����ѡ��������������֮һ���������߹�����
������������¸��غϹ������˺���
������Ե������һ�������˺���������ϸ��غ�ʹ���˾���������ι�����Ե������buffedAttack���˺������򣬻����normalAttack���˺���
����Ѫ��HP�Ͳ�ͬ�������˺���buffedAttack��normalAttack����������ɱ�����˵���С�غ�����

����������
��һ����һ������HP
�ڶ�����һ������normalAttack
��������һ������buffedAttack
1 <= HP,buffedAttack,normalAttack <= 10^9

���������
���һ�����ֱ�ʾ��С�غ���

����ʾ����
13
3
5
���ʾ��
5
*/

#include<iostream>
using namespace std;

//�����Ƿ�ֵ��ʹ��buffered attack
bool evaluateBuffer(int n,int b) {
	return b / n >= 2;
}

void solution1(int HP,int normalAttack,int bufferAttack) {
	//ͨ�������Ƿ�ֵ����������������ʲô���Ĺ�����ʽ
	if (evaluateBuffer(normalAttack, bufferAttack))
	{
		if (HP%bufferAttack == 0)
			cout << HP / bufferAttack * 2;
		else if (HP%bufferAttack <= normalAttack)
			cout << HP / bufferAttack * 2 + 1;
		else
			cout << HP / bufferAttack * 2 + 2;
	}

	else {
		if (HP%normalAttack != 0)
			cout << HP / normalAttack + 1;
		else
			cout << HP / normalAttack;
	}
}

int dfs(int HP, int normal, int buffer) {
	if (HP <= 0) return 0;
	int result1;
	int result2;

	result1 = 1 + dfs(HP - normal, normal, buffer);
	result2 = 2 + dfs(HP - buffer, normal, buffer);
	return result1 > result2 ? result2 : result1;
}

int main() {
	int HP, normalAttack, bufferAttack;
	cin >> HP >> normalAttack >> bufferAttack;

	solution1(HP, normalAttack, bufferAttack);
	cout << endl;
	
	//��DFS�������п�����
	cout<<dfs(HP, normalAttack, bufferAttack);
	system("pause");
}