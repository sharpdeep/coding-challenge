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
