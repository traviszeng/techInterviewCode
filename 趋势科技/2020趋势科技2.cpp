/**
С��ȥ���й���������һЩ��Ǯ����ֵ��1Ԫ��5Ԫ��10Ԫ��20Ԫ��50Ԫ��100Ԫ��
���н���ʱһ����Ҫ��MԪ��С���ܺ��棬����������㣬�����ж����ַ�ʽ����������MԪ������Ա�̰����õ�����
��������:
��һ�а���6���������ֱ����1��5��10��20��50��100ÿ����ֵ����Ŀ��

����������6 5 4 3 2 1�������1Ԫ��6�ţ�5Ԫ��5�ţ� 10Ԫ��4�ţ�20Ԫ��3�ţ�50Ԫ��2�ţ�100Ԫ��1��

�ڶ�����һ��������������Ҫ�ն���Ǯ��

���������� 11������ΪҪ��11Ԫ��
�������:
���Ϊһ����������������Ǹ�����ϵĳ���֮�͡�

���磬���ó�����������֣��ָ�Ϊ [1 1 1 1 1 1 5]��[1 5 5]��[1 10],  ��ô��ϳ��ȷֱ�Ϊ7��3��2�������Ϊ12��

ע�⣺�����������������ϣ������ -1��
ʾ��1�������ʾ���������ԣ���̨��������һ�㲻����ʾ��
����
����
6 5 4 3 2 1
11
���
����
12
*/
#include <iostream>

int process(std::string strTargetNum, std::string strValueSequences) {
	//insert your code here:

}

int main(int argc, const char * argv[]) {

	std::string strValueSequences;
	//std::cin >> strValueSequences;
	std::getline(std::cin, strValueSequences);

	std::string strChargeNum;
	std::cin >> strChargeNum;
	targetNum = std::stoi(strChargeNum);

	//process
	int lenSum = process(strChargeNum, strValueSequences);

	std::cout << lenSum << std::endl;


	return 0;
}