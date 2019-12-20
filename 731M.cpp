// don't know what's the error

class MyCalendarTwo {
    vector<pair<int,int> >v;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        if(v.size()<=2)
        {
            v.push_back({start,end-1});
            return true;
        }
        v.push_back({start,end-1});
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            multiset<int>st;
            for(int j=i+1;j<v.size();j++)
            {
                if(v[i].second<v[j].first)
                    continue;
                int l=v[j].first;
                int r=min(v[i].second,v[j].second);
                if(st.empty())
                {
                    st.insert(v[j].second);
                    continue;
                }
                else
                {
                    if(*st.rbegin()>=r)
                    {
                        for(auto it=v.begin();it!=v.end();it++)
                        {
                            if(it->first==start && it->second==end-1)
                            {
                                v.erase(it);
                                return false;
                            }
                        }
                    }
                }
                st.insert(v[j].second);
            }
        }
        return true;
            
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */