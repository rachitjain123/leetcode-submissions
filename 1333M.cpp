class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int,int> > v;
        vector<int>arrFilter;
        for(int i=0;i<restaurants.size();i++)
        {
            if(veganFriendly)
            {
                if(restaurants[i][2] && restaurants[i][3]<=maxPrice && restaurants[i][4]<=maxDistance)
                    v.push_back({restaurants[i][1],restaurants[i][0]});        
            }
            else
            {
                if(restaurants[i][3]<=maxPrice && restaurants[i][4]<=maxDistance)
                    v.push_back({restaurants[i][1],restaurants[i][0]});            
            }
        }
        sort(v.rbegin(),v.rend());
        for(int i=0;i<v.size();i++)
            arrFilter.push_back(v[i].second);
        return arrFilter;
    }
};