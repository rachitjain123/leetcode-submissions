class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        set<int>st;
        vector<int>tmp(10000);
        for(int i=A.size()-1;i>=0;i--)
        {
            auto it=st.lower_bound(A[i]);
            tmp[A[i]]=i;
            if(st.empty() || *st.begin()>=A[i])
            {
                st.insert(A[i]);
                continue;
            }
            it--;
            int ind1=tmp[*it];
            int ind2=i;
            swap(A[ind1],A[ind2]);
            break;
        }
        return A;
    }
};