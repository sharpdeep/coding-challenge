#数组中出现次数超过一半的数字

##问题：
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。输入数组也可能不满足超过一半的要求，如[1,2,3,4,5]。

##思路：
《编程之美》中“寻找水王”一章中出现过类似题目。解决的算法有二：

- 算法一：首先先对所有数字排序，那么排序后的数组中间的一个数就是出现次数超过一半的数字。可以自己举个例子看看为什么。但是这个算法需要排序，即使是用快排，也需要O(nlogn)的时间。
- 算法二：如果每次都从数组中删除两个不同的数字，那么最后剩下来的一个或者一组相同的数字一定就是最多的那个。(可以把数组分成两部分，一部分是相同的超过一半的部分，一部分是另外可能不相同的少于一半的部分。即使在最坏的情况下，即另外部分也完全相同，也能满足条件)。这个算法的复杂度大概在O(n)的级别。

##Code：
```C++
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
```