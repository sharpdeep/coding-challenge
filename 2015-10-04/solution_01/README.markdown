#最小的K个数

##问题：
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,不要求排序输出。

##思路：
首先选取k个数，并找出k个数中的最大值max。从第k+1个数x开始，与max比较。  
x如果小于最大值，则从k个数中删除max，并将x加入k个数中，并重新选出k个数的最大值。

其中选取最大值可以用最大堆。这里直接使用了逐个比较。

#Code：
```C++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int FindGreatIndexNumberOfK(vector<int> input){
        int greatIndex = 0;
        for(int i = 1; i < input.size(); i++){
            if(input[i] > input[greatIndex]){
                greatIndex = i;
            }
        }
        return greatIndex;
    }
     
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        int greatIndex;
        if(input.size() < k || k == 0){
            return result;
        }
     
        for(int i = 0; i < k; i++){
            result.push_back(input[i]);
        }  
         
        greatIndex = FindGreatIndexNumberOfK(result);
     
        for(int i = k; i < input.size(); i++){
            if(input[i] < result[greatIndex]){
                result[greatIndex] = input[i];
                greatIndex = FindGreatIndexNumberOfK(result);
            }
        }
     
        return result;
    }
};

int main()
{
	int a[] = {4,5,1,6,2,7,3,8};
	vector<int> array(a,a+8);

	Solution s = Solution();
	vector<int> result = s.GetLeastNumbers_Solution(array,4);

	cout<<"the 4 least of array is:"<<endl;
	for(int i = 0; i < result.size(); i++){
		cout<<result[i]<<",";
	}
}
```

