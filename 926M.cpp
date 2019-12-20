class Solution {
public:
    int minFlipsMonoIncr(string s) 
    {
        vector<int>pref(s.length());
        int sum=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='0')
                sum++;
            pref[i]=sum;
        }
        int num_ones=0;
        int min_flips=pref[0];
        for(int i=0;i<s.length();i++)
        {
            int flips=num_ones;
            if(s[i]=='1')
            {
                num_ones++;
                flips++;
            }
            if(i+1<s.length())
                flips+=pref[i+1];
            min_flips=min(min_flips,flips);
        }
        return min_flips;
    }
};