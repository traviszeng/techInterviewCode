/**
������
ʱ�����ƣ�C/C++ 1�룬�������� 2��
�ռ����ƣ�C/C++ 32768K���������� 65536K
64bit IO Format: %lld
�����޶���C++11(clang++ 3.9), Java(javac 1.8)
�����ʹ�ñ���IDE���룬�����������ƣ���������������沢���ԡ���ť���д����ύ��
��Ŀ����
��ͼ��һ��4�׵���������
1 2 3 4
12 13 14 5
11 16 15 6
10 9 8 7
���ִ�1��ʼ������˳ʱ�뷽������������������
���ڸ������Ĺ�ģn���������n����������
��������:
��������������ݣ�ÿ�����ݰ���һ��������n��1��n��20����
�������:
��Ӧÿ�����ݣ������Ӧ����������

ÿ������֮�����һ��������Ϊ�ָ���
ʾ��1�������ʾ���������ԣ���̨��������һ�㲻����ʾ��
����
����
3<br/>4
���
����
1 2 3<br/>8 9 4<br/>7 6 5<br/><br/>1 2 3 4<br/>12 13 14 5<br/>11 16 15 6<br/>10 9 8 7
*/


#include<iostream>
#include<string>
using namespace std;

//��start,start��ʼһȦһȦ��ӡ
void matrixInCircle(int** numbers, int columns, int rows, int start, int &index) {
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;

	// �����Ҵ�ӡһ��
	for (int i = start; i <= endX; ++i)
	{
		numbers[start][i] = index++;

	}

	// ���ϵ��´�ӡһ��
	if (start < endY)
	{
		for (int i = start + 1; i <= endY; ++i)
		{
			numbers[i][endX] = index++;
		}
	}

	// ���ҵ����ӡһ��
	if (start < endX && start < endY)
	{
		for (int i = endX - 1; i >= start; --i)
		{
			numbers[endY][i] = index++;

		}
	}

	// ���µ��ϴ�ӡһ��
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
