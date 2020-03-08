class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int> >pos_cnt(26,vector<int>(26,0));
        vector<pair<vector<int>,char> >ordered_teams;
        string rank_out;
        for(int i=0;i<votes.size();i++)
        {
            for(int j=0;j<votes[i].size();j++)
                pos_cnt[votes[i][j]-'A'][j]++;
        }
        for(char ch='A';ch<='Z';ch++)
        {
            vector<int>tmp;
            int count=0;
            for(int i=0;i<26;i++)
            {
                tmp.push_back(-pos_cnt[ch-'A'][i]);
                count+=pos_cnt[ch-'A'][i];
            }
            if(count)
                ordered_teams.push_back({tmp,ch});           
        }
        sort(ordered_teams.begin(),ordered_teams.end());
        for(int i=0;i<ordered_teams.size();i++)
            rank_out+=ordered_teams[i].second;
        return rank_out;
    }
};