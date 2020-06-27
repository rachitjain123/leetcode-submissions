class Solution {
public:
    string smallestSubsequence(string text) {
        string smallestSubseq;
        vector<bool>vis(26);
        vector<int>freq(26);
        for(int i=0;i<text.length();i++) freq[text[i]-'a']++;
        for(int i=0;i<text.length();i++)
        {
            freq[text[i]-'a']--;
            if(vis[text[i]-'a']) continue;
            while(!smallestSubseq.empty() && smallestSubseq.back()>text[i] && freq[smallestSubseq.back() -'a'])
            {
                vis[smallestSubseq.back() -'a']=false;
                smallestSubseq.pop_back();
            }
            smallestSubseq.push_back(text[i]);
            vis[text[i]-'a']=true;
        }
        return smallestSubseq;
    }
};