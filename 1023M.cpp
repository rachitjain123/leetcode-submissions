class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) 
    {
        vector<bool>matching;
        for(int i=0;i<queries.size();i++)
        {
            int index=0;
            int fl=1;
            for(int j=0;j<queries[i].length();j++)
            {
                if(queries[i][j]>='A' && queries[i][j]<='Z')
                {
                    if(index<pattern.length() && pattern[index]==queries[i][j])
                        index++;
                    else
                    {
                        fl=0;
                        break;
                    }
                }
                else if(index<pattern.length() && queries[i][j]==pattern[index])
                    index++;
            }
            if(fl && index==pattern.length())
                matching.push_back(true);
            else
                matching.push_back(false);
        }
        return matching;
    }
};