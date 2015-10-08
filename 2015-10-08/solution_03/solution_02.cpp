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
