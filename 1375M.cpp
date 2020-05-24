class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int lastBulbOn=0,blue_moments=0;
        for(int i=0;i<light.size();i++)
        {
            lastBulbOn = max(lastBulbOn, light[i]);
            if(lastBulbOn == i+1)
                blue_moments++;
        }
        return blue_moments;
    }
};