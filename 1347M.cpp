class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26);
        int num_min=0;
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }
        for(int i=0;i<26;i++)
            num_min+=abs(freq[i]);
        return num_min/2;
    }
};