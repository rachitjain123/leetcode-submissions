class Solution {
public:
    bool isSubsequence(string s1, string s2)
    {
        //checks if s1 is a subsequence of s2
        if(s1.length() > s2.length())
            return false;
        int id=0;
        for(int i=0;i<s2.length();i++)
        {
            if(id>=s1.length())
                break;
            if(s2[i]==s1[id])
                id++;
        }
        if(id==s1.length())
            return true;
        return false;
    }
    string findLongestWord(string s, vector<string>& d) 
    {
        string ans;
        for(int i=0;i<d.size();i++)
        {
            bool check_subseq=isSubsequence(d[i],s);
            if(check_subseq==true)
            {
                if(d[i].length()>ans.length())
                    ans=d[i];
                if(d[i].length()==ans.length() && d[i]<ans)
                    ans=d[i];
            }
        }
        return ans;
    }
};