class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int i=0,j=0;
        int cst=0;
        int maxlen=0;
        while(j<s.length())
        {
            cst+=abs(s[j]-t[j]);
            if(cst>maxCost)
            {
                if(i==j)
                {
                    i++;
                    cst=0;
                }
                else
                {
                    while(i<=j && cst>maxCost)
                    {
                        cst-=abs(s[i]-t[i]);
                        i++;
                    }
                }
                
            }
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};