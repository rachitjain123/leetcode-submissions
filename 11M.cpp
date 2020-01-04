class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,water=INT_MIN;
        while(i<j)
        {
            int mini=min(height[i],height[j]);
            water=max(water,mini*(j-i));
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return water;
    }
};