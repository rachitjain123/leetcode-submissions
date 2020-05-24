class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while(a!=0 || b!=0 || c!=0) 
        {
            int b1 = a%2;
            int b2 = b%2;
            int b3 = c%2;
            a/=2;b/=2;c/=2;
            
            if((int)(b1|b2) == b3)
                continue;
            else if(b1==1 && b2==1)
                flips+=2;
            else
                flips++;
        }
        return flips;
    }
};