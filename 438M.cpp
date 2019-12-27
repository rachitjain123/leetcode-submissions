class Solution {
    bool check(vector<int> &freq)
    {
        for(int i=0;i<26;i++)
        {
            if(freq[i])
                return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>v;
        if(p.length()>s.length())
            return v;
        vector<int>freq(26);
        for(int i=0;i<p.length();i++)
            freq[p[i]-'a']++;
        for(int i=0;i<p.length();i++)
            freq[s[i]-'a']--;
        if(check(freq))
            v.push_back(0);
        for(int i=p.length();i<s.length();i++)
        {
            freq[s[i]-'a']--;
            freq[s[i-p.length()]-'a']++;
            if(check(freq))
                v.push_back(i-p.length()+1);
        }
        return v;
    }
};