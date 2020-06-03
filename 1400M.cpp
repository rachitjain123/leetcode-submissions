class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.length())
            return false;
        vector<int>freq(26);
        for(int i=0;i<s.length();i++)
            freq[s[i]-'a']++;
        int num_ch=s.length()-k+1;
        for(int i=0;i<26;i++)
        {
            while(num_ch>=2 && freq[i]>=2)
            {
                num_ch-=2;
                freq[i]-=2;
            }
        }
        if(num_ch<=1)
            return true;
        return false;
    }
};