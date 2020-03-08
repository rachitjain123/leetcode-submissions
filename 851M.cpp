class Solution {
    vector<int>adj[1000];
    int getLeastQuiet(int src,vector<int> &quiet,vector<int> &answer)
    {
        if(answer[src]!=-1)
            return answer[src];
        int min_quiet_val=quiet[src];
        int min_quiet_person=src;
        for(int i=0;i<adj[src].size();i++)
        {
            int quiet_person=getLeastQuiet(adj[src][i],quiet,answer);
            int quiet_val=quiet[quiet_person];
            if(quiet_val<min_quiet_val)
            {
                min_quiet_val=quiet_val;
                min_quiet_person=quiet_person;
            }
        }
        return answer[src] = min_quiet_person;
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<int> answer(quiet.size(),-1);
        for(int i=0;i<richer.size();i++)
            adj[richer[i][1]].push_back(richer[i][0]);
        for(int i=0;i<quiet.size();i++)
        {
            if(answer[i]==-1)
                getLeastQuiet(i,quiet,answer);
        }
        return answer;
    }
};