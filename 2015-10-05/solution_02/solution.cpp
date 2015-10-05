#include<iostream>

using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int result = 0;
    	for(long long index = 1; index <= n; index *= 10){
            result += (n/index + 8)/10*index+(n/index%10==1)*(n%index+1);
        }
        
        return result;
    }
};

int main()
{
	int n = 13;
	Solution s = Solution();
	int result = s.NumberOf1Between1AndN_Solution(n);
	
	cout<<"Number of 1 Between 1 and "<<n<<" is:"<<result<<endl;
}
