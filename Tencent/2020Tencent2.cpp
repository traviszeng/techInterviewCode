#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int InversePairsCore(int* data, int* copy, int start, int end);
int getTimes(int n) {
	int re = 1;
	for (int i = 0; i < n; i++)
		re *= 2;
	return re;
}

int InversePairs(int* data, int length)
{
	if (data == nullptr || length < 0)
		return 0;

	int* copy = new int[length];
	for (int i = 0; i < length; ++i)
		copy[i] = data[i];

	int count = InversePairsCore(data, copy, 0, length - 1);
	delete[] copy;

	return count;
}

int InversePairsCore(int* data, int* copy, int start, int end)
{
	if (start == end)
	{
		copy[start] = data[start];
		return 0;
	}

	int length = (end - start) / 2;

	int left = InversePairsCore(copy, data, start, start + length);
	int right = InversePairsCore(copy, data, start + length + 1, end);

	// i初始化为前半段最后一个数字的下标
	int i = start + length;
	// j初始化为后半段最后一个数字的下标
	int j = end;
	int indexCopy = end;
	int count = 0;
	while (i >= start && j >= start + length + 1)
	{
		if (data[i] > data[j])
		{
			copy[indexCopy--] = data[i--];
			count += j - start - length;
		}
		else
		{
			copy[indexCopy--] = data[j--];
		}
	}

	for (; i >= start; --i)
		copy[indexCopy--] = data[i];

	for (; j >= start + length + 1; --j)
		copy[indexCopy--] = data[j];

	return left + right + count;
}

int main() {
	int n;
	cin >> n;
	int number = getTimes(n);
	int *num = new int[number];
	for (int i = 0; i < number; i++)
		cin >> num[i];

	int m;
	cin >> m;
	int *q = new int[m];
	for (int i = 0; i < m; i++)
		cin >> q[i];
	for (int i = 0; i < m; i++) {
		int result = 0;
		int gap = getTimes(q[i]);
		for (int j = 0; j < number; j += gap) {
			reverse(num + j, num + j + gap);
		}
		
		result = InversePairs(num, number);
		cout << result<<endl;
	}
	system("pause");

}