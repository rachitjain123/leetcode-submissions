class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int mini=A[A.size()-1];
        for(int i=A.size()-3;i>=0;i--)
        {
            if(A[i]>mini)
                return false;
            mini=min(mini,A[i+1]);
        }
        return true;
    }
};