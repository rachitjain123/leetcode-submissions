class Solution {
    int num_perm;
    void permute(vector<int> &num,int l,int r)
    {
        if(l==r)
        {
            if(num[l]%(l+1)==0 || (l+1)%num[l]==0)
                num_perm++;
        }
        for(int i=l;i<=r;i++)
        {
            swap(num[i],num[l]);
            if(num[l]%(l+1)==0 || (l+1)%num[l]==0)
                permute(num,l+1,r);
            swap(num[i],num[l]);
        }
    }
public:
    int countArrangement(int N) {
        vector<int>num(N);
        num_perm=0;
        for(int i=0;i<N;i++)
            num[i]=i+1;
        permute(num,0,N-1);
        return num_perm;
    }
};