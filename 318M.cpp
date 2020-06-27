class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n = words.size();
        if (n == 0) return 0;
        
        int nums[n];
        for (int i = 0; i < n; i++)
            nums[i] = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].length(); j++) {
                nums[i] |= 1 << (words[i][j]-'a');        
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (!(nums[i] & nums[j]))
                    ans = max(ans, (int)words[i].length() * (int)words[j].length());
            }
        }
        
        return ans;
    }
};