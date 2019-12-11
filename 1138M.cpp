class Solution {
public:
	string alphabetBoardPath(string target) 
	{
		map<char,pair<int,int> >mp;
		mp['a']={1,1};mp['b']={1,2};mp['c']={1,3};mp['d']={1,4};mp['e']={1,5};mp['f']={2,1};mp['g']={2,2};mp['h']={2,3};mp['i']={2,4};mp['j']={2,5};mp['k']={3,1};mp['l']={3,2};mp['m']={3,3};mp['n']={3,4};mp['o']={3,5};mp['p']={4,1};mp['q']={4,2};mp['r']={4,3};mp['s']={4,4};mp['t']={4,5};mp['u']={5,1};mp['v']={5,2};mp['w']={5,3};mp['x']={5,4};mp['y']={5,5};mp['z']={6,1};
		pair<int,int>start={1,1};
		string moves;
		for(int i=0;i<target.size();i++)
		{
			int x=start.first;
			int y=start.second;

			int tx=mp[target[i]].first;
			int ty=mp[target[i]].second;

			if(i!=0 && target[i-1]=='z')
			{

				while(x<tx)
				{
					moves+='D';
					x++;
				}
				while(x>tx)
				{
					moves+='U';
					x--;
				}
				while(y>ty)
				{
					moves+='L';
					y--;
				}
				while(y<ty)
				{
					moves+='R';
					y++;
				}
			}
			else
			{
				while(y>ty)
				{
					moves+='L';
					y--;
				}
				while(y<ty)
				{
					moves+='R';
					y++;
				}
				while(x<tx)
				{
					moves+='D';
					x++;
				}
				while(x>tx)
				{
					moves+='U';
					x--;
				}
			}
			moves+='!';
			start=mp[target[i]];
		}
		return moves;
	}
};