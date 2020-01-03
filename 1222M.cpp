class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<bool> >is_present(8,vector<bool>(8,false));
        for(int i=0;i<queens.size();i++)
            is_present[queens[i][0]][queens[i][1]]=true;
        int x=king[0];
        int y=king[1];
        vector<vector<int> >coord;
        for(int i=x-1;i>=0;i--)
        {
            if(is_present[i][y])
            {
                vector<int>tmp;
                tmp.push_back(i);
                tmp.push_back(y);
                coord.push_back(tmp);
                break;
            }
        }
        for(int i=x+1;i<8;i++)
        {
            if(is_present[i][y])
            {
                vector<int>tmp;
                tmp.push_back(i);
                tmp.push_back(y);
                coord.push_back(tmp);
                break;
            }
        }
        for(int j=y-1;j>=0;j--)
        {
            if(is_present[x][j])
            {
                vector<int>tmp;
                tmp.push_back(x);
                tmp.push_back(j);
                coord.push_back(tmp);
                break;
            }
        }
        for(int j=y+1;j<8;j++)
        {
            if(is_present[x][j])
            {
                vector<int>tmp;
                tmp.push_back(x);
                tmp.push_back(j);
                coord.push_back(tmp);
                break;
            }
        }
        int i=x-1,j=y-1;
        while(i>=0 && j>=0)
        {
            if(is_present[i][j])
            {
                vector<int>tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                coord.push_back(tmp);
                break;
            }
            i--;
            j--;
        }
        i=x-1,j=y+1;
        while(i>=0 && j<8)
        {
            if(is_present[i][j])
            {
                vector<int>tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                coord.push_back(tmp);
                break;
            }
            i--;
            j++;
        }
        
        i=x+1,j=y-1;
        while(i<8 && j>=0)
        {
            if(is_present[i][j])
            {
                vector<int>tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                coord.push_back(tmp);
                break;
            }
            i++;
            j--;
        }
        
        i=x+1,j=y+1;
        while(i<8 && j<8)
        {
            if(is_present[i][j])
            {
                vector<int>tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                coord.push_back(tmp);
                break;
            }
            i++;
            j++;
        }
        return coord;
    }
};