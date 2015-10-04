#连续子数组的最大和

##问题：
输入一个整型数组，数组中有正数也有负数。数组中一个或者连续多个整数组成一个子数组。求所有子数组的和的最大值。

##思路：
一开始想到的是穷举所有可能的子数组，并比较得到最大值，这个算法的复杂度大概是$O(n^2)$.

以数组{1,-2,3,7,-15,1,2,2}为例，当index=0时，sum=1；当index=1时，sum=1+(-2)=-1，当index=3时，sum=-1+3=2.此时前面两个数的和加上第三个数还比第三个数字本身小，说明不应该从第一个开始记起，而应该从第三个开始记起。以此类推。

##Code：
```C++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() == 0){
            return 0;
        }
     
        int sum = 0,maxSum = array[0];
        
        for(int i = 0; i < array.size(); i++){
            sum = max(sum+array[i],array[i]);
            maxSum = max(sum,maxSum);
        }
        
        return maxSum;
    }
};

int main()
{
	int a[] = {6,-3,-2,7,-15,1,2,2};
	vector<int> array(a,a+8);
	
	Solution s = Solution();
	int maxSum = s.FindGreatestSumOfSubArray(array);

	cout<<"the max sum of array is:"<<maxSum<<endl;
}
```