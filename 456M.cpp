class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size()<=2)
            return false;
        int prev=INT_MIN;
        stack<int> st;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]<prev)
                return true;
            while(!st.empty() && st.top()<nums[i])
            {
                prev=st.top();
                // prev = nums[k]
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};