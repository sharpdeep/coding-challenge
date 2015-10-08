#判断平衡二叉树

##问题：
输入一棵二叉树，判断该二叉树是否是平衡二叉树。

##思路：

- 解法一，求左右子树的高度，如果左右子树平衡并且高度相差[-1,1],则平衡。子树高度和判断平衡分开操作，但是这样同一个节点可能被多次遍历，效率不高。
- 解法二，在判断平衡的同时也算出高度。

##Code：
###解法一
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
    int TreeDepth(TreeNode* tree){
        if(!tree){
            return 0;
        }
         
        int left = TreeDepth(tree->left);
        int right = TreeDepth(tree->right);
         
        return left>right?(left+1):(right+1);
    }
     
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot){
            return true;
        }
         
        int leftH = TreeDepth(pRoot->left);
        int rightH = TreeDepth(pRoot->right);
         
        if(leftH == rightH+1 || rightH == leftH+1 || leftH == rightH){
            return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
        }else{
            return false;
        }
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
	bool r = s.IsBalanced_Solution(tree);
	string result = r==1?"true":"false";

	cout<<result<<endl;
}
```

###解法二
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
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth;
        return IsBalanced(pRoot,&depth);
    }
     
    bool IsBalanced(TreeNode* tree, int* depth){
        if(!tree){
            *depth = 0;
            return true;
        }
         
        int left,right;
         
        if(IsBalanced(tree->left,&left) && IsBalanced(tree->right,&right)){
            int diff = left - right;
            if(diff >= -1 && diff <= 1){
                *depth = 1+(left>right?left:right);
                return true;
            }
        }
         
        return false;
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
	bool r = s.IsBalanced_Solution(tree);
	string result = r==1?"true":"false";

	cout<<result<<endl;
}
```