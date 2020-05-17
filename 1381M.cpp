class CustomStack {
    vector<int> stack,inc;
    int sz;
public:
    CustomStack(int maxSize) {
        sz=maxSize;
    }
    
    void push(int x) {
        if(stack.size()==sz)
            return;
        stack.push_back(x);
        inc.push_back(0);
    }
    
    int pop() {
        if(stack.empty())
            return -1;
        int i = stack.size()-1;
        if(stack.size()>1)
            inc[i-1]+=inc[i];
        int res=stack.back()+inc[i];
        stack.pop_back();
        inc.pop_back();
        return res;
        
    }
    
    void increment(int k, int val) {
        int i = min(k,(int)stack.size()) - 1;
        if(i>=0)
            inc[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */