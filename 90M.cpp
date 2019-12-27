class Solution {
void cal_subsets(int index,vector<int>& nos,vector<int> &subset,vector<vector<int> > &res,unordered_set<string> &mp,string str)
{
    for(int i=index;i<nos.size();i++)
    {
        subset.push_back(nos[i]);
        str+=nos[i];
        cal_subsets(i+1,nos,subset,res,mp,str);
        if(mp.find(str)==mp.end())
        {
            res.push_back(subset);
            mp.insert(str);
        }
        subset.pop_back();
        str.pop_back();
    }
}
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> >res;
        vector<int>subset;
        string str;
        unordered_set<string >mp;
        res.push_back(subset);
        cal_subsets(0,nums,subset,res,mp,str);
        return res;
    }
};