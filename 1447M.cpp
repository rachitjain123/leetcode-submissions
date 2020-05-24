class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string>fractions;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(__gcd(i,j)==1)
                    fractions.push_back(to_string(i) + "/" + to_string(j));
            }
        }
        return fractions;
    }
};