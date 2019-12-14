class Solution {
public:
    string decodeString(string s) 
    {
        int num=0;
        string str="";
        stack<int>stNum;
        stack<string>stString;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='0' && s[i]<='9')
                num=num*10+s[i]-'0';
            else if(s[i]=='[')
            {
                stString.push(str);
                stNum.push(num);
                num=0;
                str="";
            }
            else if(s[i]==']')
            {
                int numVal=stNum.top();
                stNum.pop();
                string tmp="";
                for(int i=0;i<numVal;i++)
                    tmp+=str;
                str=tmp;
                str=stString.top()+str;
                stString.pop();
            }
            else
                str+=s[i];
        }
        return str;
    }
};