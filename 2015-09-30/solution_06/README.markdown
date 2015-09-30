#包含min函数的栈

##问题：
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

##思路：
利用两个栈，一个栈`myStack`用于普通的存取，一个栈`minStack`用于存储最小值。

- 当有新值push进来时，先判断是否比`minStack`中第一个值小，是的话push进`minStack`，否则只push进`myStack`
- 当需要pop的时候，必须判断将要pop的值是否是`minStack`中的，如果是，需要从`minStack`中pop出去。
- 取最小值时，只需要取`minStack`中最顶的元素即可。

#Code：
```C++
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
```





