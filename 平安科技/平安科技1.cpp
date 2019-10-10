/**
求两个字符串的最长公共子串
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> longestCommonSubString(string s1, string s2) {
	vector<string> result;
	if (s1.length() == 0 || s2.length() == 0)
		return result;
	
	vector<vector<int>> array(s1.length(), vector<int>(s2.length(), 0));
	for (int i = 0; i < s2.length(); i++) {
		if (s1[0] == s2[i]) {
			array[0][i] = 1;
		}
	}

	for (int i = 0; i < s1.length(); i++) {
		if (s2[0] == s1[i]) {
			array[i][0] = 1;
		}
	}
	//int maxLen = 0;
	for (int i = 1; i < s1.length(); i++) {
		for (int j = 1; j < s2.length(); j++) {
			if (s1[i] == s2[j]) {
				array[i][j] = array[i - 1][j - 1] + 1;
			}
		}
	}

	int maxLen = 0;
	int end = 0;
	for (int i = 0; i < array.size(); i++) {
		for (int j = 0; j < array[0].size(); j++) {
			if (array[i][j] > maxLen) {
				maxLen = array[i][j];
				end = i;
				result.clear();
				result.push_back(s1.substr(end - maxLen + 1, maxLen));
			}
			else if (array[i][j] == maxLen) {
				end = i;
				result.push_back(s1.substr(end - maxLen + 1, maxLen));
			}
		}
	}

	return result;

}



int main() {
	string s1, s2;
	cin >> s1 >> s2;
	vector<string> a = longestCommonSubString(s1, s2);
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << endl;
	}
	system("pause");
}