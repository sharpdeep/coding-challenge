#数组中的逆序对

##问题：
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。如(7,5,6,4)有5个逆序对：(7,5),(7,6),(7,4),(5,4),(6,4)

##思路：
如果采用常规思路，双指针遍历，复杂度将会是$O(n^2)$。这里可以利用类似递归排序的方法：
首先先统计左边和右边的逆序对数目，然后按以下方法计算总的逆序对：
![](2015-10-08-00.png)

实际上最后的data数组已经是一个排好序的数组了，所以这个过程其实就是一个归并排序的过程。

这个算法的时间复杂度是$O(nlogn)$,但是同时需要一个辅助数组，所以空间复杂度是$O(n)$

##Code：
```C++
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        return MergeSort(data,0,data.size()-1);
    }
    
    int MergeSort(vector<int> &data, int start, int end){
        if(start >= end){
            return 0;
        }
        
        int mid = (start+end)/2;
        int left = MergeSort(data,start,mid);//统计左边的逆序对
        int right = MergeSort(data,mid+1,end);//统计右边的逆序对
        
        int preIndex = mid;
        int backIndex = end;
        int copyIndex = end;
        int count = 0;
        vector<int> copy(data);
        
        while(preIndex >= start && backIndex >= mid+1){
            if(data[preIndex] > data[backIndex]){
                copy[copyIndex--] = data[preIndex--];
                count += (backIndex-mid);
            }
            else{
                copy[copyIndex--] = data[backIndex--];
            }
        }
        while(preIndex >= start){
            copy[copyIndex--] = data[preIndex--];
        }
        while(backIndex >= mid+1){
            copy[copyIndex--] = data[backIndex--];
        }
        
        for(int i = start; i <= end; i++){
            data[i] = copy[i];
        }
        
        return count+left+right;
    }
};

int main()
{
	int a[] = {1,2,1,2,1};
	vector<int> array(a,a+5);

	Solution s = Solution();
	int count = s.InversePairs(array);

	cout<<count<<endl;
}
```



