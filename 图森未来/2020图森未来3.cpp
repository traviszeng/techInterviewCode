#include<iostream>
#include<string>
#include<sstream>
using namespace std;
long long a[] = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };
int main() {
	int n;
	
	cin >> n;
	for (int p = 0; p < n; p++) {
		long long t, s, k;

		cin >> t >> s >> k;
		long long tempT = t;
		long long tempS = s;
		string ss = "";
		string tt = "";
		ostringstream os;
		os << tempS;
		istringstream is(os.str());
		string temp;;
		is >> temp;
		ss = temp + ss;

		ostringstream oss;
		oss << tempT;
		istringstream iss(oss.str());
		string temps;
		iss >> temps;
		tt = temps + tt;
		int sWei = 0;
		int tWei = 0;
		for (int i = 0; i < 10; i++) {
			if (s / a[i] == 0) {
				sWei = i - 1;
				break;
			}
		}

		for (int i = 0; i < 10; i++) {
			if (t / a[i] == 0) {
				tWei = i - 1;
				break;
			}
		}
		tempS = (tempS - tempS / a[sWei]*a[sWei]) * 10 + tempS / a[sWei];
		tempT = (tempT - tempT / a[tWei]*a[tWei]) * 10 + tempT / a[tWei];
		while (ss.length()<k) {
			ostringstream os;
			os << tempS;
			istringstream is(os.str());
			string temp;;
			is >> temp;
			ss = temp + ss;
			tempS = (tempS - tempS / a[sWei] * a[sWei]) * 10 + tempS / a[sWei];
		}

		while (tt.length()<k) {
			ostringstream os;
			os << tempT;
			istringstream is(os.str());
			string temp;;
			is >> temp;
			tt = temp + tt;
			tempT = (tempT - tempT / a[tWei] * a[tWei]) * 10 + tempT / a[tWei];
		}
		int sizeT = tt.length();
		int sizeS = ss.length();
		if (tt.substr(sizeT - k) > ss.substr(sizeS - k)) {
			cout << "Tu" << endl;
		}
		else if (tt.substr(sizeT - k) < ss.substr(sizeS - k)) {
			cout << "Simple" << endl;
		}
		else {
			cout << "Draw" << endl;
		}
	
	}
	system("pause");
	

	
}