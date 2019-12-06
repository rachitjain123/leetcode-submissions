class Solution {
public:
    int countSubstrings(string s) {
        int is_pal[1001][1001];
        memset(is_pal,0,sizeof(is_pal));
        for(int i=0;i<s.length();i++)
            is_pal[i][i]=1;
        int num_strings=s.length();
        for(int len=2;len<=s.length();len++)
        {
            for(int i=0;i<s.length()-len+1;i++)
            {
                int j=i+len-1;
                if(len==2)
                {
                    if(s[i]==s[j])
                        is_pal[i][j]=1;
                }
                else if(s[i]==s[j] && is_pal[i+1][j-1])
                    is_pal[i][j]=1;
                if(is_pal[i][j])
                    num_strings++;
            }
        }
        return num_strings;
    }
};