class Complex{
public:
    int real, imag; 
    Complex(int r = 0, int i =0)  {real = r;   imag = i;}
    Complex operator * (Complex const &obj) 
    { 
         Complex res; 
         res.real = real * obj.real - imag * obj.imag; 
         res.imag = imag * obj.real + real * obj.imag; 
         return res; 
    }
};
class Solution {
public:
    pair<int,int> parseString(string a)
    {
        int r1=0,i1=0,fl1=0,fl2=0;
        int ind1=0;
        while(ind1<a.length() && a[ind1]!='+')
        {
            if(a[ind1]=='-')
            {
                fl1=1;
                ind1++;
                continue;
            }
            r1=r1*10+a[ind1++]-'0';
        }
        if(fl1==1)
            r1*=-1;
        ind1++;
        while(ind1<a.length() && a[ind1]!='i')
        {
            if(a[ind1]=='-')
            {
                fl2=1;
                ind1++;
                continue;
            }
            i1=i1*10+a[ind1++]-'0';
        }
        if(fl2==1)
            i1*=-1;
        return {r1,i1};
    }
    string complexNumberMultiply(string a, string b) {
        int r1,i1,r2,i2;
        pair<int,int> p1=parseString(a);
        pair<int,int> p2=parseString(b);
        r1=p1.first;
        i1=p1.second;
        r2=p2.first;
        i2=p2.second;
        Complex c1(r1, i1), c2(r2, i2);
        Complex c3 = c1 * c2;
        string s1 = to_string(c3.real);
        string s2 = to_string(c3.imag);
        string res=s1+'+'+s2+'i';
        return res;
    }
};