class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int>pref(121);
        int friend_req=0;
        for(int i=0;i<ages.size();i++)
            pref[ages[i]]++;
        for(int i=1;i<=120;i++)
            pref[i]+=pref[i-1];
        for(int i=0;i<ages.size();i++)
        {
            int r=ages[i];
            int l=ages[i]/2+8;
            if(ages[i]<100)
                r=min(r,100);
            if(l>r)
                continue;
            friend_req+=pref[r]-pref[l-1];
            if(ages[i]>=l && ages[i]<=r)
                friend_req--;
        }
        return friend_req;
    }
};