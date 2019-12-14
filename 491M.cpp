class Solution {
    void cal_subsets(vector<vector<int> > &res, vector<int> &subset, vector<int>& nos, set<vector<int> > & st, int index)
    {
        for(int i=index;i<nos.size();i++)
        {
            if(!subset.empty() && nos[i]<subset[subset.size()-1])
                continue;
            subset.push_back(nos[i]);
            cal_subsets(res,subset,nos,st,i+1);
            if(subset.size()>1 && st.find(subset)==st.end())
            {
                res.push_back(subset);
                st.insert(subset);
            }
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int> >res;
        vector<int>subset;
        set<vector<int> >st;
        cal_subsets(res,subset,nums,st,0);
        return res;
    }
};