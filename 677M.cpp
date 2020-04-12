class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<string,int> prefSum;
    unordered_map<string,int> keyPair;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        if(keyPair.find(key)!=keyPair.end())
        {
            string prefix;
            for(int i=0;i<key.length();i++)
            {
                prefix+=key[i];
                prefSum[prefix]=prefSum[prefix]-keyPair[key]+val;
            }
            keyPair[key]=val;
        }
        else
        {
            string prefix;
            keyPair[key]=val;
            for(int i=0;i<key.length();i++)
            {
                prefix+=key[i];
                prefSum[prefix]=prefSum[prefix]+val;
            }
        }
    }
    
    int sum(string prefix) {
        if(prefSum.find(prefix)==prefSum.end())
            return 0;
        return prefSum[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */