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
