class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        vector<char>v[numRows];
        int ind=0,fl=0;
        string str;
        for(int i=0;i<s.length();i++)
        {
            v[ind].push_back(s[i]);
            if(ind==0 && fl==1)
                fl=0;
            if(ind==numRows-1 && fl==0)
                fl=1;
            if(fl==0)
                ind++;
            if(fl==1)
                ind--;
        }
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<v[i].size();j++)
                str+=v[i][j];
        }
        return str;
    }
};