class Solution {
    bool checkValidNos(string str)
    {
        if(str.length()>1 && str[0]=='0')
            return false;
        return true;
    }
    bool checkValidDecimal(string str)
    {
        if(str[0]=='.' || str[str.length()-1]=='.'||str[str.length()-1]=='0')
            return false;
        if(str[0]=='0' && str[1]!='.')
            return false;
        int fl=0;
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='.')
                fl=1;
            else if(fl==1 && str[i]!='0')
                return true;
        }
        return false;
    }
public:
    vector<string> ambiguousCoordinates(string S) 
    {
        string str1,str2;
        vector<string>corrdinates;
        for(int i=1;i<S.length()-2;i++)
        {
            str1+=S[i];
            str2="";
            for(int j=i+1;j<S.length()-1;j++)
                str2+=S[j];
            if(checkValidNos(str1) && checkValidNos(str2))
            {
                string coord='('+str1+", "+str2+')';
                corrdinates.push_back(coord);
            }
            vector<string>x,y;
            if(checkValidNos(str1))
                x.push_back(str1);
            if(checkValidNos(str2))
                y.push_back(str2);
            for(int k=0;k<str1.size();k++)
            {
                string newstr1=str1;
                newstr1.insert(k,".");
                if(checkValidDecimal(newstr1))
                    x.push_back(newstr1);
            }
            for(int l=0;l<str2.size();l++)
            {
                string newstr2=str2;
                newstr2.insert(l,".");
                if(checkValidDecimal(newstr2))
                    y.push_back(newstr2);
            }
            for(auto string1:x)
            {	
                for(auto string2:y)
                {
                    if(string1==str1 && string2==str2)
                        continue;
                    string coord='('+string1+", "+string2+')';
                    corrdinates.push_back(coord);
                }
            }
        }
        return corrdinates;
    }
};