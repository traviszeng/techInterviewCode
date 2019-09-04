/**
任务调度
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
在m个节点的分布式计算系统中，有一批任务需要执行，每个任务需要的时间是array[i]，每个节点同一时间只能执行一个任务，每个节点只能执行连续的任务，例如i,i+1,i+2,但是不能执行i,i+2。请问任务完成的最短时间

输入
输入数据包含两行

第一行，空格分隔的两个整数m和n，分别表示节点个数和任务个数(m>0,n>=0)

第二行，空格分隔的正整数序列，表示每个任务需要的时间

输出
一个整数，表示最短完成时间


样例输入
3 5
1 5 3 4 2
样例输出
6

提示
第一个节点执行：任务1和任务2，耗时=1+5=6
第二个节点执行：任务3，耗时=3
第三个节点执行：任务4和任务5，耗时=4+2=6
所以，总最短耗时=6
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
int ans = 100000;


int schedule(int m, vector<int> array) {
	int sum = 0;
	for (int i = 0; i < array.size(); i++) {
		sum += array[i];
	}

	int average = sum / m;
	int min = average, max = sum;
	while (min < max) {
		int mid = (min + max) / 2;
		if (isSatisfy(array, m, mid)) {
			max = mid;
		}
		else {
			min = mid+1;
		}
	}
	return min;
}

bool isSatisfy(vector<int> array, int m, int t) {
	int c = t;
	for (int i = 0; i < array.size(); i++) {
		if (c >= array[i]) {
			c -= array[i];
		}
		else {
			m--;
			c = t;
			if (c < array[i]) {
				return false;
			}
			else
				c -= array[i];
		
		}
	}
	return m > 0;
}

int main() {
	int res;

	int _array_size = 0;
	int m;
	cin >> m;
	cin >> _array_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	vector<int> _array;
	int _array_item;
	for (int _array_i = 0; _array_i < _array_size; _array_i++) {
		cin >> _array_item;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		_array.push_back(_array_item);
	}



	res = schedule(m, _array);
	cout << res << endl;

	return 0;

}