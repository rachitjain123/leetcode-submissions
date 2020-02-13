class Solution {
public:
    string removeKdigits(string num, int k) {
        string str;
        for(int i=0;i<num.size();i++)
        {
            if(str.empty())
                str.push_back(num[i]);
            else
            {
                while(!str.empty() && str.back()>num[i] && k)
                {
                    str.pop_back();
                    k--;
                }
                str.push_back(num[i]);
            }
        }
        while(k)
        {
            str.pop_back();
            k--;
        }
        int ind=0;
        while(ind<str.length())
        {
            if(str[ind]=='0')
                ind++;
            else
                break;
        }
        str=str.substr(ind);
        if(str.empty())
            return "0";
        return str;
    }
};