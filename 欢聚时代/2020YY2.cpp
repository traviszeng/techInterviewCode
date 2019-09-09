/**
大致的意思是从层序遍历恢复一个完全二叉树 在输出它的中序遍历序列
AC
*/

#include<iostream>
#include<queue>
using namespace std;
struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int v):val(v),left(nullptr),right(nullptr) {
		val = v;
	}
};

void inorderTraversal(TreeNode* root) {
	if (root == nullptr) return;
	if (root->left == nullptr && root->right == nullptr) {
		cout << root->val << endl;
		return;
	}
		
	if (root->left != nullptr) inorderTraversal(root->left);
	cout << root->val << endl;
	if (root->right != nullptr) inorderTraversal(root->right);
}

int main() {
	int height;
	cin >> height;
	int temp;
	queue<TreeNode*> q;
	//vector<int> vec;
	int sum = 0;
	/*while (cin >> temp) {
		sum += 1;
		vec.push_back(temp);
	}*/
	
	int count = 0;
	cin >> temp;
	TreeNode* root = new TreeNode(temp);
	q.push(root);
	count++;
	while (!q.empty() &&cin>>temp) {
		TreeNode* node = q.front();
		q.pop();
		bool hasLeft = false;
		if (node->left == nullptr) {
			node->left = new TreeNode(temp);
			count++;
			q.push(node->left);
			hasLeft = true;
			//if (count == sum) break;
		}
		if(hasLeft)
			cin >> temp;

		if (node->right == nullptr) {
			node->right = new TreeNode(temp);
			count++;
			q.push(node->right);
			//if (count == sum) break;
		}
		
	}

	inorderTraversal(root);
	system("pause");


}