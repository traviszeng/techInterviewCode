/**
螺旋数
时间限制：C/C++ 1秒，其他语言 2秒
空间限制：C/C++ 32768K，其他语言 65536K
64bit IO Format: %lld
语言限定：C++11(clang++ 3.9), Java(javac 1.8)
本题可使用本地IDE编码，不做跳出限制，编码后请点击“保存并调试”按钮进行代码提交。
题目描述
下图是一个4阶的螺旋数阵：
1 2 3 4
12 13 14 5
11 16 15 6
10 9 8 7
数字从1开始，沿着顺时针方向依次填满整个矩阵。
现在给你矩阵的规模n，请你输出n阶螺旋数阵。
输入描述:
输入包含多组数据，每组数据包含一个正整数n（1≤n≤20）。
输出描述:
对应每组数据，输出相应的螺旋数阵。

每组数据之后输出一个空行作为分隔。
示例1输入输出示例仅供调试，后台判题数据一般不包含示例
输入
复制
3<br/>4
输出
复制
1 2 3<br/>8 9 4<br/>7 6 5<br/><br/>1 2 3 4<br/>12 13 14 5<br/>11 16 15 6<br/>10 9 8 7
*/


#include<iostream>
#include<string>
using namespace std;

//从start,start开始一圈一圈打印
void matrixInCircle(int** numbers, int columns, int rows, int start, int &index) {
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;

	// 从左到右打印一行
	for (int i = start; i <= endX; ++i)
	{
		numbers[start][i] = index++;

	}

	// 从上到下打印一列
	if (start < endY)
	{
		for (int i = start + 1; i <= endY; ++i)
		{
			numbers[i][endX] = index++;
		}
	}

	// 从右到左打印一行
	if (start < endX && start < endY)
	{
		for (int i = endX - 1; i >= start; --i)
		{
			numbers[endY][i] = index++;

		}
	}

	// 从下到上打印一行
	if (start < endX && start < endY - 1)
	{
		for (int i = endY - 1; i >= start + 1; --i)
		{
			numbers[i][start] = index++;

		}
	}
}


void PrintMatrixClockwisely(int** numbers, int columns, int rows)
{
	if (numbers == nullptr || columns <= 0 || rows <= 0)
		return;

	int start = 0;
	int index = 1;
	while (columns > start * 2 && rows > start * 2) {
		matrixInCircle(numbers, columns, rows, start, index);
		start++;
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << numbers[i][j];
			if(j!=columns-1)  cout<< " ";
		}
		if(i!=rows-1) cout << "<br/>";
	}

}

void printMain(int rows) {
	int** numbers = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		numbers[i] = new int[rows];
		for (int j = 0; j < rows; ++j)
		{
			numbers[i][j] = 0;
		}
	}
	PrintMatrixClockwisely(numbers, rows, rows);
}

int main() {
	string rowsStr;
	while (cin >> rowsStr) {
		int rows = 0;
		for (int i = 0; i < rowsStr.length(); i++) {
			if (rowsStr[i] >= '0' && rowsStr[i] <= '9') {
				rows *= 10;
				rows += rowsStr[i] - '0';
			}
			else {
				if (rows != 0) {
					printMain(rows);
					cout << "<br/>";
					cout << "<br/>";
					rows = 0;
				}
			}
		}

		if (rows != 0) {
			printMain(rows);
		}
	}
}
