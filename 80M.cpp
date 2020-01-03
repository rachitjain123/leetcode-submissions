class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ind=0;
        for(int i=0;i<nums.size();i++)
        {
            int j=i;
            while(j<nums.size() && nums[i]==nums[j])
                j++;
            nums[ind++]=nums[i];
            if(j-i>=2)
                nums[ind++]=nums[i];
            i=j-1;
        }
        return ind;
    }
};