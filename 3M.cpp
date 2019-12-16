class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        map<char,int>mp;
        int start=0,maxlen=0;
        for(int i=1;i<=s.length();i++)
        {
            if(mp[s[i-1]]>start)
                start=mp[s[i-1]];
            mp[s[i-1]]=i;
            maxlen=max(maxlen,i-start);
        }
        return maxlen;    
    }
};

