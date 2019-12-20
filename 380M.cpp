class RandomizedSet {
public:
    map<int,int>mp;
    vector<int>arr;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val)!=mp.end())
            return false;
        int sz=arr.size();
        arr.push_back(val);
        mp[val]=sz;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val)==mp.end())
            return false;
        int ind=mp[val];
        swap(arr[ind],arr[arr.size()-1]);
        mp[arr[ind]]=ind;
        arr.pop_back();
        mp.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int random_number=rand()%arr.size();
        return arr[random_number];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */