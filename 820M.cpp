class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        // sort(words.begin(),words.end(),cmp);
        // unordered_map<string,int> freqMap;
        // int len=0;
        // for(int i=0;i<words.size();i++)
        //     freqMap[words[i]]=freqMap[words[i]]+1;
        // for(int i=0;i<words.size();i++)
        // {
        //     string word;
        //     if(freqMap.find(words[i])==freqMap.end())
        //         continue;
        //     for(int j=words[i].length()-1;j>=0;j--)
        //     {
        //         word+=words[i][j];
        //         string rev_word=word;
        //         reverse(rev_word.begin(),rev_word.end());
        //         if(j==0 && freqMap[rev_word] >= 2)
        //             freqMap.erase(rev_word);
        //         else if(j!=0 && freqMap.find(rev_word) != freqMap.end())
        //             freqMap.erase(rev_word);
        //     }
        //     len+=words[i].length()+1;
        // }
        // return len;
        
        // Efficient solution
        int len=0;
        for(int i=0;i<words.size();i++) reverse(words[i].begin(),words[i].end());
        sort(words.begin(),words.end());
        for(int i=1;i<words.size();i++)
        {
            if(words[i-1].length() > words[i].length() || (words[i].substr(0,words[i-1].length()) != words[i-1]))
                len+=words[i-1].length()+1;
        }
        len+=words[words.size()-1].length()+1;
        return len;
    }
};