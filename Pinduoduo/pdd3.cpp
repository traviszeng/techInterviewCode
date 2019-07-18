/*
A 国的手机号码由且仅由 N 位十进制数字(0-9)组成。一个手机号码中有至少 K 位数字相同则被定义为靓号。A 国的手机号可以有前导零，比如 000123456 是一个合法的手机号。
小多想花钱将自己的手机号码修改为一个靓号。修改号码中的一个数字需要花费的金额为新数字与旧数字之间的差值。比如将 1 修改为 6 或 6 修改为 1 都需要花 5 块钱。
给出小多现在的手机号码，问将其修改成一个靓号，最少需要多少钱？

输入描述:
第一行包含2个整数 N、K，分别表示手机号码数字个数以及靓号至少有 K 个数字相同。
第二行包含 N 个字符，每个字符都是一个数字('0'-'9')，数字之间没有任何其他空白符。表示小多的手机号码。
数据范围：
2 <= K <= N <= 10000


输出描述:
第一行包含一个整数，表示修改成一个靓号，最少需要的金额。
第二行包含 N 个数字字符，表示最少花费修改的新手机号。若有多个靓号花费都最少，则输出字典序最小的靓号。
示例1
输入
6 5
787585
输出
4
777577
说明
花费为4的方案有两种：777577与777775，前者字典序更小。
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

bool cmp(const pair<char,int>& a,const pair<char,int>& b){
	return a.second < b.second;
}


int find(map<char, int> nmap,char key,int K,string& result) {
	int needNum = K - nmap[key];
	int k = 1;
	int sum = 0;
	while (needNum>0) { 
		map<char, int>::iterator temp = nmap.find(key + k);
		if (temp != nmap.end()) {
			//先选小位置的
			if (nmap[key + k] <= needNum) {
				for (int i = 0; i < result.length(); i++)
					if (result[i] == key + k)
						result[i] = key;
				needNum -= nmap[key + k];
				sum += k * nmap[key + k];
			}
			else {
				sum += k * needNum;
				for (int i = 0, num = 0; i<result.length() && num<needNum; i++) {
					if (result[i] == key + k) {
						result[i] = key;
						num++;
					}
				}
				

				needNum = 0;
				break;
				return sum;
			}
		}


		temp = nmap.find(key - k);
		if (temp != nmap.end()) {
			//先选小位置的
			if (nmap[key - k] <= needNum) { //全部替换
				for (int i = 0; i < result.length(); i++)
					if (result[i] == key - k)
						result[i] = key;
				needNum -= nmap[key - k];
				sum += k * nmap[key - k];
			}
			else {
				
				for (int i = result.length() - 1, num = 0; i >= 0 && num<needNum; i--) {
					if (result[i] == key - k) {
						result[i] = key;
						num++;
					}
				}
				sum += k * needNum;
				needNum = 0;
				break;
				return sum;
			}
		}
		
		k++;

		
	}
	//cout << result;
	return sum;
}

int main() {
	int N, K;
	string number;
	cin >> N >> K;
	cin >> number;
	map<char, int> numMap;
	for (int i = 0; i < N; i++) {
		if (numMap.find(number[i]) == numMap.end()) {
			numMap[number[i]] = 1;
		}
		else {
			numMap[number[i]] += 1;
		}
	}
	/*map<char, int>::iterator iter = max_element(numMap.begin(), numMap.end(), cmp);
	if (iter!=numMap.end() && iter->second>=K) {
		cout << 0 << endl << number;
		return 0;
	}*/
	int min = N * 9;
	char key;
	string finalResult = "";
	
	map<char, int>::iterator start = numMap.begin();
	while (start != numMap.end()) {
		string result = number;
		int temp = find(numMap, start->first,K,result);
		if (temp < min) {
			min = temp;
			key = start->first;
			finalResult = result;
		}
		start++;
	}

	cout << min<<endl<<finalResult;
	system("pause");
}

