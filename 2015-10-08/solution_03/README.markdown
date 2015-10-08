#数字在排序数组中出现的次数

##问题:
统计一个数字在排序数组中出现的次数。

##思路：
针对两种不同的情况有两种不同的解法。

- 对于要查找的数字在数组中重复比较多次的，如(1,2,2,2,2,2,2,2,2,2,3),可以采用双指针两头并进，找到第一个k和最后一个k，然后根据索引计算k的出现次数。但是对于出现次数比较少的，如(1,2,3,4,5,6)查找3，可能会出现O(n)的复杂度。
- 对于(1,2,3,4,5,6)查找3这种，可以采用二分查找，先找到某一个k，然后再从找一个k向两个方向并进。得到最后一个和第一个k，根据索引算出出现次数。

##Code：
###解法一
```C++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size() < 1 || data[0] > k || data[data.size()-1] < k){
            return 0;
        }
         
        int start = 0,end = data.size()-1;
         
        while(start < end && data[start] < k){
            start++;
        }
        while(start < end && data[end] > k){
            end--;
        }
         
        if(end == start && data[start] != k){
            return 0;
        }else{
            return end-start+1;
        }
         
    }
};

int main()
{
	int a[] = {1,2,2,2,2,2,3};
	int k = 2;
	vector<int> array(a,a+7);

	Solution s = Solution();
	int result = s.GetNumberOfK(array,k);

	cout<<result<<endl;
}	
```

###解法二
```C++
#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size() < 1 || data[0] > k || data[data.size()-1] < k){
            return 0;
        }
        
        int start = 0, end = data.size()-1;
        int mid = (start+end)/2;
        while(start < end){
            if(data[mid] > k){
                end = mid-1;
            }
            else if(data[mid] < k){
                start = mid+1;
            }else{
                start = end = mid;
                break;
            }
            
            mid = (start + end)/2;
        }
        
        if(data[start] != k){
            return 0;
        }
        
        while(start >= 0 && data[start] == k){
            start--;
        }
        while(end < data.size() && data[end] == k){
            end++;
        }
        
        return end-start-1;
    }
};

int main()
{
	int a[] = {1,2,3,4,5,6};
	int k = 4;
	vector<int> array(a,a+6);

	Solution s = Solution();
	int result = s.GetNumberOfK(array,k);
	
	cout<<result<<endl;
}
```