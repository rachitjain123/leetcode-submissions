class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> sameOrEquivalent;
        int max_rows=1;
        for(int i=0;i<matrix.size();i++)
        {
            string strSame,strEquivalent;
            for(int j=0;j<matrix[i].size();j++)
            {
                strSame.push_back(matrix[i][j]+'0');
                strEquivalent.push_back(1-matrix[i][j]+'0');
            }
            // check For same;
            if(sameOrEquivalent.find(strSame) != sameOrEquivalent.end())
            {
                sameOrEquivalent[strSame]++;
                max_rows=max(max_rows, sameOrEquivalent[strSame]);
            }
            // check for equivalent string
            else if(sameOrEquivalent.find(strEquivalent) != sameOrEquivalent.end())
            {
                sameOrEquivalent[strEquivalent]++;
                max_rows=max(max_rows, sameOrEquivalent[strEquivalent]);
            }
            else
                sameOrEquivalent[strSame]=1;
        }
        return max_rows;
    }
};