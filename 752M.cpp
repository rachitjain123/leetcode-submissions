class Solution {
public:
    int openLock(vector<string>& deadends, string target) 
    {
        string src="0000";
        queue<pair<string,int> >q;
        q.push({src,0});
        set<string>vis_set;
        set<string>deadends_set;
        for(auto x:deadends)
            deadends_set.insert(x);
        int min_moves=-1;
        if(deadends_set.find(src)!=deadends_set.end())
            return min_moves;
        while(!q.empty())
        {
            string str=q.front().first;
            int level=q.front().second;
            if(str==target)
            {
                min_moves=level;
                break;
            }
            q.pop();
            string prestr=str;
            for(int i=0;i<str.length();i++)
            {
                str=prestr;
                int numval=str[i]-'0';
                int possible1,possible2;
                if(numval==0)
                {
                    possible1=9;
                    possible2=1;
                }
                else if(numval==9)
                {
                    possible1=8;
                    possible2=0;
                }
                else
                {
                    possible1=numval-1;
                    possible2=numval+1;
                }
                str[i]=possible1+'0';
                if(vis_set.find(str)==vis_set.end() && deadends_set.find(str)==deadends_set.end())
                {
                    q.push({str,level+1});
                    vis_set.insert(str);
                }
                str[i]=possible2+'0';
                if(vis_set.find(str)==vis_set.end() && deadends_set.find(str)==deadends_set.end())
                {
                    q.push({str,level+1});
                    vis_set.insert(str);
                }
            }
        }
        return min_moves;
    }
};