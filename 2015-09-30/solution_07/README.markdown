#栈的压入/弹出序列

##问题：
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列`1,2,3,4,5`是某栈的压入顺序，序列`4,5,3,2,1`是该压栈序列对应的一个弹出序列，但`4,3,5,1,2`就不可能是该压栈序列的弹出序列。

##思路：
利用栈和两个索引index，pushIndex指向pushV，popIndex指向popV，

- 如果检测到pushIndex和popIndex指向的不同，说明不是出栈的时候，这时候入栈并后移pushIndex。
- 如果检测到pushIndex和popIndex指向内容相同，说明这时候该出栈了，当然这时候主要不入栈即可(pushIndex++和popIndex++)
- 出栈后要再检测栈中是否还有可以出栈的。(pushIndex和myStack.top()是否相同)。
- 最后判断myStack中是否已空。

##Code：
```C++
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

```