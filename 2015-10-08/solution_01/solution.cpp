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
