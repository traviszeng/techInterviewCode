/*
你在玩一个回合制角色扮演的游戏。现在你在准备一个策略，以便在最短的回合内击败敌方角色。在战斗开始时，敌人拥有HP格血量。当血量小于等于0时，敌人死去。一个缺乏经验的玩家可能简单地尝试每个回合都攻击。但是你知道辅助技能的重要性。
在你的每个回合开始时你可以选择以下两个动作之一：聚力或者攻击。
聚力会提高你下个回合攻击的伤害。
攻击会对敌人造成一定量的伤害。如果你上个回合使用了聚力，那这次攻击会对敌人造成buffedAttack点伤害。否则，会造成normalAttack点伤害。
给出血量HP和不同攻击的伤害，buffedAttack和normalAttack，返回你能杀死敌人的最小回合数。

输入描述：
第一行是一个数字HP
第二行是一个数字normalAttack
第三行是一个数字buffedAttack
1 <= HP,buffedAttack,normalAttack <= 10^9

输出描述：
输出一个数字表示最小回合数

输入示例：
13
3
5
输出示例
5
*/

#include<iostream>
using namespace std;

//评估是否值得使用buffered attack
bool evaluateBuffer(int n,int b) {
	return b / n >= 2;
}

void solution1(int HP,int normalAttack,int bufferAttack) {
	//通过评估是否值得蓄力来决定是用什么样的攻击方式
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
	
	//用DFS遍历所有可能性
	cout<<dfs(HP, normalAttack, bufferAttack);
	system("pause");
}