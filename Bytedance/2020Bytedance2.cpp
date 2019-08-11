/*
秘密通信
时间限制：C/C++ 1秒，其他语言 2秒
空间限制：C/C++ 32768K，其他语言 65536K
64bit IO Format: %lld
本题可使用本地IDE编码，不做跳出限制，编码后请点击“保存并调试”按钮进行代码提交。
题目描述
小明和安琪是好朋友。最近，他们的谈话被一家侦探机构监控，所以他们想将他们的谈话内容进行加密处理。于是，他们发明了一种新的加密方式。 每条信息都被编译成二进制数B(明文)，其长度为N。然后该信息被写下K次，每次向右移动0, 1, ..., K-1位。
例如：B=1001010, K=4
1001010
1001010
1001010
1001010
然后对每一列进行异或操作，并且把最终所得的结果记录下来，我们将该数称为S(密文)。例如上述例子的结果为：
1110100110
最后，将编码的信息S和K发送给安琪。
小明已经实现了这种编码的加密过程，但他要求安琪写一个程序去实现这种编码的解密过程，你能帮助安琪实现解密过程吗？
输入描述:
第一行输入两个整数 N 和 K

第二行输入一个二进制字符串S，长度是N+K-1
输出描述:
输出明文B
示例1输入输出示例仅供调试，后台判题数据一般不包含示例
输入
复制
7 4
1110100110
输出
复制
1001010
示例2输入输出示例仅供调试，后台判题数据一般不包含示例
输入
复制
6 2
1110001
输出
复制
101111
备注:
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