class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int>is_present(10001,1);
        vector<int>v;
        v.push_back(1);
        is_present[1]=0;
        int ind=0;
        int fl=0;
        while(k!=0)
        {
            if(fl==0)
            {
                v.push_back(v[ind]+k);
                is_present[v[ind]+k]=0;
            }
            else
            {
                v.push_back(v[ind]-k);
                is_present[v[ind]-k]=0;
            }
            ind++;
            k--;
            fl=1-fl;
        }
        for(int i=2;i<=n;i++)
        {
            if(is_present[i]==1)
                v.push_back(i);
        }
        return v;
    }
};