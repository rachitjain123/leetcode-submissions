class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<long long int>fib;
        int ans=0;
        fib.push_back(1);fib.push_back(1);
        while(1)
        {
            int sz=fib.size();
            long long int newFib = fib[sz-1]+fib[sz-2];
            fib.push_back(newFib);
            if(fib.back()>k)
                break;
        }
        for(int i=fib.size()-1;i>=0;i--)
        {
            if(k>=fib[i])
            {
                k-=fib[i];
                ans++;
            }
        }
        return ans;
    }
};