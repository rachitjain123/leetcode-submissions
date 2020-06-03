class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        for(int i=0;i<ghosts.size();i++)
        {
            if(abs(ghosts[i][0]-target[0]) + abs(ghosts[i][1]-target[1]) <= abs(target[0])+abs(target[1]))
                return false;
        }
        return true;
    }
};