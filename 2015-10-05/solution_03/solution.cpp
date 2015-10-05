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
