#数组中只出现一次的数字

##问题：
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

##思路：
首先简化一下问题，如果一个数组里，只有一个数字出现了一次，而其他数字都出现了两次，怎么找出只出现一次的数字。

这里强调出现一次，出现两次很容易让人联想到异或的性质，两个相同的值异或为0，不同的值异或不为0.

那么在这么一个简化的数组里，我们可以从头到尾异或，即在数组(a1,a2,a3,a4,a5)中，求出a1^a2^a3^a4^a5的值，因为里面有两对相同的数字，所以最后的结果就是只出现一次的数字。

那么现在的问题是如何将一个含有两个只出现一次的数字分成两个子数组，每个子数组都包含一个只出现一次的数字，其他的数字都是成对的呢？

如果我们对数组从头到尾异或，最后的结果等同于两个只出现一次的数字的异或，那么这个结果的二进制里的1就表示在这一位两个数字是不同的。那么可以依据这一位来区分两个子数组，每个数组都只包含一次只出现一次的数字，同时因为成对的数字二进制每一位都是相同的，所以也保证了成对的数字不会被拆散。

##Code：
```C++
#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int len = data.size();
		if(len < 2){
            return;
        }
        
        int result = 0;
        for(int i = 0; i < len; i++){
            result ^= data[i];
        }
        
        int index = FindFirst1Index(result);
        *num1 = 0;
        *num2 = 0;
        for(int i = 0; i < len; i++){
            if(IsNumIndex1(data[i],index)){
                *num1 ^= data[i];
            }else{
                *num2 ^= data[i];
            }
        }
    }
    
    int FindFirst1Index(int num){
        unsigned int index = 0;
        while((num&1) == 0 && (index < 8 * sizeof(int))){
            num = num >> 1;
            index++;
        }
        return index;
    }
    
    bool IsNumIndex1(int num,unsigned int index){
        num = num >> index;
        return num&1;
    }
};

int main()
{
	int a[] = {2,4,3,6,3,2,5,5};
	vector<int> array(a,a+8);
	int num1,num2;

	Solution s = Solution();
	s.FindNumsAppearOnce(array,&num1,&num2);

	cout<<"the number appear once is:"<<num1<<","<<num2<<endl;
}
```