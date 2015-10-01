#include<iostream>
#include<vector>

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
    void inOrder(TreeNode* p, vector<TreeNode *> &nodes){
        if(p){
            inOrder(p->left,nodes);
            nodes.push_back(p);
            inOrder(p->right,nodes);
        }
    }
    
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree){
            return NULL;
        }
        
        vector<TreeNode *> nodes;
        inOrder(pRootOfTree,nodes); //中序遍历
        
        for(int i = 0; i < nodes.size()-1; i++){
           nodes[i]->right = nodes[i+1];
           nodes[i+1]->left = nodes[i];
        }
        
        return nodes[0];
    }
};

int main()
{
	TreeNode* head = new TreeNode(16);
	TreeNode* left = new TreeNode(10);
	TreeNode* right = new TreeNode(20);

	head->left = left;
	head->right = right;

	Solution s = Solution();
	TreeNode* result = s.Convert(head);

	cout<<result->val<<"->"<<result->right->val<<"->"<<result->right->right->val<<endl;
}
