#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
    	vector<int> q2,q3,q5;
        int index2 = 0,index3 = 0,index5 = 0;
        vector<int> uglys;
        
        if(index <= 0){
            return 0;
        }
        
        
        for(int i = 0; i < index; i++){
            if(i == 0){
                uglys.push_back(1);
                q2.push_back(2);
                q3.push_back(3);
                q5.push_back(5);
                continue;
            }
            
            int min = q2[index2] < q3[index3]?q2[index2]:q3[index3];
            min = min < q5[index5]?min:q5[index5];
            
            if(min == q2[index2]){
                q2.push_back(min*2);
                q3.push_back(min*3);
                uglys.push_back(q2[index2++]);
            }
            else if(min == q3[index3]){
                q3.push_back(min*3);
                uglys.push_back(q3[index3++]);
            }else{
                uglys.push_back(q5[index5++]);
            }
            
            q5.push_back(min*5);
        }
        
        return uglys.back();
    }
};

int main()
{
	int n = 6;

	Solution s = Solution();
	int result = s.GetUglyNumber_Solution(n);

	cout<<"the "<<n<<" times of ugly numbers is: "<<result<<endl;
}
