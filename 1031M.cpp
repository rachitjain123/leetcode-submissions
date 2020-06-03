class Solution {
    int getMaxSum(vector<int> &A, int L, int M)
    {
        int sum=0;
        vector<int>prefFront;
        for(int i=0;i<L;i++) 
        {
            sum+=A[i];
            prefFront.push_back(sum);
        }
        for(int i=L;i<A.size();i++)
        {
            sum=sum-A[i-L]+A[i];
            int curMax=max(prefFront[prefFront.size()-1],sum);
            prefFront.push_back(curMax);
        }
        sum=0;
        for(int i=A.size()-1;i>=A.size()-M;i--) sum+=A[i];
        int maxTotal=sum+prefFront[A.size()-1-M];
        for(int i=A.size()-M-1;i>=L;i--)
        {
            sum=sum+A[i]-A[i+M];
            maxTotal=max(maxTotal, sum+prefFront[i-1]);
        }
        return maxTotal;
    }
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        return max(getMaxSum(A,L,M), getMaxSum(A,M,L));
    }
};