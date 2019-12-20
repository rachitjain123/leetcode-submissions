class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long int>st;
        if(k<0||t<0)
            return false;
        for(int i=0;i<nums.size();i++)
        {
            long long int tmp1=(long long int)nums[i]-(long long int)t;
            long long int tmp2=(long long int)nums[i]+(long long int)t;
            auto it1=st.lower_bound(tmp1);
            auto it2=st.upper_bound(tmp2);
            if(it1!=it2)
                return true;
            st.insert(nums[i]);
            if(i-k>=0)
            {
                if(st.find(nums[i-k])!=st.end())
                    st.erase(st.find(nums[i-k]));
            }
        }
        return false;
    }
};