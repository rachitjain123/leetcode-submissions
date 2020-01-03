class RLEIterator {
    map<int,pair<int,int> >mp;
public:
    RLEIterator(vector<int>& A) {
        for(int i=0;i<A.size();i+=2)
            mp[i]={A[i],A[i+1]};
    }
    
    int next(int n) {
        vector<int>tmp;
        int ret_val=-1;
        for(auto x:mp)
        {
            pair<int,int>p1=x.second;
            if(p1.first<n)
            {
                tmp.push_back(x.first);
                n-=p1.first;
            }
            else if(p1.first==n)
            {
                tmp.push_back(x.first);
                ret_val=p1.second;
                break;
            }
            else
            {
                mp[x.first]={p1.first-n,x.second.second};
                ret_val=p1.second;
                break;
            }
        }
        for(int i=0;i<tmp.size();i++)
            mp.erase(tmp[i]);
        return ret_val;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */