class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        for(char ch='A';ch<='Z';ch++)
        {
            int i=0,j=0,cnt=0;
            while(j<s.length())
            {
                if(s[j]!=ch)
                {
                    cnt++;
                    while(cnt>k && i<=j)
                    {
                        if(s[i]!=ch)
                            cnt--;
                        i++;
                    }
                }
                ans=max(ans,j-i+1);
                j++;
            }
        }
        return ans;
    }
};