/*
���ӽ���ȥ�Ͽ�
ʱ�����ƣ�C/C++ 1�룬�������� 2��
�ռ����ƣ�C/C++ 32768K���������� 65536K
64bit IO Format: %lld
�����ʹ�ñ���IDE���룬�����������ƣ���������������沢���ԡ���ť���д����ύ��
��Ŀ����
С������˯��ͷ�����������˺ܶ����ӣ�ֻ�����������ʱ�����Ż��ѹ������Ҿ������𴲡���������������ҪX���ӵ�����ң��Ͽ�ʱ��Ϊ�����AʱB�֣��������������ʲôʱ����
��������:
ÿ���������һ����������

ÿ�����������ĵ�һ�а���һ������������ʾ���ӵ�����N(N<=100)

��������N��ÿ�а���������������ʾ������������ʱ��ΪHi(0<=A<24)ʱMi(0<=B<60)��

��������һ�а���һ����������ʾ������������ҪX(0<=X<=100)���ӵ������

��������һ�а���������������ʾ�Ͽ�ʱ��ΪA(0<=A<24)ʱB(0<=B<60)��

���ݱ�֤������һ�����ӿ�����ţţ��ʱ�������
�������:
�������������ʾţţ������ʱ��
ʾ��1�������ʾ���������ԣ���̨��������һ�㲻����ʾ��
����
����
3
5 0
6 0
7 0
59
6 59
���
����
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