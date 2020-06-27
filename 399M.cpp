class DSU 
{
	unordered_map<string,string> fatherMap;
	unordered_map<string,string> sizeMap;
	unordered_map<string,string> factorMap;

	DSU(vector<vector<string>>& equations)
	{
		for(int i=0;i<equations.size();i++)
		{
			fatherMap[equations[i][0]] = equations[i][0];
			fatherMap[equations[i][1]] = equations[i][1];

			sizeMap[equations[i][0]] = 1;
			sizeMap[equations[i][1]] = 1;

		}	
	}
};
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
    }
};