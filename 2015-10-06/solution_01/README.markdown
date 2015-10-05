#丑数

##问题：
把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

##思路：
建立4个队列：q,q2,q3,q5。q是存储丑数的队列，q2是存储含有2因子的丑数队列，以此类推。

首先将1入q，然后将2\*1,3\*1,5\*1分别入q2,q3,q5。第二个丑数就在三个队列中找最小的，假设找到的丑数是x，则有三种情况：

- 如果x在q2中，则2x，3x，5x入q2，q3，q5，x出队；
- 如果x在q3中，则3x，5x入q3，q5，x出队；
- 如果x在q5中，则5x入q5，x出队.

为什么x在q3中不更新q2，x在q5中不更新q2，q3呢？

假设x在q3中，此时x是q2，q3，q5中最小的丑数。如果更新q2，则入q2的数字是2x，其中包含了3的因数，所以也可以看成2\*3y=3z。其中y=x/3,z=2y=2x/3。z < x,z小于x，说明z在x之前，那时更新q3为3z=2x，所以如果更新q2为2x将会出现重复。

##Code：
```C++
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
```



