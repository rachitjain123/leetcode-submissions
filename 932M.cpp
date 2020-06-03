class Solution {
    unordered_map<int,vector<int> > beautifulPermutation;
public:
    vector<int> beautifulArray(int N) {
        if(beautifulPermutation.find(N)!=beautifulPermutation.end())
            return beautifulPermutation[N];
        if(N==1)
            return {1};
        vector<int> evenPerm = beautifulArray(N/2);
        vector<int> oddPerm = beautifulArray(N - N/2);
        for(auto elem: evenPerm)
            beautifulPermutation[N].push_back(elem*2);
        for(auto elem: oddPerm)
            beautifulPermutation[N].push_back(elem*2-1);
        return beautifulPermutation[N];
    }
};