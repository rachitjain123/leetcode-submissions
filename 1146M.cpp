class SnapshotArray {
    vector<pair<int,int> >v[50000];
    int snap_id;
public:
    SnapshotArray(int length) 
    {
    }
    
    void set(int index, int val) {
        v[index].push_back({snap_id,val});
    }
    
    int snap() {
        snap_id++;
        return snap_id-1;
    }
    
    int get(int index, int snap_id) {
        if(v[index].empty()||v[index][0].first>snap_id)
            return NULL;
        int low=0,high=v[index].size()-1,ans=high+1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(v[index][mid].first>snap_id)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        ans--;
        return v[index][ans].second;
        
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */