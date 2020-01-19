class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int ans;
        set<pair<int,pair<int,int> > >st;
        for(int i=0;i<matrix.size();i++)
            st.insert({matrix[0][i],{0,i}});
        while(k--)
        {
            pair<int,pair<int,int> >p1=*st.begin();
            ans=p1.first;
            int row=p1.second.first;
            int col=p1.second.second;
            st.erase(st.begin());
            if(row<matrix.size()-1)
                st.insert({matrix[row+1][col],{row+1,col}});
        }
        return ans;
    }
};