class Solution {
	int size[1005];
	int s[1005];     
	void init(int n)
	{
		for(int i=0;i<=n;i++)
		{
			s[i]=i;
			size[i]=1;
		}
	}
	int getRoot(int i)
	{   
		while(s[i]!=i)
		{   
			s[i]=s[s[i]];
			i=s[i];
		}
		return i;
	}
	void unite(int a,int b)
	{
		int r1=getRoot(a);
		int r2=getRoot(b);
		if(size[r1]<=size[r2])
		{
			s[r1]=s[r2];
			size[r2]+=size[r1];
		}
		else
		{
			s[r2]=s[r1];
			size[r1]+=size[r2];
		}
	}
public:
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
	{
		map<string,vector<int> > mp;
		vector<vector<string>> ans;
		init(accounts.size());
		for(int i=0;i<accounts.size();i++)
		{
			for(int j=1;j<accounts[i].size();j++)
				mp[accounts[i][j]].push_back(i);
		}
		for(auto x:mp)
		{
			int i1=x.second[0];
			for(int i=1;i<x.second.size();i++)
			{
				int i2=x.second[i];
				if(getRoot(i1)!=getRoot(i2))
					unite(i1,i2);
			}
		}
		
		for(int i=0;i<accounts.size();i++)
		{
			int val=getRoot(i);
			if(val!=i)
			{
				int id=val;
				for(int j=0;j<accounts[i].size();j++)
					accounts[id].push_back(accounts[i][j]);
				accounts[i].clear();
			}
		}
		for(int i=0;i<accounts.size();i++)
		{
			if(accounts[i].empty())
				continue;
			set<string>str;
			vector<string>tmp;
			tmp.push_back(accounts[i][0]);
			for(int j=0;j<accounts[i].size();j++)
				str.insert(accounts[i][j]);
			if(str.find(accounts[i][0])!=str.end())
				str.erase(accounts[i][0]);
			for(auto x:str)
				tmp.push_back(x);
			ans.push_back(tmp);
		}
		return ans;
	}
};