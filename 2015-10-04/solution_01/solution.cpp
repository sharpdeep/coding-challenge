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
