class Solution {
    vector<bool> getAllAccessibleRooms(vector<vector<int>>& rooms)
    {
        queue<int>q;
        vector<bool>accessible_rooms(rooms.size());
        q.push(0);
        accessible_rooms[0]=true;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int tp=q.front();
                accessible_rooms[tp]=true;
                q.pop();
                for(int i=0;i<rooms[tp].size();i++)
                {
                    if(!accessible_rooms[rooms[tp][i]])
                    {
                        q.push(rooms[tp][i]);
                        accessible_rooms[rooms[tp][i]]=true;
                    }
                }
            }
        }
        return accessible_rooms;
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>accessible_rooms=getAllAccessibleRooms(rooms);
        for(int i=0;i<accessible_rooms.size();i++)
        {
            if(!accessible_rooms[i])
                return false;
        }
        return true;
    }
};