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
