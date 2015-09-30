#二叉搜索树的后序遍历序列

##问题：
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

##思路：
二叉搜索树的特点是：左子树的节点都比根节点小，右子树的节点都比根节点大。

所以判断方法为：将序列分为两部分，一部分都小于最后一个元素，一部分都大于最后一个元素。如果这时候出现第三部分说明不是BST。

在对两部分分别进行BST判断。

边界条件是：当输入序列为空时，返回false。当输入序列个数小于等于2时，返回true。(因为这时候肯定是BST后序遍历序列）

##Code：
```C++
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
	vector<int> left;
        vector<int> right;
        int index = 0;
        int lastIndex = sequence.size()-1;
        if(sequence.empty()){
            return false;
        }
        if(sequence.size() <= 2){
            return true;
        }
        
        while(index < lastIndex && sequence[index] < sequence[lastIndex]){
            left.push_back(sequence[index]);
            index++;
        }
        
        while(index < lastIndex && sequence[index] > sequence[lastIndex]){
            right.push_back(sequence[index]);
            index++;
        }
        
        if(index == lastIndex){
            return (left.empty() || VerifySquenceOfBST(left)) && (right.empty() || VerifySquenceOfBST(right));
        }else{
            return false;
        }
    }
};

int main()
{
	int a[] = {1,2,3,4,5};
	vector<int> sequence(a,a+5);

	Solution s = Solution();
	string  result = s.VerifySquenceOfBST(sequence)?"true":"false";
	
	cout<<"list: ";
	for(int i = 0; i < sequence.size(); i++){
		cout<<sequence[i]<<",";	
	}
	cout<<" is BST:"<<result<<endl;
}
```