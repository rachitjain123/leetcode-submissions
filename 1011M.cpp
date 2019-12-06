class Solution {
public:
    bool checkCapacity(vector<int>& weights,int D,int capacity)
    {
        int days=0,sum_weight=0;
        for(int i=0;i<weights.size();i++)
        {
            sum_weight+=weights[i];
            if(days>D)
                return false;
            if(sum_weight>capacity)
            {
                days++;
                sum_weight=0;
                i--;
            }
        }
        if(sum_weight)
            days++;
        if(days>D)
            return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int D) 
    {
        int low=0,high=0;
        for(int i=0;i<weights.size();i++)
            high+=weights[i];
        int min_capacity=high;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(checkCapacity(weights,D,mid))
            {
                min_capacity=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return min_capacity;
    }
};