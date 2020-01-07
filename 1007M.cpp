class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int ans=INT_MAX;
        for(int i=1;i<=6;i++)
        {
            bool is_possible=true;
            int min1=0,min2=0;
            for(int j=0;j<A.size();j++)
            {
                if(A[j]!=i && B[j]!=i)
                {
                    is_possible=false;
                    break;
                }
                if(A[j]!=i && B[j]==i)
                    min1++;
                if(A[j]==i && B[j]!=i)
                    min2++;
            }
            if(is_possible)
                ans=min(ans,min(min1,min2));
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};