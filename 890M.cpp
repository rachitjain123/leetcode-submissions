class Solution {
public:
    bool checkMatching(string s1, string s2)
    {
        if(s1.length()!=s2.length())
            return false;
        map<char,char>mapping1;
        map<char,char>mapping2;
        for(int i=0;i<s1.length();i++)
        {
            if(mapping1.find(s1[i])==mapping1.end() && mapping2.find(s2[i])==mapping2.end())
            {
                mapping1[s1[i]]=s2[i];
                mapping2[s2[i]]=s1[i];
            }
            else
            {
                if(mapping1[s1[i]]!=s2[i]||mapping2[s2[i]]!=s1[i])
                    return false;
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string>matchings;
        for(int i=0;i<words.size();i++)
        {
            if(checkMatching(words[i],pattern))
                matchings.push_back(words[i]);
        }
        return matchings;
    }
};