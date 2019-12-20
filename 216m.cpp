class Solution {
    void findCombinations(int target, vector<vector<int> > &res, vector<int> &comb, int i,int k)
    {
        if(target<0)
            return;
        if(target==0 && k==0)
        {
            res.push_back(comb);
            return;
        }
        if(target!=0 && k==0)
            return;
        while(i<=9 && target-i>=0)
        {
            comb.push_back(i);
            findCombinations(target-i,res,comb,i+1,k-1);
            i++;
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> >res;
        vector<int>comb;
        findCombinations(n,res,comb,1,k);
        return res;
    }
};