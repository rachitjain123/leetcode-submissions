class Solution {
void cal_subsets(int index,vector<int>& nos,vector<int> &subset,vector<vector<int> > &res)
{
    for(int i=index;i<nos.size();i++)
    {
        subset.push_back(nos[i]);
        cal_subsets(i+1,nos,subset,res);
        res.push_back(subset);
        subset.pop_back();
    }
}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> >res;
        vector<int>subset;
        res.push_back(subset);
        cal_subsets(0,nums,subset,res);
        return res;
    }
};