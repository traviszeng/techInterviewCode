#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main() {
	string s;
	cin >> s;
	stack<char> sChar;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ']') {
			string ss = "";
			string tt = "";
			int times;
			while (sChar.top() != '[') {
				bool flag = true;
				if (sChar.top() >= '0' && sChar.top()<='9' && flag) {
					while (sChar.top() >= '0' && sChar.top() <= '9') {
						tt += sChar.top();
						sChar.pop();
					}
					reverse(tt.begin(), tt.end());
					times = atoi(tt.c_str());
					
					flag = false;
				}

				else if (sChar.top() >= 'A' && sChar.top() <= 'Z' && flag) {
					while (sChar.top() >= 'A' && sChar.top() <= 'Z') {
						ss += sChar.top();
						sChar.pop();
					}
					reverse(ss.begin(), ss.end());
					sChar.pop();//µ¯³ö|
				}
			}
			sChar.pop();//µ¯³ö[
			
			for (int j = 0; j < times; j++)
				for (int k = 0; k < ss.length(); k++)
					sChar.push(ss[k]);
				
		}
		else {
			sChar.push(s[i]);
		}
	}
	string result = "";
	while (!sChar.empty()) {
		result += sChar.top();
		sChar.pop();
	}
	reverse(result.begin(), result.end());
	cout << result;
	system("pause");
}