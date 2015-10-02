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
