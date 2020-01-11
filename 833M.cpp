class Solution {
public:
    string findReplaceString(string s, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<pair<int,pair<string,string> > >v;
        for(int i=0;i<indexes.size();i++)
            v.push_back({indexes[i],{sources[i],targets[i]}});
        sort(v.begin(),v.end());
        int cnt=0;
        for(int i=0;i<v.size();i++)
        {
            int ind=v[i].first+cnt;
            string src=v[i].second.first;
            string target=v[i].second.second;
            if(src.empty()||target.empty())
                continue;
            bool check_replacement=true;
            int pntr=0;
            for(int j=ind;j<s.length();j++)
            {
                if(pntr==src.length())
                    break;
                if(s[j]==src[pntr])
                    pntr++;
                else
                {
                    check_replacement=false;
                    break;
                }
            }
            if(pntr!=src.length())
                check_replacement=false;
            if(check_replacement)
            {
                string tmp;
                for(int j=0;j<ind;j++)
                    tmp+=s[j];
                tmp+=target;
                for(int j=ind+src.length();j<s.length();j++)
                    tmp+=s[j];
                s=tmp;
                cnt+=target.length()-src.length();
            }
        }
        return s;
    }
};