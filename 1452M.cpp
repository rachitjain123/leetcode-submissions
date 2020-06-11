class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        for(int i=0;i<favoriteCompanies.size();i++)
            sort(favoriteCompanies[i].begin(),favoriteCompanies[i].end());
        vector<int> res;
        for(int i=0;i<favoriteCompanies.size();i++)
        {
            bool isSubset = false;
            for(int j=0;j<favoriteCompanies.size();j++)
            {
                if(i==j)
                    continue;
                if(includes(favoriteCompanies[j].begin(),favoriteCompanies[j].end(), favoriteCompanies[i].begin(), favoriteCompanies[i].end()))
                {
                    isSubset=true;
                    break;
                }
            }
            if(!isSubset)
                res.push_back(i);
        }
        return res;
    }
};