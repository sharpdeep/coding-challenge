#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int pushIndex = 0,popIndex = 0;
        stack<int> myStack;
        if(pushV.empty() && popV.empty()){
            return false;
        }
         
        while(pushIndex < pushV.size() && popIndex < popV.size()){
            while(pushIndex < pushV.size() && pushV[pushIndex] != popV[popIndex]){
                myStack.push(pushV[pushIndex]);
                pushIndex++;
            }
            pushIndex++;
            popIndex++;
 
            while(!myStack.empty() && popIndex < popV.size() && myStack.top() == popV[popIndex]){
                myStack.pop();
                popIndex++;
            }  
        }
         
        if(myStack.empty()){
            return true;
        }else{
            return false;
        }
         
    }
};

int main()
{
	int a[] = {1,2,3,4,5};
	int b[] = {4,3,5,1,2};
	vector<int> pushV(a,a+5);
	vector<int> popV(b,b+5);

	Solution s = Solution();
	bool result = s.IsPopOrder(pushV,popV);

	cout<<"the reslut is:"<<result<<endl;
}

