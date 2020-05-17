class Solution {
public:
    int numTeams(vector<int>& rating) {
        int count = 0;
        vector<int> lessthan(rating.size(), 0);
        vector<int> morethan(rating.size(), 0);
        for(int i=0; i<rating.size(); i++) {
            for(int j=i+1; j<rating.size(); j++) {
                if(rating[i] < rating[j])
                    lessthan[j] += 1;
                if(rating[i] > rating[j])
                    morethan[j] += 1;
            }
        }
        for(int i=1; i<rating.size(); i++) {
            for(int j=i+1; j<rating.size(); j++) {
                if(rating[i] < rating[j] && lessthan[i] > 0)
                    count += lessthan[i];
                if(rating[i] > rating[j] && morethan[i] > 0)
                    count += morethan[i];
            }
        }
        return count;
    }
};