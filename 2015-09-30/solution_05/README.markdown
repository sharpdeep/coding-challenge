#顺时针打印矩阵

##问题：
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下矩阵： 
```
1  2  3  4 
5  6  7  8 
9 10 11 12 
13 14 15 16
```
则依次打印出数字
```
1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
```

##思路：
分成四部分：从左到右，从上到下，从右到左，从下到上分别打印。
注意边界条件：当只剩下一行或者一列时。
如剩下一行时，应判断为不用从右到左打印(重复打印)。
同理，当剩下一列时，应该判断为不用从下到上打印。

##Code：
```C++
#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> result;
        
        int maxRow = matrix.size()-1;
        int maxCol = matrix[0].size()-1;
        int minRow = 0,minCol = 0;
        if(maxRow == -1 || maxCol == -1){
            return result;
        }
        
        while(maxRow >= minRow && maxCol >= minCol){
            for(int i = minCol; i <= maxCol; i++){
                result.push_back(matrix[minRow][i]);
            }
            for(int i = minRow+1; i <= maxRow; i++){
            	result.push_back(matrix[i][maxCol]);
            }
            if(minRow != maxRow){
                for(int i = maxCol-1; i >= minCol; i--){
                    result.push_back(matrix[maxRow][i]);
                }   
            }
            if(minCol != maxCol){
                for(int i = maxRow-1; i>= minRow+1; i--){
                    result.push_back(matrix[i][minCol]);
                }
            }
          	maxRow--;maxCol--;minRow++;minCol++;  
        }
        
        return result;
    }
};

int main()
{
	vector<vector<int> > matrix;
	vector<int> temp;
	vector<int> result;

	for(int i = 0; i < 16; i++){
		temp.push_back(i);
		if((i+1)%4 == 0){
			matrix.push_back(temp);
			temp.clear();
		}
	}

	Solution s = Solution();
	result = s.printMatrix(matrix);

	cout<<"before:"<<endl;
	for(int i = 0; i < matrix.size(); i++){
		for(int j = 0; j < matrix[0].size(); j++){
			cout<<matrix[i][j]<<",";
		}
		cout<<endl;
	}
	
	cout<<"after:"<<endl;
	for(int i = 0; i < result.size(); i++){
		cout<<result[i]<<",";
	}
}
```