class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        vector<int>pref(A.size());
        int mini=INT_MAX;
        for(int i=A.size()-1;i>=0;i--)
        {
            mini=min(mini,A[i]);
            pref[i]=mini;
        }
        int maxi=0;
        int ans;
        for(int i=0;i<A.size()-1;i++)
        {
            maxi=max(maxi,A[i]);
            if(maxi<=pref[i+1])
            {
                ans=i+1;
                break;
            }
        }
        return ans;
    }
};