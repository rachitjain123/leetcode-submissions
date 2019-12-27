class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        vector<string>v;
        if(s.length()<10)
            return v;
        for(int i=0;i<=s.length()-10;i++)
        {
            string str;
            for(int j=i;j<i+10;j++)
                str+=s[j];
            if(mp[str]==1)
            {
                v.push_back(str);
                mp[str]++;
            }
            mp[str]++;
        }
        return v;
    }
};