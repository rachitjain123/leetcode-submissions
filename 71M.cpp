class Solution {
public:
    string simplifyPath(string path) {
        vector<string>v;
        for(int i=0;i<path.length();i++)
        {
            int j=i;string tmp;
            while(j<path.length() && path[j]!='/')
            {
                tmp+=path[j];
                j++;
            }
            if(tmp!="." && tmp!=".." && !tmp.empty())
                v.push_back(tmp);
            else if(tmp==".." && !v.empty())
                v.pop_back();
            i=max(i,j-1);
        }
        string fans="/";
        for(int i=0;i<v.size();i++)
        {
            if(i==v.size()-1)
                fans+=v[i];
            else
                fans+=v[i]+"/";
        }
        return fans;
    }
};