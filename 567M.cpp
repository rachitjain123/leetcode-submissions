class Solution {
    bool checkPermutation(vector<int> &pref1, vector<int> &pref2)
    {
        for(int i=0;i<26;i++)
        {
            if(pref1[i]!=pref2[i])
                return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>pref1(26);
        vector<int>pref2(26);
        if(s1.length()>s2.length())
            return false;
        for(int i=0;i<s1.length();i++)
        {
            pref1[s1[i]-'a']++;
            pref2[s2[i]-'a']++;
        }
        if(checkPermutation(pref1,pref2))
            return true;
        for(int i=s1.length();i<s2.length();i++)
        {
            pref2[s2[i]-'a']++;
            pref2[s2[i-s1.length()]-'a']--;
            if(checkPermutation(pref1,pref2))
                return true;
        }
        return false;
    }
};