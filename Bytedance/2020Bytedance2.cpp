/*
����ͨ��
ʱ�����ƣ�C/C++ 1�룬�������� 2��
�ռ����ƣ�C/C++ 32768K���������� 65536K
64bit IO Format: %lld
�����ʹ�ñ���IDE���룬�����������ƣ���������������沢���ԡ���ť���д����ύ��
��Ŀ����
С���Ͱ����Ǻ����ѡ���������ǵ�̸����һ����̽������أ����������뽫���ǵ�̸�����ݽ��м��ܴ������ǣ����Ƿ�����һ���µļ��ܷ�ʽ�� ÿ����Ϣ��������ɶ�������B(����)���䳤��ΪN��Ȼ�����Ϣ��д��K�Σ�ÿ�������ƶ�0, 1, ..., K-1λ��
���磺B=1001010, K=4
1001010
1001010
1001010
1001010
Ȼ���ÿһ�н��������������Ұ��������õĽ����¼���������ǽ�������ΪS(����)�������������ӵĽ��Ϊ��
1110100110
��󣬽��������ϢS��K���͸�������
С���Ѿ�ʵ�������ֱ���ļ��ܹ��̣�����Ҫ����дһ������ȥʵ�����ֱ���Ľ��ܹ��̣����ܰ�������ʵ�ֽ��ܹ�����
��������:
��һ�������������� N �� K

�ڶ�������һ���������ַ���S��������N+K-1
�������:
�������B
ʾ��1�������ʾ���������ԣ���̨��������һ�㲻����ʾ��
����
����
7 4
1110100110
���
����
1001010
ʾ��2�������ʾ���������ԣ���̨��������һ�㲻����ʾ��
����
����
6 2
1110001
���
����
101111
��ע:
1 <= N <= 10^6

1 <= K <= 10^6
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	string code;
	cin >> code;
	
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		ans.push_back(-1);
	}

	int start = 0;
	int end = code.length()-1;
	int ansStart = 0;
	int ansEnd = n - 1;
	ans[ansStart] = code[0]-'0';
	ans[ansEnd] = code[code.length() - 1]-'0';
	start++;
	end--;
	ansStart++;
	ansEnd--;

	while (ansStart<=ansEnd) {
		int tempStart;
		int startIndex;
		if (ansStart+1 - k < 0) {
			tempStart = ans[0];
			startIndex = 1;
		}
		else {
			tempStart = ans[ansStart+1 - k];
			startIndex = ansStart - k +2;
		}
		
		for (int i = startIndex; i < ansStart; i++) {
			tempStart = tempStart ^ ans[i];
		}
		ans[ansStart] = tempStart ^ (code[start]-'0');
		start++;
		ansStart++;
		if (start < end && ansStart<ansEnd) {
			int tempEnd;
			int endIndex;
			if (ansEnd + k-1 > ans.size()-1) {
				tempEnd = ans[ans.size() - 1];
				endIndex = ans.size() - 2;

			}
			else {
				tempEnd = ans[ansEnd + k-1];
				endIndex = ansEnd + k - 2;
			}

			for (int i = endIndex; i > ansEnd; i--) {
				tempEnd = tempEnd ^ ans[i];
			}
			ans[ansEnd] = tempEnd ^ (code[end]-'0');
			end--;
			ansEnd--;
		}
	}

	for (int i = 0; i < n; i++)
		cout << ans[i];
	system("pause");
}