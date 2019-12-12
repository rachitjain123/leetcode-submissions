class NumArray {
    vector<int>BIT;
    int len_array;
    int queryBIT(int x)
    {
        int sum=0;
        for(;x>0;x-=x&-x)
           sum+=BIT[x];
       return sum;
    }
    void updateBIT(int x, int val) 
    {
        for(;x<=len_array;x+=x&-x)
            BIT[x]+=val;
    }
public:
    NumArray(vector<int>& nums) {
        len_array=nums.size();
        for(int i=0;i<=len_array+3;i++)
            BIT.push_back(0);
        for(int i=1;i<=len_array;i++)
            updateBIT(i,nums[i-1]);
    }
    
    void update(int x, int val) 
    {
        int pre_val=sumRange(x,x);
        updateBIT(x+1,val-pre_val);
    }
    
    int sumRange(int i, int j) {
        return queryBIT(j+1)-queryBIT(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */