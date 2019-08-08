/**
小安去超市购物，妈妈给了一些零钱，面值有1元，5元，10元，20元，50元，100元。
超市结账时一共需要花M元，小安很好奇，如果不用找零，可以有多少种方式的组合来组成M元，你可以编程帮他得到答案吗？
输入描述:
第一行包含6个整数，分别代表1、5、10、20、50、100每种面值的数目。

假设输入是6 5 4 3 2 1，则代表1元有6张，5元有5张， 10元有4张，20元有3张，50元有2张，100元有1张

第二行是一个整数，代表需要凑多少钱。

假设输入是 11，含义为要凑11元。
输出描述:
输出为一个整数，这个整数是各种组合的长度之和。

例如，最后得出的组合有三种，分给为 [1 1 1 1 1 1 5]、[1 5 5]、[1 10],  那么组合长度分别为7、3、2，则其和为12。

注意：如果不存在这样的组合，请输出 -1。
示例1输入输出示例仅供调试，后台判题数据一般不包含示例
输入
复制
6 5 4 3 2 1
11
输出
复制
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