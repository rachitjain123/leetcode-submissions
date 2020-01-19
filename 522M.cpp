class Solution {
    bool isSubsequence(string s1, string s2)
    {
        if(s1.length()>s2.length())
            return false;
        int ind=0;
        for(int i=0;i<s2.length();i++)
        {
            if(ind==s1.length())
                break;
            if(s2[i]==s1[ind])
                ind++;
        }
        return ind==s1.length();
    }
public:
    int findLUSlength(vector<string>& strs) {
        int max_len=-1;
        for(int i=0;i<strs.size();i++)
        {
            bool is_possible=true;
            for(int j=0;j<strs.size();j++)
            {
                if(j==i)
                    continue;
                if(isSubsequence(strs[i],strs[j]))
                {
                    is_possible=false;
                    break;
                }
            }
            if(is_possible)
                max_len=max(max_len,(int)strs[i].length());
        }
        return max_len;
    }
};