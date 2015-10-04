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
