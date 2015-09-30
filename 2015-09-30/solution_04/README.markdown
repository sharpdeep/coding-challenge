#二叉树的镜像

##问题：
操作给定的二叉树，将其变换为源二叉树的镜像。
举例如下：
```
   	        8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
```

##思路：
**递归**：首先将左子树和右子树分别递归调用Mirror得到左右子树的镜像，然后将左子树和右子树调换即可。
边界条件是节点为NULL时。

##Code：
```C++
#include<iostream>
#include<stdlib.h>

using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
		if(pRoot == NULL){
            return;
        }
        TreeNode* node;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        node = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = node;
    }
};

int main()
{
	TreeNode* t1 = (TreeNode*)malloc(sizeof(TreeNode));
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

	Solution s = Solution();
	s.Mirror(t1);
}
```