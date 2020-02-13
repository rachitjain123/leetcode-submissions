class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string s;
        while(B>A && B>=2 && A>=1)
        {
            s=s+"bb";
            s=s+"a";
            B=B-2;
            A=A-1;
        }
        while(A>B && A>=2 && B>=1)
        {
            s=s+"aa";
            s=s+"b";
            A=A-2;
            B=B-1;
        }
        while(B>0 && A>0)
        {
            s=s+"b";
            s=s+"a";
            B--;
            A--;
        }
        while(B>0)
        {
            s=s+"b";
            B--;
        }
        while(A>0)
        {
            s=s+"a";
            A--;
        }
        return s;
    }
};