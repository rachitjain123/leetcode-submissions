class TopVotedCandidate {
    vector<pair<int,int> > leaders_with_time;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int,int> votesPerPerson;
        int max_votes=-INT_MAX;
        int leader=-1;
        for(int i=0;i<persons.size();i++)
        {
            votesPerPerson[persons[i]]++;
            if(votesPerPerson[persons[i]]>=max_votes)
            {
                max_votes=votesPerPerson[persons[i]];
                leader=persons[i];
            }
            leaders_with_time.push_back({times[i],leader});
        }
    }
    
    int q(int t) {
        int low=0,high=leaders_with_time.size()-1;
        int leader;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(leaders_with_time[mid].first<=t)
            {
                leader=leaders_with_time[mid].second;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return leader;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */