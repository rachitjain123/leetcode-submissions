class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int row=0,col=matrix[0].size()-1;
        while(row<matrix.size() && col<matrix[0].size() && col>=0 && row>=0)
        {
            if(matrix[row][col]==target)
                return true;
            if(matrix[row][col]<target)
                row++;
            else
                col--;
        }
        return false;
    }
};