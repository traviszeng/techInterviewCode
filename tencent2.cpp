/*
问题描述
	妞妞公主新得到一块白色棋盘。这块棋盘共有n行m列，任意相邻的两个格子都是不同的颜色（黑或白），坐标位（1,1）的格子是白色的。
	这一天牛牛来看妞妞公主时，牛牛公主正望着棋盘发呆。牛牛看妞妞公主闷闷不乐的样子，便对妞妞公主说：“只要你告诉我n和m，我能马上算出黑色方块的白色方块的数量。”
	“这太简单了。”妞妞公主想了一会，“我会在这n行m列中选择一个左下角坐标位（x0，y0）。右上角坐标为（x1，y1）的矩形，把这个矩形里的共（x1-x0+1）*（y1-y0+1）个方块全部涂白。你还能马上算出黑色方块和白色方块的数量吗？”
	“这太简单了。”牛牛自信一笑，“你还可以在执行涂白操作后再选择一个左下角坐标为（x2，y2），右上角坐标为（x3，y3）的矩形，把这个矩形里的方块全部涂黑。我依然能马上算出黑色方块和白色方块的数量。”
	妞妞公主终于惊讶地睁大了眼睛，于是抛出了她的T次提问。
	聪明的牛牛当然会做了，但是他想把这个问题交给你，请帮牛牛算出每次提问棋盘的黑白方块数目吧。
输入描述
	第一行一个整数T,表示妞妞公主一共提问了T次。 接下来3T行，
	第（1+3i）行两个整数n，m。表示第i次提问时棋盘的大小；
	第（2+3i）行四个整数x0,y0,x1,y1。表示第i次提问时涂白操作选取的两个坐标。
	第（3+3i）行四个整数x2,y2,x3,y3。表示第i次提问时涂黑操作选取的两个坐标。
	1<=T<=10000，1<=x<=n<=1000000000，1<=y<=m<=1000000000，x0<=x1，y0<=y1，x2<=x3，y2<=y。
输出描述
	共T行，每行两个整数分别表示白色方块的数量和黑色方块的数量。
输入样例
	3
	1 3
	1 1 1 3
	1 1 1 3
	3 3
	1 1 2 3
	2 1 3 3
	3 4
	2 1 2 4
	1 2 3 3
输出样例
	0 3
	3 6
	4 8
**/

#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long n, m;
		cin >> n >> m;
		long long white, black;
		
		if (n*m % 2 == 0) {
			white = n * m / 2;
			black = white;
		}
		else {
			white = n * m / 2 + 1;
			black = n * m / 2;
		}

		long long x0, x1, y0, y1;

		cin >> x0 >> y0 >> x1 >> y1;
		long long num = (x1 - x0 + 1)*(y1 - y0 + 1);
		if (num % 2 == 1) {
			if ((x1 % 2 == 0 && y0 % 2 == 0) || (x1 % 2 == 1 && y0 % 2 == 1)) {
				//左上角为白色
				white += num / 2;
				black -= num / 2;
			}
			else {
				//左上角为黑色
				white += (num+1) / 2 ;
				black -= (num+1) / 2;
			}
		}
		else {
			white += num / 2;
			black -= num / 2;
		}
		//涂黑色
		long long x2, x3, y2, y3;
		cin >> x2 >> y2 >> x3 >> y3;
		num = (x3 - x2 + 1)*(y3 - y2 + 1);
		if (num % 2 == 1) {
			if ((x3 % 2 == 0 && y2 % 2 == 0) || (x3 % 2 == 1 && y2 % 2 == 1)) {
				//左上角为白色
				white -= (num+1) / 2 ;
				black += (num+1) / 2 ;
			}
			else {
				//左上角为黑色
				white -= num / 2 ;
				black += num / 2;
			}
		}
		else {
			white -= num / 2;
			black += num / 2;
		}


		//看两次涂的部分是否存在重合
		//而第二步计算依然按照没涂白之前的计算，也就是少算了第一步之前的黑方块个数
        //也就是第一步多计算的白方块area，
        //最后白方块个数-area，黑方块个数+area
		long long a, b, c, d;
		a = max(x0, x2);
		b = max(y0, y2);
		c = min(x1, x3);
		d = min(y1, y3);
	
		long long area;
		if (c < a || d < b)
		{
			area = 0;
		}
		else {
			if ((a + b) % 2 == 1) {
				area = ((c - a + 1)*(d - b + 1))/2 +1;
			}
			else
				area = (c - a + 1)*(d - b + 1)/2 ;
		}
		white -= area;
		black += area;


		cout << white << " " << black << endl;


	}
	system("pause");
}