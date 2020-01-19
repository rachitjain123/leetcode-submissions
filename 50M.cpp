class Solution {
public:
    double myPow(double x, int n) {
        double res=1;
        int sign=0;
        long long int N=(long long int)n;
        if(n<0)
        {
            sign=1;
            N = N * -1;
        }
        while(N>0)
        {
            if(N%2)
                res=res*x;
            x=x*x;
            N/=2;
        }
        if(sign)
            res=1/res;
        return res;
    }
};