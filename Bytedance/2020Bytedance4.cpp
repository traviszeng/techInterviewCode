/*跑步
时间限制：C / C++ 1秒，其他语言 2秒
空间限制：C / C++ 32768K，其他语言 65536K
64bit IO Format : %lld
本题可使用本地IDE编码，不做跳出限制，编码后请点击“保存并调试”按钮进行代码提交。
题目描述
小明练习跑步，他家附近的街道是棵树，这棵树上的点按1到n标号，任意两点间互相可达，并且有且仅有一条路，每条路的距离都是1，需要在树上找一条路来跑，小明对3很感兴趣，所以他想知道所有跑道距离和 % 3 = 0，1，2的道路总长度一共各有多长。即树上任意两点间距离 % 3 = k的距离和。
输入描述 :
第一行一个n，点数n <= 1e5

接下来n - 1行每行u，v一条无向边
输出描述 :
一行3个整数，分别代表 % 3 = 0，1，2的两点距离的距离和

结果取模1e9 + 7
示例1输入输出示例仅供调试，后台判题数据一般不包含示例
输入
复制
3
1 2
2 3
输出
复制
0 2 2
说明
长度 % 3 = 0的距离不存在， = 1的有两条1 - 2，2 - 3总长度是2， = 2的有1条，1 - 3，总长度是2
备注 :
前4个case小数据点数3, 10, 100, 1000, 10000

之后数据全部100000个点*/