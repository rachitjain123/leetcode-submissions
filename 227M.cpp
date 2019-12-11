
class Solution {
public:
    int calculate(string s) 
    {
        char previous_operator='+';
        s=s+"+";
        long long int num=0;
        stack<int>st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='0' && s[i]<='9')
                num=num*10+s[i]-'0';
            else if(s[i]==' ')
                continue;
            else
            {
                if(previous_operator=='+')
                    st.push(num);
                else if(previous_operator=='-')
                    st.push(-num);
                else if(previous_operator=='*')
                {
                    int val=st.top();
                    st.pop();
                    st.push(num*val);
                }
                else if(previous_operator=='/')
                {
                    int val=st.top();
                    st.pop();
                    st.push(val/num);
                }
                num=0;
                previous_operator=s[i];
            }
        }
        int ans=0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};