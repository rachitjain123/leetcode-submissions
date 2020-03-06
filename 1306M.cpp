class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;
        vector<bool>vis(arr.size());
        q.push(start);
        vis[start]=true;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int tp=q.front();
                if(arr[tp]==0)
                    return true;
                q.pop();
                if(tp+arr[tp]<arr.size() && !vis[tp+arr[tp]])
                {
                    q.push(tp+arr[tp]);
                    vis[tp+arr[tp]]=true;
                }
                if(tp-arr[tp]>=0 && !vis[tp-arr[tp]])
                {
                    q.push(tp-arr[tp]);
                    vis[tp-arr[tp]]=true;
                }
            }
        }
        return false;
    }
};