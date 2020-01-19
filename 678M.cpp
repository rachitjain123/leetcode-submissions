class Solution {
public:
    bool checkValidString(string s) {
        stack<char>stars,brack;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='*')
                stars.push(i);
            else if(s[i]=='(')
                brack.push(i);
            else
            {
                if(stars.empty() && brack.empty())
                    return false;
                if(brack.empty())
                    stars.pop();
                else
                    brack.pop();
            }
        }
        while(!brack.empty())
        {
            if(stars.empty())
                return false;
            if(stars.top()>brack.top())
            {
                stars.pop();
                brack.pop();
            }
            else
                return false;
        }
        return true;
    }
};