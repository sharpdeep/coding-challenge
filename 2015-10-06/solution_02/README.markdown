#第一次只出现一次的字符位置

##问题：
在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符的位置。若为空串，返回-1。位置索引从0开始。

##思路：
字符ASCII编码总共有256，因此可以采用一个256长度的数组，利用字符到数组索引的哈希，计算每个字符出现的次数。

总共需要2次扫描，第一次扫描是为了建立hash表，时间复杂度是O(n)，第二次扫描是找出出现以此的字符索引，时间复杂度也是O(n),总共的时间复杂度是O(n)。同时需要一个256长度的数组，空间复杂度是O(1).

##Code：
```C++
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.size() == 0){
            return -1;
        }
        
        int hashT[256] = {0};
        
        for(int i = 0; i < str.size(); i++){
            hashT[str[i]]++;
        }
        
        for(int i = 0; i < str.size(); i++){
            if(hashT[str[i]] == 1){
                return i;
            }
        }
        
        return -1;
        
    }
};

int main()
{
	string str = "solution";	

	Solution s =Solution();
	int index = s.FirstNotRepeatingChar(str);

	cout<<"the index of First not repeating char of "<<str<<" is "<<index<<endl;
}
```