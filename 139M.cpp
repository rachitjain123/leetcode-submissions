class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length(),false);
        unordered_set<string> wordMap;
        for(int i=0;i<wordDict.size();i++)
            wordMap.insert(wordDict[i]);
        for(int i=0;i<s.length();i++)
        {
            if(!dp[i] && wordMap.find(s.substr(0,i+1))!=wordMap.end())
                dp[i]=true;
            string word;
            if(dp[i]==true)
            {
                for(int j=i+1;j<s.length();j++)
                {
                    word+=s[j];
                    if(dp[j]==false && wordMap.find(word)!=wordMap.end())
                        dp[j]=true;
                }
            }
        }
        return dp[s.length()-1];
    }
};