class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int>freq(26);
        vector<string>universal_words;
        for(int i=0;i<B.size();i++)
        {
            vector<int>tmp(26);
            for(int j=0;j<B[i].size();j++)
                tmp[B[i][j]-'a']++;
            for(int j=0;j<26;j++)
                freq[j]=max(freq[j],tmp[j]);
        }
        for(int i=0;i<A.size();i++)
        {
            vector<int>freq_word(26);
            bool is_univ=true;
            for(int j=0;j<A[i].size();j++)
                freq_word[A[i][j]-'a']++;
            for(int j=0;j<26;j++)
            {
                if(freq[j]>freq_word[j])
                {
                    is_univ=false;
                    break;
                }
            }
            if(is_univ)
                universal_words.push_back(A[i]);
        }
        return universal_words;
    }
};