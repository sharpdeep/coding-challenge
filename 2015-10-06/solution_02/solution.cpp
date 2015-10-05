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
