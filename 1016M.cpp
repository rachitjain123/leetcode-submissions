class Solution {
public:
    bool queryString(string S, int N) 
    {
        if(N>(int)1e6)
            return false;
        unordered_set<int>st;
        for(int i=0;i<S.length();i++)
        {
            long long int ans=0;
            for(int j=i;j<S.length();j++)
            {
                if(S[j]=='1')
                    ans=ans*2+1;
                else
                    ans=ans*2;
                if(ans>N)
                    break;
                if(ans<=N && ans!=0)
                    st.insert(ans);
            }
        }
        if(st.size()==N)
            return true;
        return false;
    }
};