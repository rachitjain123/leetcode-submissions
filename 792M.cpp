class Solution {
    int find(unordered_map<char,vector<int> > &mp, char ch, int pos)
    {
        int low=0,high=mp[ch].size(),ans;
        if(mp.find(ch)==mp.end()||mp[ch].empty()||mp[ch][high-1]<=pos)
            return -1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(mp[ch][mid]>pos)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return mp[ch][ans];
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int> > mp;
        int subseq_words=0;
        for(int i=0;i<s.length();i++)
            mp[s[i]].push_back(i);
        for(int i=0;i<words.size();i++)
        {
            string str=words[i];
            int init_pos=-1;
            bool is_subsequence=true;
            for(int j=0;j<str.length();j++)
            {
                init_pos=find(mp,str[j],init_pos);
                if(init_pos==-1)
                {
                    is_subsequence=false;
                    break;
                }
            }
            if(is_subsequence)
                subseq_words++;
        }
        return subseq_words;
    }
};