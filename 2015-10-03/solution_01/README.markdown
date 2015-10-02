#字符串的排列

##问题：
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串`abc`,则打印出由字符a,b,c所能排列出来的所有字符串`abc,acb,bac,bca,cab和cba`。 **结果请按字母顺序输出.**

##思路：
解题思路是从网上找到的，利用的是递归的方法，确定第一位，然后遍历后面，确定前两位，然后遍历后面，确定前三位然后遍历后面......  
边界条件是：确定了前n-1位，这时候只有一种可能，装入结果vector。

#Code：
```C++
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    //功能：遍历第index位及其后面字符
    void Permutation(vector<string> &array,int index, string str){
        if(index == str.size()-1){
            array.push_back(str);
            return;
        }
        for(int i = index; i < str.size(); i++){
            if(i == index || str[i] != str[index]){//滤除重复字符
                swap(str[i],str[index]);
                Permutation(array,index+1,str);
                swap(str[i],str[index]);
            }
        }
    }
    
    vector<string> Permutation(string str) {
        vector<string> result;
        if(str.size() == 0){
            return result;
        }
        Permutation(result,0,str);
        sort(result.begin(),result.end());
        return result;
    }
};

int main()
{
	Solution s = Solution();
	vector<string> result = s.Permutation("abc");

	cout<<"all the permutation of (a,b,c) is:"<<endl;
	for(int i = 0; i < result.size(); i++){
		cout<<result[i]<<",";
	}
}
```