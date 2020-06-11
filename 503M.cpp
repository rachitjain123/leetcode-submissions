class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>tmp=nums;
        stack<int>st;
        for(int i=0;i<tmp.size();i++) nums.push_back(tmp[i]);
        for(int i=0;i<nums.size();i++)
        {
            while(!st.empty() && nums[st.top()]<nums[i])
            {
                nums[st.top()]=nums[i];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            nums[st.top()]=-1;
            st.pop();
        }
        while(nums.size()!=tmp.size())
            nums.pop_back();
        return nums;
    }
};