class Solution {
public:
    string reorganizeString(string s) {
        vector<int>pref(27);
        priority_queue<pair<int,char> >pq;
        string res;
        for(int i=0;i<s.length();i++)
            pref[s[i]-'a']++;
        for(int i=0;i<26;i++)
        {
            if(pref[i])
                pq.push({pref[i],'a'+i});
        }
        while(!pq.empty())
        {
            char ch1=pq.top().second;
            int freq1=pq.top().first;
            if(ch1==res[res.length()-1])
                return "";
            res+=ch1;
            pq.pop();
            if(!pq.empty())            
            {
                char ch2=pq.top().second;
                int freq2=pq.top().first;
                if(ch2==res[res.length()-1])
                    return "";
                res+=ch2;
                pq.pop();
                if(freq2>1)
                    pq.push({freq2-1,ch2});
            }
            if(freq1>1)
                pq.push({freq1-1,ch1});
        }
        return res;
    }
};