class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double> >cars;
        for(int i=0;i<position.size();i++)
            cars.push_back({position[i],(double)((target-position[i])/(double)speed[i])});
        sort(cars.begin(),cars.end());
        int ind=cars.size()-1,num_fleets=1;
        while(ind>0)
        {
            if(cars[ind].second<cars[ind-1].second)
                num_fleets++;
            else
                cars[ind-1]=cars[ind];
            ind--;
        }
        return num_fleets-position.empty();
    }
};