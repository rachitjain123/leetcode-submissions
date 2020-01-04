class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0,high=matrix.size()-1,row=0;
        if(matrix.empty()||matrix[0].empty()||matrix[0][0]>target)
            return false;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(matrix[mid][0]<=target)
            {
                row=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        low=0,high=matrix[row].size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(matrix[row][mid]==target)
                return true;
            if(matrix[row][mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return false;
    }
};