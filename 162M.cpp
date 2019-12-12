class Solution {
public:
    int findPeakElement(vector<int>& arr) 
    {
        int low=0,high=arr.size()-1,ans;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if((mid==low||arr[mid-1]<=arr[mid]) && (mid==high||arr[mid+1]<=arr[mid]))
            {
                ans=mid;
                break;
            }
            if(mid>low && arr[mid]<arr[mid-1])
                high=mid-1;
            else 
                low=mid+1;
        }
        return ans;
    }
};