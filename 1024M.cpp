class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int>dp(T+1, -1);
        int pos=0,num_clips=0;
        for(int i=0;i<clips.size();i++)
        {
            int start=clips[i][0];
            int end=min(T,clips[i][1]);
            for(int i=start;i<=end;i++)
                dp[i]=max(dp[i],end);
        }
        while(pos<T)
        {
            if(dp[pos]==-1 || pos==dp[pos])
                return -1;
            pos=dp[pos];
            num_clips++;
        }
        return num_clips;
    }
};