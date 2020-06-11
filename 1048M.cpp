class Solution {
    static bool cmp(const string &s1, const string &s2)
    {
        return s1.length()<s2.length();
    }
    
    // very important here address is passed to string not str1, str2
    bool isPredecessor(string &str1, string &str2)
    {
        int i=0,j=0;
        if(str1.length()!=str2.length()-1)
            return false;
        while(i<str1.length() && j<str2.length())
        {
            if(str1[i]==str2[j])
                i++;
            j++;
            if(j-i>=2)
                return false;
        }
        if(i==str1.length()) return true;
        return false;
    }
public:
    int longestStrChain(vector<string>& words) {
        vector<int> dp(words.size(),1);
        sort(words.begin(),words.end(),cmp);
        int longest_len=0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(isPredecessor(words[j],words[i]))
                    dp[i]=max(dp[i],dp[j]+1);
            }
            longest_len=max(longest_len,dp[i]);
        }
        return longest_len;
    }
};