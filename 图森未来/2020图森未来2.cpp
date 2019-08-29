#include<iostream>
#include<vector>
using namespace std;
int minPath = 99999;
bool traversal(vector<vector<char>> mat,int rows,int cols,int row,int col,bool *visited,int &pathLen) {
	if (row < 0 || col < 0 || row >= rows || col >= cols)
		return false;

	if ( mat[row][col] == 'E')
	{
		if (pathLen < minPath)
			minPath = pathLen;
		return true;
	}
	bool isPath = false;
	if (row >= 0 && col >= 0 && row < rows && col < cols && (mat[row][col]== '.'||mat[row][col]=='S') && visited[row*cols+col]==false) {
		pathLen++;
		visited[row*cols + col] = true;
		bool up, down, left, right;
		down = traversal(mat, rows, cols, row + 1, col, visited, pathLen);
		up = traversal(mat, rows, cols, row - 1, col, visited, pathLen);
		right = traversal(mat, rows, cols, row, col + 1, visited, pathLen);
		left = traversal(mat, rows, cols, row, col - 1, visited, pathLen);
		isPath = down || up || left || right;
		if (!isPath) {
			--pathLen;
			visited[row*cols + col] = false;
		}
	}
	return isPath;
}


int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> mat;
	bool *visited = new bool[n*m];
	memset(visited, false, n*m);
	pair<int, int> start;
	pair<int, int> end;

	for (int i = 0; i < n; i++) {
		vector<char> temp;
		for (int j = 0; j < m; j++) {
			char tem;
			cin >> tem;
			temp.push_back(tem);
			if (tem == '#')
				visited[i*m + j] = true;
			else if (tem == 'S')
			{	
				start.first = i;
				start.second = j;
			}
			else if (tem == 'E') {
				end.first = i;
				end.second = j;
			}
		}
		mat.push_back(temp);
	}
	int pathLen = 0;
	bool shortestLen = traversal(mat, n,m,start.first, start.second, visited, pathLen);
	cout << minPath;
	system("pause");

}