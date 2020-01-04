class Solution {
    int sumArr(vector<int> &arr, int val)
    {
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>val)
                sum+=val;
            else
                sum+=arr[i];
        }
        return sum;
    }
public:
    int findBestValue(vector<int>& arr, int target) {
        int low=0,high=*max_element(arr.begin(),arr.end());
        int abs_diff=INT_MAX,res=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int sum=sumArr(arr,mid);
            if(sum<target)
                low=mid+1;
            else
                high=mid-1;
            if(abs_diff>abs(sum-target)||(abs_diff==abs(sum-target) && mid<res))
            {
                res=mid;
                abs_diff=abs(sum-target);
            }
        }
        return res;
    }
};