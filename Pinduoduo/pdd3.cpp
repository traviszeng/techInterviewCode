/*
A �����ֻ��������ҽ��� N λʮ��������(0-9)��ɡ�һ���ֻ������������� K λ������ͬ�򱻶���Ϊ���š�A �����ֻ��ſ�����ǰ���㣬���� 000123456 ��һ���Ϸ����ֻ��š�
С���뻨Ǯ���Լ����ֻ������޸�Ϊһ�����š��޸ĺ����е�һ��������Ҫ���ѵĽ��Ϊ�������������֮��Ĳ�ֵ�����罫 1 �޸�Ϊ 6 �� 6 �޸�Ϊ 1 ����Ҫ�� 5 ��Ǯ��
����С�����ڵ��ֻ����룬�ʽ����޸ĳ�һ�����ţ�������Ҫ����Ǯ��

��������:
��һ�а���2������ N��K���ֱ��ʾ�ֻ��������ָ����Լ����������� K ��������ͬ��
�ڶ��а��� N ���ַ���ÿ���ַ�����һ������('0'-'9')������֮��û���κ������հ׷�����ʾС����ֻ����롣
���ݷ�Χ��
2 <= K <= N <= 10000


�������:
��һ�а���һ����������ʾ�޸ĳ�һ�����ţ�������Ҫ�Ľ�
�ڶ��а��� N �������ַ�����ʾ���ٻ����޸ĵ����ֻ��š����ж�����Ż��Ѷ����٣�������ֵ�����С�����š�
ʾ��1
����
6 5
787585
���
4
777577
˵��
����Ϊ4�ķ��������֣�777577��777775��ǰ���ֵ����С��
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
			//��ѡСλ�õ�
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
			//��ѡСλ�õ�
			if (nmap[key - k] <= needNum) { //ȫ���滻
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

