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
