class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int maxi=0,sum=0;
        for(int i=0;i<k;i++)
            maxi+=customers[i];
        int precur=maxi;
        for(int i=k;i<customers.size();i++)
        {
            if(!grumpy[i])
            {
                maxi+=customers[i];
                sum+=customers[i];
            }
        }
        int i=1,j=k;
        while(j<customers.size())
        {
            int cur=precur;
            if(grumpy[i-1])
                cur=cur-customers[i-1];
            cur=cur+customers[j];
            if(grumpy[j]==0)
                sum=sum-customers[j];
            if(cur+sum>maxi)
                maxi=cur+sum;
            i++;
            j++;
            precur=cur;
        }
        return maxi;
    }
};