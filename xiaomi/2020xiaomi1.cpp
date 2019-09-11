/**
模仿2048游戏
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
《2048》是一款热门的数字游戏。游戏中，每个方块上的数字都有2的幂，数字方块会根据指令整体进行上下左右移动，如果两个数字相同的方块在移动中碰撞，他们就会合成一个新的方块。例如下图为4*4格子的游戏，0表示格子为空，图a为移动前格子中的数字，图b为图a左移后的结果:

0 0 2 4
0 2 2 2
0 4 2 2
8 8 2 2
图a
2 4 0 0
4 2 0 0
4 4 0 0
16 4 0 0
图b
问，给定n*m的矩阵M，0表示空格子，非0整数表示待移动的数字，按照2048的移动规则，输出进行左移操作后的矩阵结果。

输入
输入n行数据

第1行为矩阵行数

第2行到第n行为矩阵每行数据，m个数据用空格隔开

输出
输出左移后的矩阵，单行元素用空格隔开，换行处无空格


样例输入
4
0 0 2 4
0 2 2 2
0 4 2 2
8 8 2 2
样例输出
2 4 0 0
4 2 0 0
4 4 0 0
16 4 0 0
*/

#include <iostream>
#include <vector>
#include <numeric>
#include<string>

#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
void solution(vector < string > input) {
	vector<vector<int>> num;
	int temp = 0;
	for (int i = 0; i < input.size(); i++) {
		vector<int> tempNum;
		temp = 0;
		for (int j = 0; j < input[i].length(); j++) {
			if (input[i][j] <= '9'  && input[i][j] >= '0') {
				temp *= 10;
				temp += input[i][j] - '0';

			}
			else {//遇到空格
				tempNum.push_back(temp);
				temp = 0;
			}
		}
		tempNum.push_back(temp);
		num.push_back(tempNum);
	}
	for (int i = 0; i<num.size(); i++) {
		for (int j = 0; j < num[i].size()-1; j++) {
			if (num[i][j]!=0 && num[i][j] == num[i][j + 1]) {
				num[i][j] = num[i][j] * 2;
				num[i][j + 1] = 0;
			}
		}
	}

	for (int i = 0; i < num.size(); i++) {
		int sumOfZero = 0; //标记0的个数
		for (auto it = num[i].begin(); it != num[i].end();) {
			if (*it == 0) {
				it = num[i].erase(it);
				sumOfZero++;
				//num[i].push_back(0);
			}
			else {
				it++;
			}
		}
		for (int k = 0; k < sumOfZero; k++)
			num[i].push_back(0);
	}

	for (int i = 0; i < num.size(); i++) {
		for (int j = 0; j < num[i].size(); j++) {
			cout << num[i][j];
			if (j != num[i].size() - 1) cout << " ";
		}
		cout << endl;
	}


}
/******************************结束写代码******************************/


int main() {
	string res;

	int _input_size = 0;
	cin >> _input_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	vector<string> _input;
	string _input_item;
	for (int _input_i = 0; _input_i<_input_size; _input_i++) {
		getline(cin, _input_item);
		_input.push_back(_input_item);
	}

	solution(_input);

	//cout << res << endl;
	system("pause");
	return 0;

}
