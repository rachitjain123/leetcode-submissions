class Solution {
    void findCombinations(vector<int> &candidates,int target, vector<vector<int> > &res, vector<int> &comb, set<vector<int> > &st,int ind)
    {
        if(target==0)
        {
            if(st.find(comb)==st.end())
            {
                res.push_back(comb);
                st.insert(comb);
            }
            return;
        }
        if(target<0)
            return;
        for(int i=ind;i<candidates.size();i++)
        {
            comb.push_back(candidates[i]);
            findCombinations(candidates,target-candidates[i],res,comb,st,i+1);
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int> >res;
        vector<int>comb;
        set<vector<int> > st;
        findCombinations(candidates,target,res,comb,st,0);
        return res;
    }
};