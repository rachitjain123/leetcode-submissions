class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) 
    {
        map<int,int>mp;
        map<int,int>vis;
        for(int i=0;i<hand.size();i++)
            mp[hand[i]]++;
        for(auto x:mp)
        {
            if(x.second==0)
                continue;
            for(int i=x.first+1;i<x.first+W;i++)
            {
                if(mp[i]<x.second)
                    return false;
                mp[i]=mp[i]-x.second;
            }
        }
        return true;
    }
};