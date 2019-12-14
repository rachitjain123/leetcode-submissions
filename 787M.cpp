#include <bits/stdc++.h>
#define  pb push_back
#define nl "\n"
#define fastScan ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
{
	set<pair<pair<int,int>,int> >st;
	vector<int>dist(105);
	vector<pair<int,int> >adj[105];
	for(int i=1;i<=n;i++)
	{
		dist[i]=INT_MAX;
		int u=flights[i-1][0];
		int v=flights[i-1][1];
		int w=flights[i-1][2];
		adj[u].push_back({v,w});
	}
	dist[src]=0;
	st.insert({{0,src},-1});
	while(!st.empty())
	{
		int u=*st.begin().first.second;
		int min_cst=*st.begin().first.first;
		int stops=*st.begin().second;
		st.erase(st.begin());
		if(u==dst)
			return min_cst;
		if(stops>=k)
			continue;
		for(int i=0;i<adj[u].size();i++)
		{
			int v=adj[u][i].first;
			int w=adj[u][i].first.second;
			int stops=adj[u][i].second;
			if(stops>=k)
				continue;
			if(dist[u]+w<dist[v])
			{
				dist[v]=dist[u]+w;
				st.insert({{dist[v],v},stops+1});
			}
		}
	}
	return -1;
}
int main()
{
	fastScan;
	
}
