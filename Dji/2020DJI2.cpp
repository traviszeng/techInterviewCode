/*
不听话的机器人
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
小B平时喜欢倒腾一些小东西，最近他准备给自己做的小机器人加入一套语音控制的功能，每个指令对应一个动作。

由于语言转文字有很多现成的方案，所以小B打算直接复用这些方案，但是语音转成了文字之后，还需要将文字跟具体的动作对应起来。

因此小B需要实现一个函数，将语音转换出来的文字，再转换成相应的动作。

为了简单实现，小B将语音直接转成了拼音，然后把对应的动作也都起了名字，因此只要预先输入好两者的映射关系，然后输入语音指令就输出相应的动作。

然而因为小B的函数有bug，机器人并不想听他的话...

你能帮小B解决这个问题吗？

输入
输入包含多组测试数据，对于每组测试数据：

第一行输入两个正整数，空格隔开，需要进 行映射的命令的数目N 和进行调试时发送的语音指令条数 M (1 < N < 1000, 1 < M < 1000)

接下来N行，每行输入两个字符串表示语音指令和对应的动作cmd和action，以空格隔开，每个字符串的长度小于1000，且只有大小写字母

最后M行，每行输入一个字符串表示需要进行调试的语音指令

输出
对于每组测试数据：

输出M行，根据调试的语音指令输出对应的动作指令action


样例输入
4 4
ZuoZhuan TurnLeft
YouZhuan TurnRight
QianJin Forward
HouTui Backward
ZuoZhuan
QianJin
QianJin
HouTui
1 1
SDFlkjdf LNCIls
SDFlkjdf
样例输出
TurnLeft
Forward
Forward
Backward
LNCIls
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;
int main() {
	int n, m;
	while (cin >> n >> m) {
		map<string, string> cmdMap;
		for (int i = 0; i < n; i++) {
			string pinyin, command;
			cin >> pinyin >> command;
			cmdMap[pinyin] = command;
		}

		for (int i = 0; i < m; i++) {
			string p;
			cin >> p;
			cout << cmdMap[p];
		}
	}
	//system("pause");

}
