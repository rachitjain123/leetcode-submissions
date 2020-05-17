class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        vector<int>sameNum(2001);
        int min_num=INT_MAX;
        for(int i=0;i<fronts.size();i++)
        {
            if(fronts[i]==backs[i])
                sameNum[fronts[i]]++;
        }
        for(int i=0;i<fronts.size();i++)
        {
            int n1=fronts[i];
            int n2=backs[i];
            if(n1==n2)
                continue;
            if(sameNum[n1]==0)
                min_num=min(min_num,n1);
            if(sameNum[n2]==0)
                min_num=min(min_num,n2);
        }
        if(min_num==INT_MAX)
            return 0;
        return min_num;
    }
};