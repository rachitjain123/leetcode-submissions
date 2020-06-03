class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<string,int> sequenceInd;
        string bitSeq="00000";
        unordered_map<char,int > vowelMap;
        int maxLen=0;
        sequenceInd[bitSeq]=-1;
        vowelMap['a']=0;
        vowelMap['e']=1;
        vowelMap['i']=2;
        vowelMap['o']=3;
        vowelMap['u']=4;
        for(int i=0;i<s.length();i++)
        {
            if(vowelMap.find(s[i])!=vowelMap.end())
            {
                bitSeq[vowelMap[s[i]]] == '0' ? bitSeq[vowelMap[s[i]]] = '1' : bitSeq[vowelMap[s[i]]] = '0';
                if(sequenceInd.find(bitSeq)==sequenceInd.end())
                    sequenceInd[bitSeq]=i;
            }
            maxLen=max(maxLen,i-sequenceInd[bitSeq]);
        }
        return maxLen;
    }
};