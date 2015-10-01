#include<iostream>
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
    vector<vector<int> > Path(TreeNode* root, int target, vector<int> path,vector<vector<int> > pathList)
    {
        path.push_back(root->val);
        if(!root->left && !root->right && root->val == target){
            pathList.push_back(path);
            return pathList;
        }
        
        if(!root->left && !root->right){
            path.pop_back();
            return pathList;
        }
        
        if(root->left){
            pathList = Path(root->left,target-(root->val),path,pathList);
        }
        if(root->right){
            pathList = Path(root->right,target-(root->val),path,pathList);   
        }
        
        return pathList;
    }
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<int> path;
        vector<vector<int> > pathList; 
        
        if(!root){
        	return pathList;     
        }
        
        pathList = Path(root,expectNumber,path,pathList); 
        
        return pathList;
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
    vector<vector<int> >result = s.FindPath(tree,17);

    cout<<"the path that sum is 17 is:"<<endl;
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[0].size(); j++){
	    cout<<result[i][j]<<",";
  	}
	cout<<endl;
    }

}
