class Solution {
public:
    bool isValid(string s) {
        vector<char>v;
        for(int i=0;i<s.length();i++)
        {
            int sz=v.size();
            if(sz>=2)
            {
                if(s[i]=='c' && v[sz-1]=='b' && v[sz-2]=='a')
                {
                    v.pop_back();
                    v.pop_back();
                }
                else
                    v.push_back(s[i]);
            }
            else
                v.push_back(s[i]);
        }
        return v.empty();
    }
};