#二叉树的深度

##问题：
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

##思路:
递归，深度=max(左子树深度，右子树深度)+1

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
    int TreeDepth(TreeNode* pRoot)
    {
    	if(!pRoot){
            return 0;
        }
        
        int leftH = TreeDepth(pRoot->left);
        int rightH = TreeDepth(pRoot->right);
        
        int childH = leftH > rightH?leftH:rightH;
        
        return childH+1;
    }
};

int main()
{
 	TreeNode* tree = (TreeNode*)malloc(sizeof(TreeNode));
    	TreeNode* p = tree;

    	tree->val = 0;
    	for(int i = 1; i < 10; i+=2){
        	TreeNode* left = (TreeNode*)malloc(sizeof(TreeNode));
       		TreeNode* right = (TreeNode*)malloc(sizeof(TreeNode));
        	left->val = i;
        	right->val = i+1;
        	p->left = left;
        	p->right = right;
        	if((i-1)%4 == 0){
        	    p = left;   
        	}else{
        	    p = right;
        	}
    	}	

	Solution s = Solution();
	int depth = s.TreeDepth(tree);

	cout<<depth<<endl;
}
```




