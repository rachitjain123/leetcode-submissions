class Solution {
public:
    int longestOnes(vector<int>& A, int K) 
    {
        int i=0,j=0,cnt=0,ans=0;
        while(j<A.size())
        {
            if(A[j]==0)
            {
                cnt++;
                while(cnt>K && i<=j)
                {
                    if(A[i]==0)
                        cnt--;
                    i++;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};