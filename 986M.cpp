class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int l=0,r=0;
        vector<vector<int> > intersection;
        while(l<A.size() && r<B.size())
        {
            if(A[l][0]>=B[r][0] && A[l][0]<=B[r][1])
            {
                vector<int>section;
                section.push_back(A[l][0]);
                section.push_back(min(A[l][1],B[r][1]));
                intersection.push_back(section);
                

            }
            else if(B[r][0]>=A[l][0] && B[r][0]<=A[l][1])
            {
                vector<int>section;
                section.push_back(B[r][0]);
                section.push_back(min(A[l][1],B[r][1]));
                intersection.push_back(section);
            }

            if(A[l][1]>B[r][1])
                r++;
            else
                l++;
        }
        
        return intersection;
    }
};