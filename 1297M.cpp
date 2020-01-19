class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string,int>all_strings;
        int max_occurences=0;
        for(int i=0;i<s.length();i++)
        {
            string tmp;
            unordered_set<char>dist_chars;
            for(int j=i;j<s.length();j++)
            {
                if(tmp.length()==minSize)
                    break;
                tmp+=s[j];
                dist_chars.insert(s[j]);
            }
            if(tmp.length()==minSize && dist_chars.size()<=maxLetters)
            {
                all_strings[tmp]++;
                max_occurences=max(max_occurences,all_strings[tmp]);
            }
        }
        return max_occurences;
    }
};