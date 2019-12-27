class Solution {
void init(vector<int> &root,vector<int> &size,int len)
{
    for(int i=0;i<len;i++)
    {
        root[i]=i;
        size[i]=1;
    }
}
int getRoot(vector<int> &root,int node)
{
    while(root[node]!=node)
    {
        root[node]=root[root[node]];
        node=root[node];
    }
    return node;
}
void unite(vector<int> &root,vector<int> &size,int a,int b)
{
    int r1=getRoot(root,a);
    int r2=getRoot(root,b);
    if(size[r1]<size[r2])
    {
        root[r1]=root[r2];
        size[r2]+=size[r1];
    }
    else
    {
        root[r2]=root[r1];
        size[r1]+=size[r2];
    }
}
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int>root(s.length());
        vector<int>size(s.length());
        vector<int>mapping[s.length()];
        init(root,size,s.length());
        for(int i=0;i<pairs.size();i++)
        {
            int ind1=pairs[i][0];
            int ind2=pairs[i][1];
            if(getRoot(root,ind1)!=getRoot(root,ind2))
                unite(root,size,ind1,ind2);
        }
        for(int i=0;i<s.length();i++)
            mapping[getRoot(root,i)].push_back(i);
        for(int i=0;i<s.length();i++)
        {
            string str;
            for(int j=0;j<mapping[i].size();j++)
                str+=s[mapping[i][j]];
            sort(str.begin(),str.end());
            for(int j=0;j<mapping[i].size();j++)
                s[mapping[i][j]]=str[j];
        }
        return s;        
    }
};