class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int> >st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                st.push({s[i],i});
            else if(s[i]==')')
            {
                if(st.empty())
                    s[i]='*';
                else
                    st.pop();
            }
        }
        while(!st.empty())
        {
            s[st.top().second]='*';
            st.pop();
        }
        string resultant_str;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='*')
                resultant_str+=s[i];
        }
        return resultant_str;
    }
};