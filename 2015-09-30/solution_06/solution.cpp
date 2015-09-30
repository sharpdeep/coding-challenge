#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
private:
    stack<int> myStack;
    stack<int> minStack;
public:
    void push(int value) {
        myStack.push(value);
        if(minStack.empty()){
            minStack.push(value);
        }else{
            if(minStack.top() >= value){
                minStack.push(value);
            }
        }
    }
    void pop() {
        int value = myStack.top();
        if(value <= minStack.top()){
            minStack.pop();
        }
        myStack.pop();
    }
    int top() {
        return myStack.top();
    }
    int min() {
        return minStack.top();
    }
};

int main()
{
	Solution s = Solution();
	s.push(10);
	s.push(31);
	s.push(20);
	s.push(16);
	s.push(7);

	cout<<"now min value is: "<<s.min()<<endl;

	s.pop();
	s.pop();

	cout<<"after pop two value, the min value is: "<<s.min()<<endl;

}
