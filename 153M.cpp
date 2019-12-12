class Solution {
public:
    // Recursive
    // int getMin(vector<int> &arr,int low,int high)
    // {
    //     if(low>high)
    //         return arr[0];
    //     int mid=(low+high)/2;
    //     if(mid>low && arr[mid]<arr[mid-1])
    //         return arr[mid];
    //     if(mid<high && arr[mid]>arr[mid+1])
    //         return arr[mid+1];
    //     if(arr[mid]>=arr[low])
    //         return getMin(arr,mid+1,high);
    //     return getMin(arr,low,mid-1);
    // }
    // int findMin(vector<int>& nums) {
    //     return getMin(nums,0,nums.size()-1);
    // }
    // Iterative
    int findMin(vector<int>& arr) {
        int low=0,high=arr.size()-1;
        while(1)
        {
            if(low>high)
                return arr[0];
            int mid=(low+high)/2;
            if(mid>low && arr[mid]<arr[mid-1])
                return arr[mid];
            if(mid<high && arr[mid]>arr[mid+1])
                return arr[mid+1];
            if(arr[mid]>=arr[low])
                low=mid+1;
            else
                high=mid-1;
        }
    }
};