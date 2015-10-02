#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        
        if(numbers.size() == 0){
            return 0;
        }
        if(numbers.size() == 1){
            return numbers[0];
        }
        
        int result = numbers[0];
        int times = 1;
        
        for(int i = 1; i < numbers.size(); i++){
            if(times == 0){
                result = numbers[i];
                times = 1;
                continue;
            }
            if(numbers[i] == result){
                times++;
            }else{
                times--;
            }
        }
        
        //判断result是不是结果
        times = 0;
        for(int i = 0; i < numbers.size(); i++){
            if(result == numbers[i]){
                times++;
            }
        }
        
        if(!(times > numbers.size()/2)){
            return 0;
        }else{
         	return result;   
        }
    }
};

int main()
{
	int a[] = {1,2,3,2,2,2,5,4,2,2};
	vector<int> array(a,a+10);

	Solution s = Solution();
	int result = s.MoreThanHalfNum_Solution(array);

	cout<<"the number more than half is:"<<result<<endl;
}
