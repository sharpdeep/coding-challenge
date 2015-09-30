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
