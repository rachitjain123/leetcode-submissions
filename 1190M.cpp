
class Solution {
public:
    string reverseParentheses(string s) 
    {
        stack<int> test;
        string res = "";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') 
                test.push(i);
            else if(s[i]==')') 
            {
                reverse(s.begin()+test.top(),s.begin()+i);
                test.pop();
            }
        }
        for(auto resStr:s)
            if(resStr!='(' && resStr!=')') 
                res+= resStr;
        return res;
    }
};