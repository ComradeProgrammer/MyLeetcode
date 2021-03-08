#include"stdfax.h"
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int line=int(matrix.size());
        if(line==0){
            return false;
        }
        int column=int(matrix[0].size());
        if(column==0){
            return false;
        }
        int i=0,j=column-1;
        while(i< line && j>=0){
            if(target==matrix[i][j]){
                return true;
            }
            else if(target<matrix[i][j]){
                j--;
            }
            else if(target>matrix[i][j]){
                i++;
            }
        }
        return false;

    }
};