#include<iostream>
#include<queue>
#include<vector>
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
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        vector<int> result;
		queue<TreeNode*>  myQueue;
        
        if(root == NULL){
            return result;
        }
        myQueue.push(root);
        
        while(!myQueue.empty()){
            TreeNode* node = myQueue.front();
            myQueue.pop();
            result.push_back(node->val);
            if(node->left){
                myQueue.push(node->left);
            }
            if(node->right){
                myQueue.push(node->right);
            }
        }
        
        return result;
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
	vector<int> result = s.PrintFromTopToBottom(tree);

	cout<<"print tree node from top tp bottom:"<<endl;
	for(int i = 0; i < result.size(); i++){
		cout<<result[i]<<",";
	}
}
