/**
ģ��2048��Ϸ
ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 65536KB���������� 589824KB
��Ŀ������
��2048����һ�����ŵ�������Ϸ����Ϸ�У�ÿ�������ϵ����ֶ���2���ݣ����ַ�������ָ������������������ƶ����������������ͬ�ķ������ƶ�����ײ�����Ǿͻ�ϳ�һ���µķ��顣������ͼΪ4*4���ӵ���Ϸ��0��ʾ����Ϊ�գ�ͼaΪ�ƶ�ǰ�����е����֣�ͼbΪͼa���ƺ�Ľ��:

0 0 2 4
0 2 2 2
0 4 2 2
8 8 2 2
ͼa
2 4 0 0
4 2 0 0
4 4 0 0
16 4 0 0
ͼb
�ʣ�����n*m�ľ���M��0��ʾ�ո��ӣ���0������ʾ���ƶ������֣�����2048���ƶ���������������Ʋ�����ľ�������

����
����n������

��1��Ϊ��������

��2�е���n��Ϊ����ÿ�����ݣ�m�������ÿո����

���
������ƺ�ľ��󣬵���Ԫ���ÿո���������д��޿ո�


��������
4
0 0 2 4
0 2 2 2
0 4 2 2
8 8 2 2
�������
2 4 0 0
4 2 0 0
4 4 0 0
16 4 0 0
*/

#include <iostream>
#include <vector>
#include <numeric>
#include<string>

#include <limits>

using namespace std;


/*������������������ʵ����ĿҪ��Ĺ���
��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^
******************************��ʼд����******************************/
void solution(vector < string > input) {
	vector<vector<int>> num;
	int temp = 0;
	for (int i = 0; i < input.size(); i++) {
		vector<int> tempNum;
		temp = 0;
		for (int j = 0; j < input[i].length(); j++) {
			if (input[i][j] <= '9'  && input[i][j] >= '0') {
				temp *= 10;
				temp += input[i][j] - '0';

			}
			else {//�����ո�
				tempNum.push_back(temp);
				temp = 0;
			}
		}
		tempNum.push_back(temp);
		num.push_back(tempNum);
	}
	for (int i = 0; i<num.size(); i++) {
		for (int j = 0; j < num[i].size()-1; j++) {
			if (num[i][j]!=0 && num[i][j] == num[i][j + 1]) {
				num[i][j] = num[i][j] * 2;
				num[i][j + 1] = 0;
			}
		}
	}

	for (int i = 0; i < num.size(); i++) {
		int sumOfZero = 0; //���0�ĸ���
		for (auto it = num[i].begin(); it != num[i].end();) {
			if (*it == 0) {
				it = num[i].erase(it);
				sumOfZero++;
				//num[i].push_back(0);
			}
			else {
				it++;
			}
		}
		for (int k = 0; k < sumOfZero; k++)
			num[i].push_back(0);
	}

	for (int i = 0; i < num.size(); i++) {
		for (int j = 0; j < num[i].size(); j++) {
			cout << num[i][j];
			if (j != num[i].size() - 1) cout << " ";
		}
		cout << endl;
	}


}
/******************************����д����******************************/


int main() {
	string res;

	int _input_size = 0;
	cin >> _input_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	vector<string> _input;
	string _input_item;
	for (int _input_i = 0; _input_i<_input_size; _input_i++) {
		getline(cin, _input_item);
		_input.push_back(_input_item);
	}

	solution(_input);

	//cout << res << endl;
	system("pause");
	return 0;

}
