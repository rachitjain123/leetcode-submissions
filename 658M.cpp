class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low=0,high=arr.size()-1;
        int ans=arr.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]>=x)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        int left=ans-k,right=ans+k;
        if(left<0)
            left=0;
        if(right>=arr.size())
            right=arr.size()-1;
        while(left<=right)
        {
            if(right-left+1==k)
                break;
            if(abs(arr[right]-x)>=abs(arr[left]-x))
                right--;
            else
                left++;
        }
        int ind=0;
        for(int i=left;i<=right;i++)
            arr[ind++]=arr[i];
        if(arr.size()==k)
            return arr;
        arr.erase(arr.begin()+k,arr.begin()+arr.size());
        return arr;
    }
};