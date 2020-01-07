class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string> >mp;
        for(int i=0;i<strs.size();i++)
        {
            string tmp=strs[i];
            sort(tmp.begin(),tmp.end());
            mp[tmp].push_back(strs[i]);
        }
        vector<vector<string> >anagrams;
        for(auto x:mp)
        {
            vector<string>v;
            for(int i=0;i<x.second.size();i++)
                v.push_back(x.second[i]);
            anagrams.push_back(v);
        }
        return anagrams;
    }
};