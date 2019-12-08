class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) 
    {
        sort(A.begin(),A.end());
        vector<pair<int,int> >modB;
        for(int i=0;i<B.size();i++)
        	modB.push_back({B[i],i});
        sort(modB.begin(),modB.end());
        int ix=0,ind=0;
        vector<int>perm(B.size(),-1);
        vector<int>bigNos;
        while(ix<A.size())
        {
        	if(A[ix]>modB[ind].first)
        	{
        		perm[modB[ind].second]=A[ix];
        		ix++;
        		ind++;
        	}
        	else
        	{
        		bigNos.push_back(A[ix]);
        		ix++;
        	}
        }
        for(int i=0;i<perm.size();i++)
        {
        	if(perm[i]==-1)
        	{
        		perm[i]=bigNos.back();
        		bigNos.pop_back();
        	}
        }
        return perm;

    }
};