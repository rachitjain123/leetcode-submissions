class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int>p(m);
        vector<int>res;
        for(int i=0;i<m;i++)
            p[i]=i+1;
         for(int i=0;i<queries.size();i++){
             int idx;
             for(int j=0;j<m;j++){
                 if(p[j] ==queries[i]){
                     idx=j;
                     break;
                 }
             }
             res.push_back(idx);
                 for(int j=idx;j>0;j--){
                     p[j]=p[j-1];
                 }
                 p[0] =queries[i];
         }
        return res;
    }
};