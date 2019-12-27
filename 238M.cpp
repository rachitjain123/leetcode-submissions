class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l=1;
        vector<int>pref(nums.size()+1,1);
        pref[nums.size()]=1;
        for(int i=nums.size()-1;i>=0;i--)
            pref[i]=pref[i+1]*nums[i];
        for(int i=0;i<nums.size();i++)
        {
            int tmp=nums[i];
            pref[i]=l*pref[i+1];
            l=l*tmp;
        }
        pref.pop_back();
        return pref;
    }
};