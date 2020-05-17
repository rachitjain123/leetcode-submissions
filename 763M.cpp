class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> max_pos(26);
        vector<int>parts;
        int maxId=1,len=1;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(!max_pos[s[i]-'a'])
                max_pos[s[i]-'a']=i+1;
        }
        for(int i=0;i<s.length();i++)
        {
            maxId=max(maxId,max_pos[s[i]-'a']);
            if(maxId>i+1)
                len++;
            else
            {
                parts.push_back(len);
                len=1;
            }
        }
        return parts;
    }
};