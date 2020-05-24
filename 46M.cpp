class Solution {
    void getPermutations(int index, vector<int> &nums, vector<vector<int> > &permutations)
    {
        if(index == nums.size())
            permutations.push_back(nums);
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[i],nums[index]);
            getPermutations(index+1, nums,permutations);
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > permutations;
        getPermutations(0,nums, permutations);
        return permutations;
    }
};