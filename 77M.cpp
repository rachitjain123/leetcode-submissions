class Solution {
    void getCombinations(int ind,int n,int k,vector<int> &subset, vector<vector<int> > &comb)
    {
        if(subset.size()>k)
            return;
        for(int i=ind;i<=n;i++)
        {
            subset.push_back(i);
            if(subset.size()==k)
                comb.push_back(subset);
            getCombinations(i+1,n,k,subset,comb);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>subset;
        vector<vector<int> > comb;
        getCombinations(1,n,k,subset,comb);
        return comb;
    }
};