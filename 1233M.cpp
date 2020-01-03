class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_map<string,bool>mp;
        vector<string>v;
        sort(folder.begin(),folder.end());
        for(int i=0;i<folder.size();i++)
        {
            string str="/";
            int fl=0,j=1;
            while(true)
            {
                while(j<folder[i].length() && folder[i][j]!='/')
                    str+=folder[i][j++];
                if(mp[str])
                {
                    fl=1;
                    break;
                }
                if(j>=folder[i].length())
                    break;
                str+=folder[i][j++];
            }
            if(!fl)
            {
                v.push_back(folder[i]);
                mp[folder[i]]=true;
            }
        }
        return v;
    }
};