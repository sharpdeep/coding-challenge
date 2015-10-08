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
