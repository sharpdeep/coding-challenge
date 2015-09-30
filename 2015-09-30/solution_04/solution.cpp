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

