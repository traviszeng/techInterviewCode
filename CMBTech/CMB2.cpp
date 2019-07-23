#include<map>
#include<set>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class UrlClassifier {
public:
	static set<string> classifiedUrls;
	static map<string, set<string>> result;
	static void classifyUrl(string url);
	static vector<string> getUrl(string url);
	static string getType(string url);
};

set<string> UrlClassifier::classifiedUrls;
map<string, set<string>> UrlClassifier::result;

void UrlClassifier::classifyUrl(string url) {
	if (url == "")
		return;

	string type = getType(url);
	map<string, set<string>>::iterator it = result.find(type);
	if (it != result.end()) {
		it->second.insert(url);
	}
	else {
		set<string> set;
		set.insert(url);
		result.insert(make_pair(type, set));
	}

	classifiedUrls.insert(url);

	vector<string> nextUrls = getUrl(url);

	if (nextUrls.empty())
		return;

	for (vector<string>::iterator iterator = nextUrls.begin(); iterator != nextUrls.end(); iterator++) {
		set<string>::iterator sit = classifiedUrls.find(*iterator);
		if (sit != classifiedUrls.end())
			continue;

		classifyUrl(*iterator);
	}
}
