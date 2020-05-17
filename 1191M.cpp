class Solution {
    int getMaxSum(vector<int> &arr)
    {
        long long int max_sum=0,cur_sum=0;
        for(int i=0;i<arr.size();i++)
        {
            cur_sum+=arr[i];
            if(cur_sum<0)
                cur_sum=0;
           if(max_sum<cur_sum)
                max_sum=cur_sum;
        }
        return max_sum;
    }
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long int max_sum=0,sum=0,mod=(long long int)(1e9+7);
        for(int i=0;i<arr.size();i++)
            sum+=arr[i];
        max_sum=getMaxSum(arr);
        int ind=0,len=arr.size();
        while(ind<len)
            arr.push_back(arr[ind++]);
        if(k==1)
            return max_sum;
        if(sum<0)
            max_sum=getMaxSum(arr);
        else
            max_sum=getMaxSum(arr)+(k-2)*sum;
        return max_sum%mod;
    }
};