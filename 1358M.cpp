class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0,num_str=0;
        vector<int>freq(3);
        while(r<s.length() && l<=r)
        {
            freq[s[r]-'a']++;
            while(freq[0]>=1 && freq[1]>=1 && freq[2]>=1)
            {
                num_str+=s.length()-r;
                freq[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return num_str;
    }
};