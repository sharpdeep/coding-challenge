#树的子结构

##问题：
输入两颗二叉树A，B，判断B是不是A的子结构。

##思路
**递归**：tree2是tree1的子树或者tree2是tree1左子树的子树或者tree2是tree1右子树的子树。利用`||`和`&&`的短路原则可以减少代码量。

##Code：
```C++
#include<iostream>
#include<stdlib.h>

using namespace std;

struct TreeNode{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):
		val(x),left(NULL),right(NULL){
		
		}
};

class Solution {
public:
	
	bool subTree(TreeNode* tree1,TreeNode* tree2){
		if(tree2 == NULL){
			return true;
		}
		if(tree1 == NULL){
			return false;
		}
		return tree1->val == tree2->val && subTree(tree1->left,tree2->left) && subTree(tree1->right,tree2->right);
	}

	bool HasSubTree(TreeNode* pRoot1,TreeNode* pRoot2){
		if(pRoot1 == NULL || pRoot2 == NULL){
			return false;
		}
		return subTree(pRoot1,pRoot2) || HasSubTree(pRoot1->left,pRoot2) || HasSubTree(pRoot1->right,pRoot2);
	}
};

int main()
{
	TreeNode* t1 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* t2 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* node = t1;
	
	t1->val = 0;
	for(int i = 1; i < 10; i+=2){
		TreeNode* left = (TreeNode*)malloc(sizeof(TreeNode));
		TreeNode* right = (TreeNode*)malloc(sizeof(TreeNode));
		left->val = i;
		right->val = i+1;
		node->left = left;
		node->right = right;
		node = node->left;
	}

	t2->val = 1;
	TreeNode* left = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* right = (TreeNode*)malloc(sizeof(TreeNode));
	left->val = 3;
	right->val = 4;
	t2->left = left;
	t2->right = right;

	Solution s = Solution();
	cout<<"t1 has sub tree t2:"<<s.HasSubTree(t1,t2)<<endl;

}

```