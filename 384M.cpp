class Solution {
    vector<int> init;
    vector<int>shuffled_arr;
public:
    Solution(vector<int>& nums) {
        init=nums;
        shuffled_arr=init;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return shuffled_arr=init;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        random_shuffle(shuffled_arr.begin(), shuffled_arr.end()); 
        return shuffled_arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */