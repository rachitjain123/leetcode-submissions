class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>v;
        for(int i=0;i<nums.size();i++)
        {
            int tmp=nums[i],j=i+1;
            string str;
            while(j<nums.size())
            {
                if(nums[j]==tmp+1)
                {
                    tmp=nums[j];
                    j++;
                }
                else
                    break;
            }
            if(nums[i]==tmp)
                str=to_string(nums[i]);
            else
                str=to_string(nums[i])+"->"+to_string(tmp);
            i=j-1;
            v.push_back(str);
        }
        return v;
    }
};