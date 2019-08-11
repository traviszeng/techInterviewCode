/*
闹钟叫醒去上课
时间限制：C/C++ 1秒，其他语言 2秒
空间限制：C/C++ 32768K，其他语言 65536K
64bit IO Format: %lld
本题可使用本地IDE编码，不做跳出限制，编码后请点击“保存并调试”按钮进行代码提交。
题目描述
小明总是睡过头，所以他定了很多闹钟，只有在闹钟响的时候他才会醒过来并且决定起不起床。从他起床算起他需要X分钟到达教室，上课时间为当天的A时B分，请问他最晚可以什么时间起床
输入描述:
每个输入包含一个测试用例

每个测试用例的第一行包含一个正整数，表示闹钟的数量N(N<=100)

接下来的N行每行包含两个整数，表示这个闹钟响起的时间为Hi(0<=A<24)时Mi(0<=B<60)分

接下来的一行包含一个整数，表示从起床算起他需要X(0<=X<=100)分钟到达教室

接下来的一行包含两个整数，表示上课时间为A(0<=A<24)时B(0<=B<60)分

数据保证至少有一个闹钟可以让牛牛及时到达教室
输出描述:
输出两个整数表示牛牛最晚起床时间
示例1输入输出示例仅供调试，后台判题数据一般不包含示例
输入
复制
3
5 0
6 0
7 0
59
6 59
输出
复制
6 0
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isEarly(pair<int, int> alarm, pair<int, int> schoolTime,int goTime) {
	if (alarm.first > schoolTime.first)
		return false;
	alarm.second += goTime;
	if (alarm.second >= 60)
	{
		alarm.first += alarm.second / 60;
		alarm.second %= 60;
	}

	if (alarm.first < schoolTime.first)
		return true;
	else if (alarm.first == schoolTime.first) {
		return alarm.second <= schoolTime.second;
	}
	else return false;
}


int main() {
	int alarmNum;
	cin >> alarmNum;
	vector<pair<int, int>> hourList;
	for (int i = 0; i < alarmNum; i++) {
		int hour, time;
		cin >> hour >> time;
		hourList.push_back(make_pair(hour, time));
	}
	int goTime;
	cin >> goTime;
	sort(hourList.begin(), hourList.end());

	//for (int i = 0; i < hourList.size(); i++)
		//cout << hourList[i].first << " " << hourList[i].second << endl;
	
	int hour, time;
	cin >> hour >> time;
	pair<int, int> schoolTime = make_pair(hour, time);
	if (schoolTime.first < hourList[0].first) schoolTime.first += 24;
	for (int i = alarmNum - 1; i >= 0; i--) {
		if (isEarly(hourList[i], schoolTime, goTime)) {
			cout << hourList[i].first << " " << hourList[i].second;
			break;
		}
	}
	system("pause");
}