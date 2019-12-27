class TimeMap {
    map<string,vector<pair<int,string> > >mp;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timeStamp) {
        vector<pair<int,string> >v=mp[key];
        if(v.empty()||v[0].first>timeStamp)
            return "";
        int low=0,high=v.size()-1,ans=high+1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(v[mid].first>timeStamp)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        ans--;
        return v[ans].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */