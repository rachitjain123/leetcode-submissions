class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum=0,num_subarrays=0,num_elements=0;
        for(int i=0;i<arr.size();i++)  
        {
            if(i>=k) sum-=arr[i-k];
            sum+=arr[i];
            num_elements++;
            if(num_elements>=k && sum>=k*threshold) num_subarrays++;
        }
        return num_subarrays;
    }
};