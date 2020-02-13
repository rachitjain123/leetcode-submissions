class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1,points=0;
        while(i<=j)
        {
            if(tokens[i]<=P)
            {
                P-=tokens[i];
                points++;
                i++;
            }
            else if(points>0 && i<j)
            {
                P+=tokens[j];
                j--;
                points--;
            }
            else
                break;
        }
        return points;
    }
};