/**
数组移动
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
给定一个数列，每一次移动可以将数列某个数移动到某个位置上，移动多次后，形成新的数列。定义数列中相邻两两之间的差的绝对值为“移动距离”，定义所有移动距离的总和为“总移动距离”。希望计算出最少的移动次数，使得新数列的“总移动距离”最小。 例如原数列为[4,2,7,6]，总移动距离为2+5+1=8。将6移动到7之前，会变成[4,2,6,7]，总移动距离变成2+4+1=7。

需要编写一个函数，输入为一个int数组表示数列内容，输出为一个int数字，表示最小移动次数

输入
第一行输入为数组大小，然后依次输入数组元素，如数组[4, 2, 7, 6]

输出
总移动距离最小的数列之一为[2,4,6,7]

最少移动次数：2


样例输入
4
4
2
7
6
样例输出
2
*/

#include <iostream>
#include <vector>
#include <numeric>
#include<algorithm>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
int solution(vector < int > arr) {
	vector<int> temp;

	for (int i = 0; i < arr.size(); i++) temp.push_back(arr[i]);
	sort(temp.begin(), temp.end());
	int count = 0; int j = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == temp[j]) {
			++count;
			++j;
		}
	}
	return arr.size() - count;

}
/******************************结束写代码******************************/


int main() {
	int res;

	int _arr_size = 0;
	cin >> _arr_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	vector<int> _arr;
	int _arr_item;
	for (int _arr_i = 0; _arr_i<_arr_size; _arr_i++) {
		cin >> _arr_item;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		_arr.push_back(_arr_item);
	}



	res = solution(_arr);
	cout << res << endl;

	return 0;

}
