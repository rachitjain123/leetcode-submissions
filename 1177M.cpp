class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int len=s.length();
        vector<vector<int> >pref(26,vector<int>(len,0));
        vector<bool>answer;
        for(char ch='a';ch<='z';ch++)
        {
            int freq=0;
            for(int i=0;i<s.length();i++)
            {
                if(s[i]==ch)
                    freq++;
                pref[ch-'a'][i]=freq;
            }
        }
        for(int i=0;i<queries.size();i++)
        {
            int l=queries[i][0];
            int r=queries[i][1];
            int k=queries[i][2];
            int num=0;
            for(char ch='a';ch<='z';ch++)
            {
                int sum;
                if(l==0)
                    sum=pref[ch-'a'][r];
                else
                    sum=pref[ch-'a'][r]-pref[ch-'a'][l-1];
                if(sum%2==1)
                    num++;
            }

            if(k>=num/2)
                answer.push_back(true);
            else
                answer.push_back(false);
        }
        return answer;
    }
};