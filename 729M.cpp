class MyCalendar {
    map<int,int> events;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it=events.upper_bound(start);
        if(it!=events.end() && it->second<end)
            return false;
        events[end]=start;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */