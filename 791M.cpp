class Solution {
public:
    string customSortString(string s, string t) {
        int freq[26];
        for(int i=0;i<26;i++)
            freq[i]=0;
        for(int i=0;i<t.length();i++)
            freq[t[i]-'a']++;
        string custom_string;
        for(int i=0;i<s.length();i++)
        {
            while(freq[s[i]-'a'])
            {
                custom_string+=s[i];
                freq[s[i]-'a']--;
            }
        }
        for(int i=0;i<26;i++)
        {
            while(freq[i])
            {
                custom_string+=(char)('a'+i);
                freq[i]--;
            }
        }
        return custom_string;
    }
};