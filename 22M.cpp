class Solution {
    void generate(int open, int close, int len, string str,vector<string> &parenthesis)
    {
        if(close>open)
            return;
        if(str.length()==len)
        {
            parenthesis.push_back(str);
            return;
        }
        if(open==close)
            generate(open+1,close,len,str + "(",parenthesis);
        else
        {
            if(open<len/2)
                generate(open+1,close,len,str+"(",parenthesis);
            if(close<len/2)
                generate(open,close+1,len,str+")",parenthesis);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> parenthesis;
        generate(0,0,n*2,"",parenthesis);
        return parenthesis;
    }
};