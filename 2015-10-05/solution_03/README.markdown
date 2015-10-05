#把数组排成最小的数

##问题：
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

##思路：
如果输入的都是一位数的数字，很容易想到最大的数字应该在后面，最小的的数字应该前面。

但是如果不是一位数，这个就不一定了，如(3,32,321)。

这时可以自己定义一个比较的规则。假设有两个数字n和m，拼接起来有两种情况，`nm`和`mn`。如果`nm<mn`,就应该输出`nm`，这时我们定义n小于m。如果`nm>mn`，就应该输出`mn`，我们定义此时n大于m。这里的**小于**和**大于**并不是真正的小于大于。

从小到大排序后，从头到尾拼接成string返回即可。

##Code：
```C++
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> strNumbers;
        string result;
        
        if(numbers.size() == 0){
            return result;
        }
        
        //int 转 string
        for(int i = 0; i < numbers.size(); ++i){
        	stringstream ss;
            ss<<numbers[i];
            strNumbers.push_back(ss.str());
        }
        
        sort(strNumbers.begin(),strNumbers.end(),compare);
        
        //拼接
        for(int i = 0; i < numbers.size(); ++i){
            result.append(strNumbers[i]);
        }
        
        return result;
    }

    static bool compare(const string s1,const string s2){
        string comb1 = s1+s2;
        string comb2 = s2+s1;
        return comb1 < comb2;
    }

};

int main()
{
	int a[] = {3,32,321};
	vector<int> array(a,a+3);
	
	Solution s = Solution();
	string result = s.PrintMinNumber(array);

	cout<<"the min number is: "<<result<<endl;
}
```