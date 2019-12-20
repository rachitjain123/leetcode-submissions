class Solution {
    void findCombinations(vector<int> &candidates,int target, vector<vector<int> > &res, vector<int> &comb, int i)
    {
        if(target<0)
            return;
        if(target==0)
        {
            res.push_back(comb);
            return;
        }
        while(i<candidates.size() && target-candidates[i]>=0)
        {
            comb.push_back(candidates[i]);
            findCombinations(candidates,target-candidates[i],res,comb,i);
            i++;
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int> >res;
        vector<int>comb;
        findCombinations(candidates,target,res,comb,0);
        return res;
    }
};