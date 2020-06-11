class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int max_elem=-1,ans=0;
        for(int i=0;i<arr.size();i++)
        {
            max_elem=max(arr[i],max_elem);
            if(max_elem==i) ans++;
        }
        return ans;
    }
};